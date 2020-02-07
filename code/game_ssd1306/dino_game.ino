
uint8_t unsigned const dino_image[] PROGMEM = {
  0x00, 0x1f, 0xf0, 0x00, 0x37, 0xf0, 0x00, 0x3f, 0xf0, 0x00, 0x3f, 0xf0, 0x00, 0x3f, 0xf0, 0x00, 
  0x3e, 0x00, 0x00, 0x3f, 0xc0, 0x80, 0x7c, 0x00, 0x81, 0xfc, 0x00, 0xc3, 0xff, 0x00, 0xe7, 0xfc, 
  0x00, 0xff, 0xfc, 0x00, 0xff, 0xfc, 0x00, 0x3f, 0xf8, 0x00, 0x1f, 0xf0, 0x00, 0x0f, 0xe0, 0x00, 
  0x07, 0x60, 0x00, 0x06, 0x20, 0x00, 0x04, 0x20, 0x00, 0x06, 0x30, 0x00
};

uint8_t unsigned const dino_front_leg[] PROGMEM = {
  0x00, 0x1f, 0xe0, 0x00, 0x37, 0xf0, 0x00, 0x3f, 0xf0, 0x00, 0x3f, 0xf0, 0x00, 0x3f, 0xf0, 0x00, 
  0x3e, 0x00, 0x00, 0x3f, 0xc0, 0x80, 0x7c, 0x00, 0x81, 0xfc, 0x00, 0xc3, 0xff, 0x00, 0xe7, 0xfd, 
  0x00, 0xff, 0xfc, 0x00, 0x7f, 0xfc, 0x00, 0x3f, 0xf8, 0x00, 0x1f, 0xf0, 0x00, 0x0f, 0xe0, 0x00, 
  0x06, 0x60, 0x00, 0x03, 0x20, 0x00, 0x00, 0x20, 0x00, 0x00, 0x30, 0x00
};


uint8_t unsigned const dino_back_leg[] PROGMEM = {
  0x00, 0x1f, 0xe0, 0x00, 0x37, 0xf0, 0x00, 0x3f, 0xf0, 0x00, 0x3f, 0xf0, 0x00, 0x3f, 0xf0, 0x00, 
  0x3e, 0x00, 0x00, 0x3f, 0xc0, 0x80, 0x7c, 0x00, 0x81, 0xfc, 0x00, 0xc3, 0xff, 0x00, 0xe7, 0xfd, 
  0x00, 0xff, 0xfc, 0x00, 0xff, 0xfc, 0x00, 0x3f, 0xf8, 0x00, 0x1f, 0xf0, 0x00, 0x0f, 0xe0, 0x00, 
  0x07, 0x30, 0x00, 0x06, 0x00, 0x00, 0x04, 0x00, 0x00, 0x06, 0x00, 0x00
};



uint8_t player_y = 40;

float full_jump_speed = 13;
float jump_speed = full_jump_speed;
float gravity = 2.2;

bool can_jump = true;

int dino_game_STATE= 0;

const uint8_t dino_game_floor = 60;
bool isFowardLeg = true;
uint8_t score = 0;
uint8_t score_gameover = 0;

typedef struct obstacle {
  int width = 7;
  int height = 15;
  int speed = 5;
  int y = 45;
  int x = 100;
} Obstacle;


Obstacle obstacle_array[3];

void dino_game_display(){
  display.clearDisplay();
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
 // display.setCursor(70, 0);
 // display.println(player_y);

  
  if(dino_game_STATE == 0){
    // Game Running State

    display.setCursor(60, 0);
    display.println(score);
    
    // Hitting Floor
    if(player_y >= 40){
      can_jump = true;
      jump_speed = full_jump_speed;
      player_y = 40;
    }
  
    display.drawLine(0, 60, 128, 60, WHITE);
  
  
    if(isFowardLeg){
      isFowardLeg = false;
      display.drawBitmap(15, player_y, dino_back_leg, 20, 20, WHITE);
    } else{
      isFowardLeg = true;
      display.drawBitmap(15, player_y, dino_front_leg, 20, 20, WHITE);
    }
  
    
    obstacle_array[0].x -= obstacle_array[0].speed;
    display.fillRect(obstacle_array[0].x, obstacle_array[0].y, obstacle_array[0].width, obstacle_array[0].height, WHITE);
  
    if(obstacle_array[0].x + obstacle_array[0].width < 0){
      obstacle_array[0].x = 128;
      obstacle_array[0].speed = round(random(6, 10)) ;
      score++;
    }
  
   // Collision
    if(15+20 > obstacle_array[0].x && 15 < obstacle_array[0].x+obstacle_array[0].width && player_y+20 > obstacle_array[0].y){
      dino_game_STATE = 1;
      can_jump = true;
      player_y = 40;
      score_gameover = score;
    }
   
  } else {
     // Game fail state
    display.setCursor(60, 0);
    display.println(score_gameover);
    display.setCursor(15, 27);
    display.println(F("Game Over"));
  }
  
  
  display.display();
  delay(1);
  
}


void dino_game_input_handle(){

  
  if(right_button_state || left_button_state){
    if(dino_game_STATE == 0){
      if(can_jump){
        can_jump = false;
      }
    } else{
      delay(100);
      score = 0;
      dino_game_STATE = 0;
      obstacle_array[0].x = 128;
      obstacle_array[0].speed = round(random(6, 10)) ;
    }
  } else if(right_shoulder_button_state || left_shoulder_button_state){
    STATE = 0;
    display.clearDisplay();
    delay(50);
  }

  
  if(!can_jump){
    jump_speed -= gravity;
    player_y = player_y - round(jump_speed);
  }


}

