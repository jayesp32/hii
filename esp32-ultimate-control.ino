#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SoftwareSerial.h>

SoftwareSerial body(2, 4); 
SoftwareSerial voice(18, 19); 

const char* ssid = "Test1";          // Your WiFi SSID
const char* password = "12345678";   // Your WiFi password

// Create an instance of the web server
AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  body.begin(9600);


  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Route to handle the root page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", "<html><body><h1>Hello, ESP32!</h1></body></html>");
  });

  // Route to execute a custom command
  // Route to execute a custom command
server.on("/custom-command", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("value")) {
        String value = request->getParam("value")->value();
        Serial.println("Value: " + value);
        body.println(value);
        // Handle the "value" parameter
        // Your code here to process the value parameter

        request->send(200, "text/plain", "Value received and printed: " + value);
    } else if (request->hasParam("state")) {
        String state = request->getParam("state")->value();
        Serial.println("State: " + state);
        voice.println(state);
        // Handle the "state" parameter
        // Your code here to process the state parameter

        request->send(200, "text/plain", "State received and printed: " + state);
    } else {
        request->send(400, "text/plain", "Value or State parameter missing.");
    }
});


  // Start the server
  server.begin();
}

void loop() {
  // Your code here
}

