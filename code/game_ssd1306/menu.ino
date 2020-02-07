

  uint8_t cursor_pos_state = 0;
  uint8_t cursor_pos_y[] = {25, 35, 45, 55};
  
  static void menu_init(){
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
  
    display.setCursor(12, 0);
    display.println(F("OLED BOY!"));
  
    display.setTextSize(1);
    display.setCursor(92, 25);
    display.println(F("By:"));
    display.setCursor(92, 35);
    display.println(F("Alex"));
    display.setCursor(92, 45);
    display.println(F("Zidros"));
  
    display.setCursor(10, 25);
    display.println(F("Pong Game"));
    display.setCursor(10, 35);
    display.println(F("Dino Game"));
    display.setCursor(4, 45);
    display.println(F("Space Game"));
    display.setCursor(22, 55);
    display.println(F("QR Code"));
    
    
  }

  static void menu_display(){
    display.setTextSize(1);
    display.drawChar(65, cursor_pos_y[cursor_pos_state], '<', WHITE, 0, 1);

    float measuredvbat = analogRead(VBATPIN);
    measuredvbat *= 2;    // we divided by 2, so multiply back
    measuredvbat *= 3.3;  // Multiply by 3.3V, our reference voltage
    measuredvbat /= 1024; // convert to voltage
    display.setCursor(120, 55);
    display.println(F("v"));
    display.setCursor(95, 55);
    display.println(measuredvbat);


    display.display();
    
  }

  static void menu_input_handle(){//(bool LS, bool RS, bool L, bool R){
    if(right_button_state){
      if(cursor_pos_state < 3){
        cursor_pos_state++;
      } 
      display.clearDisplay();
      delay(100);
    } else if (left_button_state){
      if(cursor_pos_state > 0){
        cursor_pos_state--;
      } 
      display.clearDisplay();
      delay(100);  
    } else if(right_shoulder_button_state || left_shoulder_button_state){
      
     // display.fillScreen(0x0000);
      display.clearDisplay();
      delay(100);  
      STATE = cursor_pos_state+1;
    }
  }



