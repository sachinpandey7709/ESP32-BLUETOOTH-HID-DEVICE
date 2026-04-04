#include <WiFi.h>
#include <WebServer.h>
#include <SPIFFS.h>
#include <BleKeyboard.h>

const char* ssid = "ESP32_Ducky";
const char* password = "12345678";

WebServer server(80);
BleKeyboard bleKeyboard("ESP32 Ducky");

void handleRoot() {
  File file = SPIFFS.open("/index.html", "r");
  server.streamFile(file, "text/html");
  file.close();
}

void handleSave() {
  String data = server.arg("data");
  File file = SPIFFS.open("/script.txt", "w");
  file.print(data);
  file.close();
  server.send(200, "text/plain", "Saved");
}

void handleLoad() {
  File file = SPIFFS.open("/script.txt", "r");
  String data = file.readString();
  file.close();
  server.send(200, "text/plain", data);
}

void handleSend() {
  String data = server.arg("data");
  server.send(200, "text/plain", "Sent");

  if (bleKeyboard.isConnected()) {
    bleKeyboard.print(data);
  }
}

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  Serial.println(WiFi.softAPIP());

  SPIFFS.begin(true);

  bleKeyboard.begin();

  server.on("/", handleRoot);
  server.on("/save", handleSave);
  server.on("/load", handleLoad);
  server.on("/send", handleSend);

  server.begin();
}

void loop() {
  server.handleClient();
}
