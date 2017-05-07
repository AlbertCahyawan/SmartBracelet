#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h>

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
  delay(5000);
  client_status();
  delay(4000);
}

void client_status() {

unsigned char number_client;
struct station_info *stat_info;

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

Serial.print("client= ");

Serial.print(i);
Serial.print(" ip adress is = ");
Serial.print((address));
Serial.print(" with mac adress is = ");

Serial.print(stat_info->bssid[0],HEX);
Serial.print(stat_info->bssid[1],HEX);
Serial.print(stat_info->bssid[2],HEX);
Serial.print(stat_info->bssid[3],HEX);
Serial.print(stat_info->bssid[4],HEX);
Serial.print(stat_info->bssid[5],HEX);

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


/*
 

void loop() { 

  WiFiClient client = server.available();
  
  while (client.connected()) { 
    Serial.println("Somebody is connected :)");
    Serial.println(WiFi.softAPIP());
     Serial.println(" ");
     delay(5000);
    char c = client.read();
    Serial.write(c);
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if (!client) {
    digitalWrite(LED_BUILTIN, LOW); 
    //  digitalWrite(LED_BUILTIN, LOW);
    return;
  } 
} 

// this method makes a HTTP connection to the server:
void httpRequest() {
  // close any connection before send a new request.
  // This will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection:
  if (client.connect(server, 80)) {
    Serial.println("connecting...");
    // send the HTTP PUT request:
    client.println("GET /latest.txt HTTP/1.1");
    client.println("Host: www.arduino.cc");
    client.println("User-Agent: ArduinoWiFi/1.1");
    client.println("Connection: close");
    client.println();

    // note the time that the connection was made:
    lastConnectionTime = millis();
  } else {
    // if you couldn't make a connection:
    Serial.println("connection failed");
  }
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

//Chip ID = 008E9B2F
//MAC: 2F:9B:8E:7F:CF:5C

*/


 /*

  //Read what the browser has sent into a String class and print the request to the monitor
  String request = client.readStringUntil('\r');
  //Looking under the hood
  Serial.println(request); 


 
  if (request.indexOf("/OFF") != -1) {
   
  }
  else if (request.indexOf("/ON") != -1) {
    digitalWrite(LED_BUILTIN, LOW);
  }

 // Prepare the HTML document to respond and add buttons:
  String s = "HTTP/1,1 200 OK\r\n";
  s += "content-type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML>\r\n<html>\r\n";
  s += "<br><input type=\"buton\" name=\"b1\" value=\"Turn Led ON\" onclick=\"location.href='/ON'\">";
  s += "<br><br><br>";
  s += "<br><input type=\"buton\" name=\"b1\" value=\"Turn Led OFF\" onclick=\"location.href='/OFF'\">";
  s += "</html>\n";
 
  //client.flush(); //clear previous info in the stream
  client.print(s); // Send the response to the client
  delay(1);
  Serial.println("Client disonnected"); //Looking under the hood  
  */


