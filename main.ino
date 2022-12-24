float G = 9.80665;  //  重力加速度
float MAX_BIT = 1023;  // 最大ビット数
float MAX_PRESSURE = 10;  // 最大計測圧力
float BIAS = 557;  // 圧力センサーの補正項
  
float max_weight;  // 最大計測重量
float maxAnalogValue;  // 圧力センサの最大値


void setup()
{
  Serial.begin(9600);
  max_weight = MAX_PRESSURE / G;  // 最大計測重量
  maxAnalogValue = MAX_BIT - BIAS;
}

void loop()
{
  float weight = getWeight();
  Serial.println(weight);
  delay(100);
}

float getWeight()
{
  float ratio = (MAX_BIT - analogRead(A0)) / maxAnalogValue;
  float weight =  ratio * max_weight;
  return weight;
}
