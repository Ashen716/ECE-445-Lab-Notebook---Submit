#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "ESP32_AP";
const char *password = "12345678"; // Minimum 8 characters required

const int gpioPins[] = {5, 6, 7, 8, 9, 10};  // GPIO 11–13 excluded
bool keyStates[256] = {false}; // Track key states

WebServer server(80);

void handleRoot() {
    server.send(200, "text/html", R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
        <title>ESP32 Keyboard Input</title>
    </head>
    <body>
        <h2>Type to Send Data to ESP32</h2>
        <input type="text" id="textInput" onkeydown="sendText(event.key, true)" onkeyup="sendText(event.key, false)" autofocus>
        <script>
            function sendText(key, state) {
                fetch("/send?key=" + encodeURIComponent(key) + "&state=" + (state ? "on" : "off"));
            }
        </script>
    </body>
    </html>
    )rawliteral");
}

void updateGPIOControl() {
    bool w = keyStates['w'];
    bool s = keyStates['s'];
    bool a = keyStates['a'];
    bool d = keyStates['d'];
    bool e = keyStates['e'];
    bool q = keyStates['q'];

    if (w && s) w = s = false;
    if (a && d) a = d = false;
    if (q && e) q = e = false;

    if (w && (a || d)) w = false;
    if (s && (a || d)) s = false;

    digitalWrite(5, w || d);
    digitalWrite(6, s || a);
    digitalWrite(7, w || a);
    digitalWrite(8, s || d);
    digitalWrite(9, e);
    digitalWrite(10, q);
}

void handleText() {
    if (server.hasArg("key") && server.hasArg("state")) {
        String key = server.arg("key");
        String state = server.arg("state");
        char keyChar = key[0];
        keyStates[keyChar] = (state == "on");
        Serial.println("Received: " + key + " - " + state);
        updateGPIOControl();
    }
    server.send(200, "text/plain", "OK");
}

void setup() {
    Serial.begin(115200);

    // Setup and initialize only GPIO 5–10
    for (int pin : gpioPins) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    // Permanently set GPIO 11, 12, 13 to HIGH
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);

    WiFi.softAP(ssid, password);
    Serial.println("Access Point Started");
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());

    server.on("/", handleRoot);
    server.on("/send", handleText);
    server.begin();
}

void loop() {
    server.handleClient();

    // Only disable GPIO 5–10 if no clients are connected
    if (WiFi.softAPgetStationNum() == 0) {
        for (int pin : gpioPins) {
            digitalWrite(pin, LOW);
        }
    }
}

