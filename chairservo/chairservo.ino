#include <Servo.h>
Servo servo_test;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo_test.attach(9);
  servo_test.write(90);
}
int a,b=90,c;
void loop() {
  // put your main code here, to run repeatedly:
c=analogRead(A0);
Serial.print("seat: ");
Serial.println(c);
if(c>4)
{
while(1){
a=analogRead(A1);
Serial.print("back: ");
Serial.println(a);
if((a<4)&&(analogRead(A0)>10)){
  servo_test.write(b);
  b=b-2;
  delay(800);
  Serial.print("b is: ");
  Serial.println(b);}
else if((a>20)&&(analogRead(A0)>10)){
  delay(100);
  servo_test.write(b);
  b=b+2;
  delay(1000);
  Serial.print("b is: ");
  Serial.println(b);}
else{
  delay(2000);
  to90();
  break;
}
}
}
else{
  to90();
}
}
void to90()
{
  while(b!=90)
  {
    if(b<90)
    {
         servo_test.write(b);
         b=b+2;
         delay(500);
         Serial.print("b is: ");
  Serial.println(b);
    }
    else
    {
      servo_test.write(b);
         b=b-2;
         delay(500);
         Serial.print("b is: ");
  Serial.println(b);
    }
  }
}
