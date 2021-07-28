#define ADC_RESOLUTION    4096  //1024
#define CTmonitor 2

float avgResult=0;
float currentInmA=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
for(int i=0;i<10;i++){
  avgResult += GetpeakTopeak(); 
  }
  avgResult = avgResult/10.00;
  currentInmA = 0.0045 * avgResult;
  Serial.println(currentInmA);
  avgResult = 0;
  delay(250);
}

int16_t GetpeakTopeak() {
  int16_t ctValueHigh = 0;
  int16_t ctValueLow = ADC_RESOLUTION;

  for (uint8_t i = 0; i < 40; i++) {
    if (analogRead(CTmonitor) > ctValueHigh)
      ctValueHigh = analogRead(CTmonitor);
    if (analogRead(CTmonitor) < ctValueLow)
      ctValueLow = analogRead(CTmonitor);
    delayMicroseconds(500);
    //delay(1);
  }
    Serial.print("High : ");  Serial.print(ctValueHigh);
    Serial.print('\t');
    Serial.print("Low : ");  Serial.println(ctValueLow);
  return (ctValueHigh - ctValueLow);
}
