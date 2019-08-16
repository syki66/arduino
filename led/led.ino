int redPin = 11;
int greenPin = 10;
int bluePin = 9;
 
void setup()
{
 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT); 
}

int i, j= 0;
int k = 255;
void loop()
{
  k++;
  setColor(255, 255, 255);
  delay(4000);
  
  for(int i=255; i>0;i--){
    setColor(255, i, i);
    delay(10);
  }
  delay(4000);

  for(int i=0; i<256;i++){
    setColor(255-i, i, i);
    delay(10);
  }
  delay(4000);

  for(int i=0; i<256;i++){
    setColor(i, 255, 255);
    delay(10);
  }


}
 
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue); 
}