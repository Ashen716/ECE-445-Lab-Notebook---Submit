#include <WiFi.h>

const char* ssid = "ESP";
const char* password = "1234";

WiFiServer server(80);
const int ledPin = 1;

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    
    WiFi.softAP(ssid, password);

    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);
    
    server.begin();
}

void loop() {
    WiFiClient client = server.available();
    
    if (client) {
        Serial.println("Client connected.");
        digitalWrite(ledPin, HIGH);
        
        while (client.connected()) {
            Serial.println(WiFi.softAPgetStationNum());
            delay(10);
            if (WiFi.softAPgetStationNum() == 0) {
              digitalWrite(ledPin, LOW);
              break;
            }
        }
        
        Serial.println("Client disconnected.");
    }
}
