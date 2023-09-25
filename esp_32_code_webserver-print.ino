#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Define your WiFi credentials
const char* WIFI_SSID = "Test1";
const char* WIFI_PASSWORD = "12345678";

// Create an instance of the web server
AsyncWebServer server(80);

// Number of commands
const int NUM_COMMANDS = 100;

void setup() {
    // Start Serial communication for debugging
    Serial.begin(115200);

    // Connect to Wi-Fi
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi!");

    // Print the ESP32's IP address
    Serial.println("ESP32 IP address: " + WiFi.localIP().toString());

    // Define web server route
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        String html = "<html><body>";
        html += "<h1>ESP32 Web Server</h1>";
        html += "<p>Hello from ESP32!</p>";
        html += "<p>Available commands:</p>";
        html += "<ul>";
        for (int i = 1; i <= NUM_COMMANDS; i++) {
            html += "<li><a href='/command" + String(i) + "'>Command " + String(i) + "</a></li>";
        }
        html += "</ul>";
        html += "</body></html>";
        request->send(200, "text/html", html);
    });

    // Define routes for the commands (command1 to command50)
    for (int i = 1; i <= NUM_COMMANDS; i++) {
        String commandRoute = "/command" + String(i);

        server.on(commandRoute.c_str(), HTTP_GET, [i](AsyncWebServerRequest *request){
            Serial.println( String(i)); // Trigger Serial print
            request->send(200, "text/plain", "Command " + String(i) + " received");
        });
    }

    // Start the server
    server.begin();
}

void loop() {
    // Your additional code can go here

    // Handle other tasks or checks in the loop

    delay(1000); // Add a delay for stability
}
