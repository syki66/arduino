int redPin = 10;
int greenPin = 11;
int bluePin = 9;
 
void setup()
{
 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT); 
 Serial.begin(9600);
}

// 흰, 빨, 주, 노, 초, 파, 남, 보
int rgb[][3] = {
  {255,255,255}, //흰색
  {255, 0, 0},   // 빨강
  {255, 127, 0},   // 주황
  {255, 212, 0},   // 노랑
  {0, 255, 0}, // 초록
  {0, 0, 255}, // 파랑
  {0, 0, 128}, // 남색
  {139, 0, 255} // 보라
};



int cnt = 0;


int previous_r = 0, previous_g = 0, previous_b = 0;
int r = 0, g = 0, b = 0;
int r_change = 0, g_change = 0, b_change = 0;




void loop()
{

  r = rgb[cnt][0];
  g = rgb[cnt][1];
  b = rgb[cnt][2];
  
  r_change = previous_r - r;
  g_change = previous_g - g;
  b_change = previous_b - b;
  
  while ( !((r_change == 0) && (g_change == 0) && (b_change == 0)) ){
    if (r_change < 0){
      previous_r++;
      r_change++;
    }
    else if (r_change > 0) {
      previous_r--;
      r_change--;   
    }
    
    if (g_change < 0){
      previous_g++;
      g_change++;
    }
    else if (g_change > 0) {
      previous_g--;
      g_change--;   
    }
    
    if (b_change < 0){
      previous_b++;
      b_change++;
    }
    else if (b_change > 0) {
      previous_b--;
      b_change--;   
    }
    
    setColor(previous_r, previous_g, previous_b);
    delay(10);
    Serial.print(previous_r);
    Serial.print(", ");
    Serial.print(previous_g);
    Serial.print(", ");
    Serial.println(previous_b);
    }
  
  Serial.println("=============");
  Serial.print(previous_r);
  Serial.print(", ");
  Serial.print(previous_g);
  Serial.print(", ");
  Serial.println(previous_b);
  Serial.println("=============");

  setColor(previous_r, previous_g, previous_b);
  delay(4000);

  
  
  if ( cnt < (sizeof(rgb) / sizeof(rgb[0]))-1 ) {
    cnt++;
  } else {
    cnt = 0;
  }
  
  Serial.println(cnt);

}






// pcm 단자일때는 아날로그 쓰면되고
// 디지털 단자는 digitalWrite(redPin, HIGH); 이런식으로 쓰면됨

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue); 
}