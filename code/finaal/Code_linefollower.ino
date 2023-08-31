#include "SerialCommand.h"
#include "EEPROMAnything.h"


#define SerialPort Serial
#define Baudrate 115200

SerialCommand sCmd(SerialPort);
bool debug;
bool run = 0;
bool calibrate; //
unsigned long previous, calculationTime;

const int sensor[] = {A7, A6, A5, A4, A3, A2, A1, A0};
int Sensorwaarde[8]; //

#define MotorRightForward 9 //3
#define MotorRightBackward 6 //5
#define MotorLeftForward 5 //6
#define MotorLeftBackward 3 //9
#define buttonInterrupt 2
#define ledRun 13
#define ledPower 12


struct param_t
{
  unsigned long cycleTime;
  int black[8];
  int white[8];
  int power;
  float diff;
  float kp;
  float ki;
  float kd;
  float iTerm;
  /* andere parameters die in het eeprom geheugen moeten opgeslagen worden voeg je hier toe ... */
} params;
int normalised[8];
float debugPosition;

void onUnknownCommand(char*command);
void onSet();
void onDebug();
void onCalibrate();
void onRun();

void setup()
{
  SerialPort.begin(Baudrate);

  sCmd.addCommand("set", onSet);
  sCmd.addCommand("debug", onDebug);
  sCmd.addCommand("calibrate", onCalibrate);
  sCmd.addCommand("run", onRun);
  sCmd.setDefaultHandler(onUnknownCommand);

  EEPROM_readAnything(0, params);

  pinMode(ledRun, OUTPUT);
  pinMode(ledPower, OUTPUT);
  pinMode(buttonInterrupt, INPUT_PULLUP);  //
  digitalWrite(ledPower, HIGH);
  attachInterrupt(digitalPinToInterrupt(buttonInterrupt), onRun, FALLING);
  
  SerialPort.println("ready");
  
  pinMode(MotorLeftForward,OUTPUT);  // 
  pinMode(MotorLeftBackward,OUTPUT);  //
  pinMode(MotorRightForward,OUTPUT);  //
  pinMode(MotorRightBackward,OUTPUT);  //
}

void loop()
{
  sCmd.readSerial();
   
  unsigned long current = micros();
  if (current - previous >= params.cycleTime)
  {
    previous = current;

    int normalised[8];
    /* code die cyclisch moet uitgevoerd worden programmeer je hier ... */

    /* normaliseren en interpoleren sensor */

    Serial/*Port*/.print("normalised values: ");
    for (int i = 0; i < 8; i++)
    {
      normalised[i] = map(analogRead(sensor[i]), params.black[i], params.white[i],0 , 1000);
      Serial/*Port*/.print(normalised[i]);
      Serial/*Port*/.print(" ");
      
    }
    Serial/*Port¨*/.println();

    int index = 0;
    for (int i = 1; i < 8; i++) if (normalised[i] < normalised[index]) index = i;

    // if (normalised[index] < 200) run = false;
    float position;
    if (index == 0) position = -29;
    else if (index == 7) position = 29;
    else
    {
      int sNul = normalised[index];
      int sMinEen = normalised[index-1];
      int sPlusEen = normalised[index+1];

      float b = sPlusEen - sMinEen;
      b = b / 2;

      float a = sPlusEen - b - sNul;

      position = -b / (2 * a);
      position += index;
      position -= 3.493;

      position *= 9.525;
    }
    debugPosition = position;
    
    float error = -position;
    float output = error * params.kp;

    params.iTerm += params.ki*error;
    params.iTerm = constrain(params.iTerm, -510,510);
    output += params.iTerm;

    float lastErr;
    output += params.kd*(error - lastErr);
    lastErr = error;

    output = constrain(output, -510,510);

    int powerLeft = 0;
    int powerRight = 0;

   if(run) if (output >= 0)
  {
    powerLeft = constrain(params.power + params.diff * output, -255, 255);
    powerRight = constrain(powerLeft - output, -255, 255);
    powerLeft = powerRight + output;
  }
  else
  {
    powerRight = constrain(params.power - params.diff * output, -255, 255);
    powerLeft = constrain(powerRight + output, -255, 255);
    powerRight = powerLeft - output;
  }

  analogWrite(MotorLeftForward, powerLeft > 0 ? powerLeft : 0);
  analogWrite(MotorLeftBackward, powerLeft < 0 ? -powerLeft : 0);
  analogWrite(MotorRightForward, powerRight > 0 ? powerRight : 0);
  analogWrite(MotorRightBackward, powerRight < 0 ? -powerRight : 0);

  }

  unsigned long difference = micros() - current;
  if (difference > calculationTime) calculationTime = difference;
}

void onUnknownCommand(char *command)
{
  Serial/*Port*/.print("unknown command: \"");
  Serial/*Port*/.print(command);
  Serial/*Port*/.println("\"");
}

void onSet()
{
  char* param = sCmd.next();
  char* value = sCmd.next();  
  
  if (strcmp(param, "debug") == 0) debug = (strcmp(value, "on") == 0);
  else if (strcmp(param, "cycle") == 0)
  {
    long newCycleTime = atol(value);
    float ratio = ((float) newCycleTime) / ((float) params.cycleTime);

    params.ki *= ratio;
    params.kd /= ratio;

    params.cycleTime = newCycleTime;
    
  }
  else if (strcmp(param, "power") == 0) params.power = atol(value);
  else if (strcmp(param, "diff") == 0) params.diff = atof(value);
  else if (strcmp(param, "kp") == 0) params.kp = atof(value);
  else if (strcmp(param, "ki") == 0)
  {
    float cycleTimeInSec = ((float) params.cycleTime) / 1000000;
    params.ki = atof(value) * cycleTimeInSec;
  }
  else if (strcmp(param, "kd") == 0)
  {
    float cycleTimeInSec = ((float) params.cycleTime) / 1000000;
    params.kd = atof(value) / cycleTimeInSec;
  }
  /* parameters een nieuwe waarde geven via het set commando doe je hier ... */
  
  EEPROM_writeAnything(0, params);
}

void onDebug()
{
  Serial/*Port*/.print("cycle time: ");
  Serial/*Port*/.println(params.cycleTime);
  
  /* parameters weergeven met behulp van het debug commando doe je hier ... */
  Serial/*Port*/.print("black: ");
  for (int i = 0; i < 8; i++)
  {
    Serial/*Port*/.print(params.black[i]);
    Serial/*Port*/.print(" ");
  }
  Serial/*Port*/.println(" ");

  Serial/*Port*/.print("white: ");
  for (int i = 0; i < 8; i++)
  {
    Serial/*Port*/.print(params.white[i]);
    Serial/*Port*/.print(" ");
  }
    Serial/*Port*/.println(" ");

  Serial/*Port*/.print("normalised: ");
  for (int i = 0; i < 8; i++)
  {
    Serial/*Port*/.print(normalised[i]);
    Serial/*Port*/.print(" ");
  }
    Serial/*Port*/.println(" ");

  Serial/*Port*/.print("position: ");
  Serial/*Port*/.println(debugPosition);

  Serial/*Port*/.print("power: ");
  Serial/*Port*/.println(params.power);
  Serial/*Port*/.print("diff: ");
  Serial/*Port*/.println(params.diff);
  Serial/*Port*/.print("kp: ");
  Serial/*Port*/.println(params.kp);

  float cycleTimeInSec = ((float) params.cycleTime) / 1000000;
  float ki = params.ki / cycleTimeInSec;
  SerialPort.print("Ki: ");
  SerialPort.println(ki);

  float kd = params.kd * cycleTimeInSec;
  SerialPort.print("Kd: ");
  SerialPort.println(kd);


    Serial/*Port*/.print("calculationTime: ");
    Serial/*Port*/.println(calculationTime);
    calculationTime = 0;
}

void onCalibrate()
{
  char* param = sCmd.next();

  if (strcmp(param, "black") == 0)
  {
    SerialPort.print("start calibrating black... ");
    for(int i = 0; i < 8; i++) params.black[i]=analogRead(sensor[i]);
    SerialPort.println("done");
  }
  else if (strcmp(param, "white") == 0)
  {
    SerialPort.print("start calibrating white... ");    
    for (int i = 0; i < 8; i++) params.white[i]=analogRead(sensor[i]);  
    SerialPort.println("done");      
  }

  EEPROM_writeAnything(0, params);
}

void onRun()
{
  Serial.print("RUUNNN");
  run = !run;
  params.iTerm = 0;
  if (run == HIGH)
  {
    digitalWrite(ledRun, HIGH);
  }
  else
  {
    digitalWrite(ledRun, LOW);
  }
}
