float MAX_WEIGHT = 2000;  // 最大計測重量 2 kg


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float weight = analogRead(A5) / 1023 * MAX_WEIGHT;
  
  Serial.println(weight);
  delay(100);
}
