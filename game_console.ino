#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define I2C_SDA 21
#define I2C_SCL 22
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define JOY_Y 35 
#define JOY_X 34
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
struct Detalca 
{
  byte size[8][8];
};
byte game[64][128] = {0};
int start_x = 1;    
int start_y = 32;   
bool need_new = true;
bool flag = false;
Detalca new_detalca;
Detalca add_detalca() 
{
  int a = random(1, 3); 
  Detalca new_detalca; 
  byte palca_matrix[8][8] = 
  {
    {1, 1, 1, 1, 1, 1, 1, 1}, 
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0}
  };
  byte kv_matrix[8][8] = 
  {
    {1, 1, 1, 1, 1, 1, 0, 0}, 
    {1, 1, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0}, 
    {1, 1, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0}, 
    {1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0}
  };
  byte xr_matrix[8][8] = 
  {
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0}, 
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1}, 
    {0, 0, 0, 0, 1, 1, 1, 1},  
    {0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1}, 
    {0, 0, 0, 0, 1, 1, 1, 1}
  };
  byte z_matrix[8][8] = 
  {
    {0, 0, 0, 0, 1, 1, 1, 1}, 
    {0, 0, 0, 0, 1, 1, 1, 1},  
    {0, 0, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}, 
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0}, 
    {1, 1, 1, 1, 0, 0, 0, 0},
  };
  byte I_matrix[8][8] = 
  {
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0}, 
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0}, 
    {1, 1, 1, 1, 1, 1, 1, 1},  
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}, 
    {1, 1, 1, 1, 1, 1, 1, 1},
  };
  byte J_matrix[8][8] = 
  {
    {0, 0, 0, 0, 1, 1, 1, 1},  
    {0, 0, 0, 0, 1, 1, 1, 1}, 
    {0, 0, 0, 0, 1, 1, 1, 1},  
    {0, 0, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},  
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}, 
    {1, 1, 1, 1, 1, 1, 1, 1},
  };
  byte t_matrix[8][8] = 
  {
    {1, 1, 1, 1, 1, 1, 1, 1}, 
    {1, 1, 1, 1, 1, 1, 1, 1},  
    {1, 1, 1, 1, 1, 1, 1, 1}, 
    {1, 1, 1, 1, 1, 1, 1, 1}, 
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0}, 
    {0, 0, 1, 1, 1, 1, 0, 0},
  };
  switch (a) 
  {
    case 1: 
    {
      for(int i = 0; i < 8; i++) 
      {
        for(int j = 0; j < 8; j++) 
        {
          new_detalca.size[i][j] = palca_matrix[i][j];
        }
      } 
      break; 
    }
    case 2:
    { 
      for(int i = 0; i < 8; i++) 
      {
        for(int j = 0; j < 8; j++)
        {
          new_detalca.size[i][j] = kv_matrix[i][j];
        }
      } 
      break;
    }
    case 3: 
    {
      for(int i = 0; i < 8; i++) 
      {
        for(int j = 0; j < 8; j++)
        {
          new_detalca.size[i][j] = xr_matrix[i][j];
        }
      } 
      break;
    }
    case 4: 
    {
      for(int i = 0; i < 8; i++) 
      {
        for(int j = 0; j < 8; j++)
        {
          new_detalca.size[i][j] = z_matrix[i][j];
        }
      } 
      break;
    }
    case 5:
    { 
      for(int i = 0; i < 8; i++) 
      {
        for(int j = 0; j < 8; j++)
        {
          new_detalca.size[i][j] = I_matrix[i][j];
        }
      } 
      break;
    }
    case 6: 
    {
      for(int i = 0; i < 8; i++) 
      {
        for(int j = 0; j < 8; j++)
        {
          new_detalca.size[i][j] = J_matrix[i][j];
        }
      } 
      break;
    }
    case 7: 
    {
      for(int i = 0; i < 8; i++) 
      {
        for(int j = 0; j < 8; j++)
        {
          new_detalca.size[i][j] = t_matrix[i][j];
        }
      } 
      break;
    }
  }
  return new_detalca; 
}
void otr_det(Detalca detalca) 
{
  for (int i = 0; i < 8; i++) 
  {
    for (int j = 0; j < 8; j++) 
    {
      if (detalca.size[i][j] == 1) 
      {
        display.fillRect(start_x + j, start_y + i, 1, 1, SSD1306_WHITE);
      }
    }
  }
}
void gran() 
{
  for (int i = 0; i < 64; i++) 
  {
    for (int j = 0; j < 128; j++) 
    {
      if (game[i][j] == 1) 
      {
        display.fillRect(j, i, 1, 1, SSD1306_WHITE);
      }
    }
  }
}
bool go_d() 
{
  for (int i = 0; i < 8; i++) 
  {
    for (int j = 0; j < 8; j++) 
    {
      if (new_detalca.size[i][j] == 1) 
      {
        if (game[start_y + i][start_x + j + 1] == 1) 
        {
          return false; 
        }
      }
    }
  }
  return true; 
}
bool go_right()
{
  for (int i = 0; i < 8; i++) 
  {
    for (int j = 0; j < 8; j++) 
    {
      if (new_detalca.size[i][j] == 1) 
      {
        if (game[start_y + i + 1][start_x + j] == 1) 
        {
          return false; 
        }
      }
    }
  }
  return true; 
}
bool go_left()
{
  for (int i = 0; i < 8; i++) 
  {
    for (int j = 0; j < 8; j++) 
    {
      if (new_detalca.size[i][j] == 1) 
      {
        if (game[start_y + i - 1][start_x + j] == 1) 
        {
          return false; 
        }
      }
    }
  }
  return true; 
}
void play(Detalca detalca) 
{
  if (go_d()) 
  {
    otr_det(detalca);
    start_x++; 
  }
}
bool win() 
{
  bool zbc = false;
  bool gavno = true;
  while (gavno) 
  {
    gavno = false; 
    for (int i = 126; i >= 1; i--) 
    {
      bool is_full = true;
      for (int j = 1; j <= 62; j++) 
      {
        if (game[j][i] == 0) 
        {
          is_full = false;
          break;
        }
      }
      if (is_full) 
      {
        for (int st_i = i; st_i > 1; st_i--) 
        {
          for (int j = 1; j <= 62; j++) {
            game[j][st_i] = game[j][st_i - 1];
          }
        }
        for (int j = 1; j <= 62; j++) 
        {
          game[j][1] = 0;
        }
        zbc = true;
        gavno = true; 
        break; 
      }
    }
  }
  return zbc;
}
void setup() 
{
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);
  randomSeed(millis());
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  {
    Serial.println("Дисплей не найден!");
    while (1); 
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  for (int i = 0; i < 64; i++) 
  {
    for (int j = 0; j < 128; j++) 
    {
      if (i == 0 || j == 0 || i == 63 || j == 127) 
      {
        game[i][j] = 1;
      }
    }
  }
}
void loop() 
{
  if (need_new) 
  {
    new_detalca = add_detalca();
    start_x = 1;
    start_y = 28;
    need_new = false;
    if (!go_d()) {
      for (int i = 1; i < 63; i++) 
      {
        for (int j = 1; j < 127; j++) 
        {
          game[i][j] = 0;
        }
      }
      Serial.println("Лох");
    }
  }
  display.clearDisplay();
  gran();  
  if (analogRead(JOY_Y) < 1000) 
  {
    if (go_left()) 
    {
      start_y--;
    }
  } 
  if (analogRead(JOY_Y) > 4000) 
  {
    if (go_right()) 
    {
      start_y++;
    }
  }
  if (go_d()) 
  {
    start_x++; 
  } 
  else 
  {
    for (int i = 0; i < 8; i++) 
    {
      for (int j = 0; j < 8; j++) 
      {
        if (new_detalca.size[i][j] == 1) 
        {
          game[start_y + i][start_x + j] = 1;
        }
      }
    }
    need_new = true; 
  }
  win();
  otr_det(new_detalca); 
  display.display();  
  delay(10);  
}