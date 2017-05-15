#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h> 
#include <ESP8266Ping.h>
  
/* configuration  wifi */ 

IPAddress local_IP(192,168,4,2);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);
const char* ServerName = "SmartSam";
const char* ServerPassword = "12345678";

double distance ;

long rssi ;
IPAddress ClientIp;


ESP8266WebServer server(80);
 

const char* ssid     = "AlbertWifi";
const char* password = "3496BEF9";
 
int red = 14;
int yellow = 4;
int blue = 5;

void setup() {
  Serial.begin(115200);
  delay(10);

  //Setting up pin 
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);

  // We start by connecting to a WiFi network
  
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    TurnOnred();
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); 
  
}

int value = 0;

void loop() {  

  delay(2000);
   
  if(WiFi.status()== WL_CONNECTED) { 
     Serial.println("Wifi Connected");  
     rssi = WiFi.RSSI();
     Serial.print("RSSI:");
     Serial.print(rssi);
     Serial.println("dbm") ; 
   
     distance = ((27.55 - (20 * log10(2412)) + ((-1)*rssi)  )/20);
     distance = pow(10,distance);
     Serial.print("distance:");
     Serial.print( distance);
     Serial.println("m") ; 
     if(distance >= 0 && distance < 5){
      Serial.println("dekat") ;
      TurnOnblue();
     }
      if(distance >= 5 && distance < 15){
      Serial.println("agak jauh") ;
      TurnOnyellow();
     }
      if(distance >= 15){
      Serial.println("jauh") ;
      TurnOnred();
     }
  }
  else{ 
    Serial.println("Wifi DisConnected");  
    Serial.println("terputus/sangat jauh") ;
    TurnOnred();
  }  
} 

void TurnOnblue(){  
  // turn off red and yellow, then turn on blue
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH); 
}

void TurnOnyellow(){  
  // turn off red and blue then turn on yellow
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW); 
}

void TurnOnred(){  
  // turn off blue and yellow, then turn on red
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW); 
}
  
// distance = 10 ^ ((27.55 - (20 * log10(frequency)) + signalLevel)/20)
 
//Chip ID = 008E9B2F
//MAC: 2F:9B:8E:7F:CF:5C



 





 

