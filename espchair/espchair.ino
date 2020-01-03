#include <Servo.h>
#include <SoftwareSerial.h>
#define RX 4
#define TX 5
String AP = "dummy";
String PASS = "lmfaohaha";
String API = "H2LD60SZO0MUA78Z";
String HOST = "api.thingspeak.com";
String PORT = "80";
String field = "field1";
int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
int valSensor = 1;
SoftwareSerial esp8266(RX,TX); 
Servo servo_test;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo_test.attach(9);
servo_test.write(90);
esp8266.begin(115200);
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=1",5,"OK");
  sendCommand("AT+CWJAP=\""+ AP +"\",\""+ PASS +"\"",20,"OK");
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
  thingspeak(b);
  Serial.print("b is: ");
  Serial.println(b);}
else if((a>20)&&(analogRead(A0)>10)){
  delay(100);
  servo_test.write(b);
  b=b+2;
  thingspeak(b);
  Serial.print("b is: ");
  Serial.println(b);}
else{
  delay(3000);
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
         thingspeak(b);
         Serial.print("b is: ");
  Serial.println(b);
    }
    else
    {
      servo_test.write(b);
         b=b-2;
         thingspeak(b);
         Serial.print("b is: ");
  Serial.println(b);
    }
  }
}
void thingspeak(int val)
{
  String getData = "GET /update?api_key="+ API +"&"+ field +"="+String(val);
sendCommand("AT+CIPMUX=1",5,"OK");
 sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
 esp8266.println(getData);delay(1500);countTrueCommand++;
 sendCommand("AT+CIPCLOSE=0",5,"OK");
}
void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    esp8266.println(command);//at+cipsend
    if(esp8266.find(readReplay))//ok
    {
      found = true;
      break;
    }
  
    countTimeCommand++;
  }
  
  if(found == true)
  {
    Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }
  
  found = false;
 }
