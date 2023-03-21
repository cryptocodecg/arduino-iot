#define BLYNK_TEMPLATE_ID "TMPL4mpHdm2b"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "1Un2eoRi4Wk1nBQ2H34LdN7tFLXqBcNA"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

#define BLYNK_PRINT Serial
#define DHTTYPE DHT11
#define DHTPIN 4

DHT dht(DHTPIN, DHTTYPE);
float humidity, temp;
char auth[] = "1Un2eoRi4Wk1nBQ2H34LdN7tFLXqBcNA";
//char ssid[] = "DJUWITA";
//char pass[] = "50767953";
const char* ssid ="k";
const char* pass = "awzo3557";

void setup() {  // put your setup code here, to run once
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  //Blynk.config(auth);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
 
  // Print ESP MAC Address
  Serial.println("MAC address: ");
  Serial.println(WiFi.macAddress());
  
    
 // Blynk.begin(auth, ssid, pass);
 
}



bool isFirstConnect = true;
BLYNK_CONNECTED(){
  if (isFirstConnect){
    Blynk.syncAll();
    isFirstConnect = false;
  }
}

void loop() {
  // put your main code here, to run repeatedly:  
    humidity = dht.readHumidity();
    temp = dht.readTemperature();
    Serial.print(F("Humidity: "));
    Serial.print(humidity);
    Serial.print("\n");
    Serial.print(F("  Temperature: "));
    Serial.print(temp);
    Serial.print(F("°C "));
    Blynk.virtualWrite(V0, temp);
    Blynk.virtualWrite(V1, humidity);
   
    delay(2000);  
    Blynk.run();
 
}
