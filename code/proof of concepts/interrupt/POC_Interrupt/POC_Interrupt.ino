int ledRun=13;
int buttonInterrupt=2;

bool ledStatus = false;

void setup(){
  pinMode(ledRun,OUTPUT);
  pinMode(buttonInterrupt,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonInterrupt), interrupt, FALLING);
}

void loop (){
   digitalWrite(ledRun,ledStatus);
}

void interrupt()
{

    ledStatus = !ledStatus;
}
