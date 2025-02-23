#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// Button pins
#define BUTTON1_PIN 22  
#define BUTTON2_PIN 15 
#define BUTTON3_PIN 21  

#define TFT_CS   5    
#define TFT_DC   2  
#define TFT_RST  4   

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// Variables to hold button states
bool button1State = HIGH, lastButton1State = HIGH;
bool button2State = HIGH, lastButton2State = HIGH;
bool button3State = HIGH, lastButton3State = HIGH;

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing Display...");

  // Initialize button pins
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);

  // Initialize display
  
  tft.initR(INITR_BLACKTAB);    
  tft.fillScreen(ST77XX_BLACK);
  tft.setRotation(2); //Portrait
  tft.setTextWrap(true);
  tft.setTextSize(1);
  tft.setTextColor(ST77XX_WHITE);
  
  tft.setCursor(0, 0);
  tft.println("Press a Button");
}

void loop() {
  // Read the current state of each button
  button1State = digitalRead(BUTTON1_PIN);
  button2State = digitalRead(BUTTON2_PIN);
  button3State = digitalRead(BUTTON3_PIN);

  // Check for a new press (HIGH -> LOW transition)
  if (button1State == LOW && lastButton1State == HIGH) {
    tft.fillScreen(ST77XX_BLACK);
    tft.setCursor(0, 0);
    tft.println("Button 1 -");
    tft.println("Hello B1");
    Serial.println("Button 1 Pressed!");
  }
  if (button2State == LOW && lastButton2State == HIGH) {
    tft.fillScreen(ST77XX_BLACK);
    tft.setCursor(0, 0);
    tft.println("Button 2 -");
    tft.println("Hello B2");
    Serial.println("Button 2 Pressed!");
  }
  if (button3State == LOW && lastButton3State == HIGH) {
    tft.fillScreen(ST77XX_BLACK);
    tft.setCursor(0, 0);
    tft.println("Button 3 -");
    tft.println("Hello B3");
    Serial.println("Button 3 Pressed!");
  }

  // Update last button states
  lastButton1State = button1State;
  lastButton2State = button2State;
  lastButton3State = button3State;

  delay(50); 
}
