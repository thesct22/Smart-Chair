void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
}
int a,b=100,c;
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
if(a<4){
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(100);
  b=b+1;
  Serial.print("b is: ");
  Serial.println(b);}
else if(a>10){
  delay(100);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(400);
  b=b-1;
  Serial.print("b is: ");
  Serial.println(b);}
else{
  delay(1000);
  to90();
  break;
}
a=analogRead(A1);
Serial.print("back: ");
Serial.println(a);
if(a<4){
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(100);
  b=b+1;
  Serial.print("b is: ");
  Serial.println(b);}
else if(a>10){
  delay(100);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(400);
  b=b-1;
  Serial.print("b is: ");
  Serial.println(b);}
else{
  delay(1000);
  to90();
  break;
}
a=analogRead(A1);
Serial.print("back: ");
Serial.println(a);
if(a<4){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(100);
  b=b+1;
  Serial.print("b is: ");
  Serial.println(b);}
else if(a>10){
  delay(100);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(400);
  b=b-1;
  Serial.print("b is: ");
  Serial.println(b);}
else{
  delay(1000);
  to90();
  break;
}
a=analogRead(A1);
Serial.print("back: ");
Serial.println(a);
if (a<4){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(100);
  b=b+1;
  Serial.print("b is: ");
  Serial.println(b);}
else if(a>10){
  delay(100);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(400);
  Serial.print("b is: ");
  Serial.println(b);}
else{
  delay(1000);
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
  while(b!=100)
  {
    if(b<100)
    {
      if(b%4==0){
         delay(100);
         digitalWrite(8, LOW);
         digitalWrite(9, LOW);
         digitalWrite(10, LOW);
         digitalWrite(11, HIGH);
         delay(400);
         b=b-1;
         Serial.print("b is: ");
  Serial.println(b);
      }
      else if(b%4==1)
      {
        delay(100);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        delay(400);
        b=b-1;
        Serial.print("b is: ");
  Serial.println(b);
      }
      else if(b%4==2)
      {
        delay(100);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        delay(400);
        b=b-1;
        Serial.print("b is: ");
  Serial.println(b);
      }
      else if(b%4==3)
      {
        delay(100);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        delay(400);
        b=b-1;
        Serial.print("b is: ");
  Serial.println(b);
      }
    }
    else
    {
      if(b%4==0){
         delay(100);
         digitalWrite(8, LOW);
         digitalWrite(9, HIGH);
         digitalWrite(10, LOW);
         digitalWrite(11, LOW);
         delay(400);
         b=b-1;
         Serial.print("b is: ");
  Serial.println(b);
      }
      else if(b%4==1)
      {
        delay(100);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        delay(400);
        b=b-1;
        Serial.print("b is: ");
  Serial.println(b);
      }
      else if(b%4==2)
      {
        delay(100);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        delay(400);
        b=b-1;
        Serial.print("b is: ");
  Serial.println(b);
      }
      else if(b%4==3)
      {
        delay(100);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        delay(400);
        b=b-1;
        Serial.print("b is: ");
  Serial.println(b);
      }
    }
  }
}
