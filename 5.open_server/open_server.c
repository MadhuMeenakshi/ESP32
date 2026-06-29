#include <WiFi.h>
#include <WebServer.h>

// Replace with your WiFi details
const char* ssid =  "Wokwi-GUEST";
const char* password = "";

WebServer server(80);

void handleRoot() {
  String html = R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
      <title>ESP32 Web Server</title>
    </head>
    <body>
      <h1>Welcome to ESP32 Web Server!</h1>
      <p>The ESP32 is serving this page.</p>
    </body>
    </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);

  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");

  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);

  server.begin();  

  Serial.println("Web Server Started");
}

void loop() {
  server.handleClient();
}