
const int sensor[] = {A7, A6, A5, A4, A3, A2, A1, A0};
int Sensorwaarde[8];

void setup() {
  
Serial.begin(115200);
}

void loop() {
  
  Serial.print("waarde sensoren: ");
    for (int i = 0; i < 8; i++)
    {
      Sensorwaarde[i] = analogRead(sensor[i]);
      Serial.print(Sensorwaarde[i]);
      Serial.print(" ");
    }
    
   Serial.println();
   delay(500);
}
