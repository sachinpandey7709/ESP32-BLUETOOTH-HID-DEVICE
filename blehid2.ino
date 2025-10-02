#include <BleKeyboard.h>

#define BUTTON_1_PIN 16 // Button 1 (Trigger: Rickroll)
#define BUTTON_2_PIN 17 // Button 2 (Trigger: System Info)
#define BUTTON_3_PIN 18 // Button 3 (Trigger: Windows Lock)

char kbd[] = "Headphone"; // Device Name
BleKeyboard bleKeyboard(kbd, "Espressif", 100);

bool lastState1 = HIGH;
bool lastState2 = HIGH;
bool lastState3 = HIGH;

void sendString(const char* s, int charDelay = 10) {
  for (size_t i = 0; i < strlen(s); i++) {
    bleKeyboard.print(s[i]);
    delay(charDelay);
  }
}

void openRun() {
  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press('r');
  delay(100);
  bleKeyboard.releaseAll();
  delay(300);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE HID setup with 4 Triggers on Buttons 1, 2, 3, 4 (Pins 16, 17, 18, 19)...");

  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);

  Serial.println("Initializing BLE...");
  delay(1000);
  bleKeyboard.begin();
  Serial.println("BLE ready. Connect as 'Headphone'.");
}

void loop() {
  if (bleKeyboard.isConnected()) {
    bool state1 = digitalRead(BUTTON_1_PIN);
    bool state2 = digitalRead(BUTTON_2_PIN);
    bool state3 = digitalRead(BUTTON_3_PIN);

    // Button 1: Rickroll (Pin 16)
    if (lastState1 == HIGH && state1 == LOW) {
      Serial.println("Button 1: Rickroll (Pin 16)");
      openRun(); delay(700); 
      const char* url = "https://youtube.com/shorts/SXHMnicI6Pg?si=uX7jga76jFQsKcYo"; 
      sendString(url, 10); delay(300); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
    }

    // Button 2: System Info (Pin 17)
    if (lastState2 == HIGH && state2 == LOW) {
      Serial.println("Button 2: System Info (Pin 17)");
      openRun(); delay(300); 
      sendString("cmd"); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(300); 
      bleKeyboard.releaseAll(); delay(700);
      sendString("systeminfo", 10); delay(200); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
    }

    // Button 3: Windows Lock (Win + L) (Pin 18)
    if (lastState3 == HIGH && state3 == LOW) {
      Serial.println("Button 3: Lock Screen (Win+L) (Pin 18)");
      bleKeyboard.press(KEY_LEFT_GUI); 
      bleKeyboard.press('l'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(500);
    }

    lastState1 = state1;
    lastState2 = state2;
    lastState3 = state3;
  } else {
    Serial.println("Waiting for BLE connection...");
  }
  delay(50); // Debounce/stability

}

