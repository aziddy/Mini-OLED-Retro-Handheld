
/*
  A simple Pong game:
 */

#include <SPI.h>
#include <Wire.h>
#include "dino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <avr/pgmspace.h>
#include <math.h>



#define LEFT_SHOULDER_BUTTON A1
#define RIGHT_SHOULDER_BUTTON A2
#define LEFT_BUTTON 2
#define RIGHT_BUTTON 9
#define VBATPIN A6

static bool left_shoulder_button_state = false;
static bool right_shoulder_button_state = false;
static bool left_button_state = false;
static bool right_button_state = false; 

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(OLED_RESET);

void drawCourt();


uint8_t STATE = 0;
bool first = true;


void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  
  display.display();
  unsigned long start = millis();
  
  pinMode(LEFT_SHOULDER_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_SHOULDER_BUTTON, INPUT_PULLUP);
  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  
  display.clearDisplay();
 // drawCourt();
  
  while(millis() - start < 2000);
  
  display.display();


}

void loop() {
  bool update = false;
  unsigned long time = millis();

  left_shoulder_button_state = false;
  right_shoulder_button_state = false;
  left_button_state = false;
  right_button_state = false; 
  
  left_shoulder_button_state |= (digitalRead(LEFT_SHOULDER_BUTTON) == LOW);
  right_shoulder_button_state |= (digitalRead(RIGHT_SHOULDER_BUTTON) == LOW);
  left_button_state |= (digitalRead(LEFT_BUTTON) == LOW);
  right_button_state |= (digitalRead(RIGHT_BUTTON) == LOW);


  if(STATE == 0){
    menu_init();
    menu_display();
    menu_input_handle();
  } else if(STATE == 1){
    dino_game_display();
    dino_game_input_handle();
  } else if(STATE == 2){
    dino_game_display();
    dino_game_input_handle();
  } else if(STATE == 3){
    dino_game_display();
    dino_game_input_handle();
  } else if(STATE == 4){
    QR_code_page_display();
    QR_code_page_input_handle();
  }




}


void drawCourt() {
    display.drawRect(0, 0, 128, 64, WHITE);
}
