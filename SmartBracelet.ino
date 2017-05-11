#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h> 
#include <ESP8266Ping.h>

///// De :  http://www.esp8266.com/viewtopic.php?f=32&t=5669&start=4#sthash.OFdvQdJF.dpuf ///
extern "C" {
#include<user_interface.h>
}

/* configuration  wifi */ 

IPAddress local_IP(192,168,4,2);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);
const char* ServerName = "SmartSam";
const char* ServerPassword = "12345678";
float distance = 0;

IPAddress ClientIp;


ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<h1>You are connected</h1>");
  //String addy = server.client().remoteIP().toString();
  //Serial.println(addy);
}

void setup() {
  delay(1000);
  Serial.begin(115200); //Start communication between the ESP8266-12E and the monitor window
  Serial.println();
  Serial.print("Configuring access point...");

  //WiFi.mode(WIFI_AP); //Our ESP8266-12E is an AccessPoint
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(ServerName);
  //WiFi.softAP(ServerName, ServerPassword); // Provide the (SSID, password); 
  
  IPAddress myIP = WiFi.softAPIP(); // Obtain the IP of the Server
  Serial.print("AP IP address: "); // Print the IP to the monitor window
  Serial.println(myIP); 
  printMacAddress();
  server.on("/", handleRoot);
  server.begin(); // Start the HTTP Server
  Serial.println("HTTP server started"); 
 
  
  pinMode(LED_BUILTIN, OUTPUT); //GPIO16 is an OUTPUT pin;
  digitalWrite(LED_BUILTIN, LOW); //Initial state is ON
} 

void loop() {
  server.handleClient();   
  delay(1000);
  client_status();
  delay(1000);
}

void client_status() {

unsigned char number_client;
struct station_info *stat_info;


int32_t SignalStrenght ;
struct ip_addr *IPaddress;
IPAddress address;
int i=1;

number_client= wifi_softap_get_station_num(); // Count of stations which are connected to ESP8266 soft-AP
stat_info = wifi_softap_get_station_info();  



Serial.print(" Total connected_client are = ");
Serial.println(number_client);

while (stat_info != NULL) {
  
digitalWrite(LED_BUILTIN, HIGH);//Turn off the light 

IPaddress = &stat_info->ip;
address = IPaddress->addr;
ClientIp = address;

//SignalStrenght ;  
 

bool ret = Ping.ping(ClientIp); 
 
float avg_time_ms =  float(Ping.averageTime());
distance = ((avg_time_ms/2)*0.3);
//distance = pow(10,((27.55 - (20 * log(1)) + 1 )/20));
//((avg_time_ms/2)*299792,458);  

// distance = 10 ^ ((27.55 - (20 * log10(frequency)) + signalLevel)/20)


Serial.print("client= ");

Serial.print(i);
Serial.print(" ip adress is = ");
Serial.print((ClientIp));
Serial.print(" with mac adress is = ");

Serial.print(stat_info->bssid[0],HEX);
Serial.print(stat_info->bssid[1],HEX);
Serial.print(stat_info->bssid[2],HEX);
Serial.print(stat_info->bssid[3],HEX);
Serial.print(stat_info->bssid[4],HEX);
Serial.print(stat_info->bssid[5],HEX);

Serial.println("");
Serial.print("Client Time= ");
Serial.print(avg_time_ms);
Serial.print("ms");
Serial.println("");
Serial.print("Client Distance= ");
Serial.print(distance);
Serial.print("m");

stat_info = STAILQ_NEXT(stat_info, next);
i++;
Serial.println();
}

if(number_client == 0){
digitalWrite(LED_BUILTIN, LOW);//Turn on the light
}

delay(500);
} 

//Separator

void printMacAddress() {
  // the MAC address of your Wifi shield
  byte mac[6];

  // print your MAC address:
  WiFi.macAddress(mac);
  Serial.print("MAC: ");
  Serial.print(mac[5], HEX);
  Serial.print(":");
  Serial.print(mac[4], HEX);
  Serial.print(":");
  Serial.print(mac[3], HEX);
  Serial.print(":");
  Serial.print(mac[2], HEX);
  Serial.print(":");
  Serial.print(mac[1], HEX);
  Serial.print(":");
  Serial.println(mac[0], HEX);
}

void listNetworks() {
  // scan for nearby networks:
  Serial.println("** Scan Networks **");
  int numSsid = WiFi.scanNetworks();
  if (numSsid == -1) {
    Serial.println("Couldn't get a wifi connection");
    while (true);
  }

  // print the list of networks seen:
  Serial.print("number of available networks:");
  Serial.println(numSsid);

  // print the network number and name for each network found:
  for (int thisNet = 0; thisNet < numSsid; thisNet++) {
    Serial.print(thisNet);
    Serial.print(") ");
    Serial.print(WiFi.SSID(thisNet));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(thisNet));
    Serial.print(" dBm");
    Serial.print("\tEncryption: ");
    printEncryptionType(WiFi.encryptionType(thisNet));
  }
}

void printEncryptionType(int thisType) {
  // read the encryption type and print out the name:
  switch (thisType) {
    case ENC_TYPE_WEP:
      Serial.println("WEP");
      break;
    case ENC_TYPE_TKIP:
      Serial.println("WPA");
      break;
    case ENC_TYPE_CCMP:
      Serial.println("WPA2");
      break;
    case ENC_TYPE_NONE:
      Serial.println("None");
      break;
    case ENC_TYPE_AUTO:
      Serial.println("Auto");
      break;
  }
}  
//Chip ID = 008E9B2F
//MAC: 2F:9B:8E:7F:CF:5C



 

