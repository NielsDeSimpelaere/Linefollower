int ledRun = 13;
char ReadSerial = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledRun, OUTPUT);
}
void loop()
{
  if (Serial.available() > 0)
  {
    ReadSerial = Serial.read();
    Serial.println(ReadSerial);
    if (ReadSerial == '0')
    {
      digitalWrite(ledRun, LOW);
      Serial.println("LED UIT");
    }
    else if (ReadSerial == '1')
    {
      digitalWrite(ledRun, HIGH);
      Serial.println("LED AAN");
    }
   
  }
}
