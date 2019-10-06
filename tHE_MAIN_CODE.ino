
#include <ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266WebServer.h>
//ESP8266WebServer server(80);
WiFiServer server(80);
uint8_t GPIO_Pin = D3;
String  i;
const char* ssid="Google pixel2";
const char* password="123456789";
//?////////////////////////////////////////////
void handleRoot()
{
  //use only in hotspot mode
}

////////////////////
void ISR()
{
  //WRITE THE CODE FOR ACTIVATING HOTSPOT MODE AND GETTING CREDENTIALS
}

///////////////////////////////


void setup()
{
  i = "";
  pinMode(D2,OUTPUT);//the relay to be connected
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT); 
 digitalWrite(D5,HIGH);
 digitalWrite(D6,HIGH);
 digitalWrite(D7,HIGH);
 attachInterrupt(digitalPinToInterrupt(GPIO_Pin), ISR, FALLING);



  WiFi.disconnect();
  delay(3000);
   WiFi.begin(ssid,password);//connecting to  a wifi network
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);

  }
  server.begin();
digitalWrite(D5,LOW);
}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
if(i=="n") digitalWrite(D2,HIGH);
if(i=="f") digitalWrite(D2,LOW);
}
