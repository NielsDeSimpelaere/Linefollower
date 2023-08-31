#define MotorRightForward 5
#define MotorRightBackward 3
#define MotorLeftForward 9
#define MotorLeftBackward 6

void setup() {

  Serial.begin(115200);
  
  pinMode(MotorLeftForward,OUTPUT);
  pinMode(MotorLeftBackward,OUTPUT);
  pinMode(MotorRightForward,OUTPUT);
  pinMode(MotorRightBackward,OUTPUT);
}

void loop() {
motorstop();
delay(500);
analogWrite(MotorLeftForward,50); // Linker motor vooruit laten draaien aan vaste snelheid
delay(3000);
motorstop();
delay(500);

analogWrite(MotorRightForward,50); // Rechtse motor vooruit laten draaien aan vaste snelheid
delay(3000);
motorstop();
delay(500);
///////////////////////////////
analogWrite(MotorLeftBackward,50); // Linker motor achteruit laten draaien aan vaste snelheid
delay(3000);
motorstop();
delay(500);

analogWrite(MotorRightBackward,50); // Rechtse motor achteruit laten draaien aan vaste snelheid
delay(3000);
motorstop();
delay(500);
/////////////////////////////////////////////////////////////
motorversnelt(MotorLeftForward); // Linker motor vooruit laten draaien aan vaste snelheid
motorstop();
delay(500);

motorversnelt(MotorRightForward); // Rechtse motor vooruit laten draaien aan vaste snelheid
motorstop();
delay(500);
//////////////////////////////
motorversnelt(MotorLeftBackward); // Linker motor achteruit laten draaien aan vaste snelheid
motorstop();
delay(500);

motorversnelt(MotorRightBackward); // Rechtse motor achteruit laten draaien aan vaste snelheid
motorstop();
delay(500);
}

void motorstop(){
analogWrite(MotorLeftForward, 0);
analogWrite(MotorLeftBackward, 0);
analogWrite(MotorRightForward, 0);
analogWrite(MotorRightBackward, 0);
}

void motorversnelt(int uit){
  for (int i=0; i<255; i++){
      analogWrite(uit,i);
      delay(100);
  }
}
