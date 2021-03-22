#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "extapp_api.h"


#define LCD_WIDTH_PX 320
#define LCD_HEIGHT_PX 222
#define TOOLBAR_HEIGHT_PX 18

#define _WHITE 0xffff
#define _BLACK 0x0000
#define _RED 0xff00

void concatenate(char [], char []);


void draw_rectangle(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t color) {
  extapp_pushRectUniform(x, y + TOOLBAR_HEIGHT_PX, w, h, color);
}

void draw_rectangle_text(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t color, const char *text) {
  extapp_pushRectUniform(x, y + TOOLBAR_HEIGHT_PX, w, h, color);
  extapp_drawTextSmall(text, x, y + TOOLBAR_HEIGHT_PX, _BLACK, color, false);
}

char* get_column_name(int column) {
  char* a;
  char* temp;
  char temp2[4];
  if ( column < 26){
    sprintf(a, "%c", column+64);
    return a;
  } else {
    int tempoff = column / 26;
    sprintf(temp, "%c", tempoff+64);
    int tempcol = column % 26;
    sprintf(a, "%c", tempcol+64);
    concatenate(temp, a); //why doesn't this work ?
    return temp;
  }
}

void concatenate(char p[], char q[]) {
   int c, d;
   
   c = 0;
 
   while (p[c] != '\0') {
      c++;      
   }
 
   d = 0;
 
   while (q[d] != '\0') {
      p[c] = q[d];
      d++;
      c++;    
   }
 
   p[c] = '\0';
}

void stroke_rectangle(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t color) {
  extapp_pushRectUniform(x, y + TOOLBAR_HEIGHT_PX, w, 1, color);
  extapp_pushRectUniform(x, y + h - 1 + TOOLBAR_HEIGHT_PX, w, 1, color);
  extapp_pushRectUniform(x, y + TOOLBAR_HEIGHT_PX, 1, h, color);
  extapp_pushRectUniform(x + w - 1, y + TOOLBAR_HEIGHT_PX, 1, h, color);
}

void draw_string(int16_t x, int16_t y, const char *text) {
  extapp_drawTextLarge(text, x, y + TOOLBAR_HEIGHT_PX, _BLACK, _WHITE, false);
}

void draw_string_small(int16_t x, int16_t y, uint16_t fg, uint16_t bg, const char *text) {
  extapp_drawTextSmall(text, x, y + TOOLBAR_HEIGHT_PX, fg, bg, false);
}

int rgb24to16(int c) {
  int r=(c>>16)&0xff,g=(c>>8)&0xff,b=c&0xff;
  return (((r*32)/256)<<11) | (((g*64)/256)<<5) | (b*32/256);
}


void copy(const char * text) {
  extapp_clipboardStore(text);
  draw_string(130, 100, "Copie !");
  extapp_msleep(500);
}

void extapp_main(void) {
  char buf[128];
  bool partial_draw = true, redraw = true;
  int cursor_pos_x = 0, cursor_pos_y = 0;
  char fucking_string[4];
  for (;;) {
    if (redraw) {
      if (partial_draw) {
        partial_draw = false;
        draw_rectangle(0, 0, LCD_WIDTH_PX, LCD_HEIGHT_PX, _WHITE);
        for(int i = 0; i< (LCD_WIDTH_PX / 40 ); i++){
          for(int k = 0; k < (LCD_HEIGHT_PX / 20); k++) {
            stroke_rectangle(40*i,20*k,40,20, _BLACK);
          }
        }
        for(int j = 1; j < (LCD_WIDTH_PX / 40 ); j++ ) {                
          draw_rectangle_text(40*j,1,38,18,_RED, get_column_name(30));
        }
        for(int l = 1; l < (LCD_HEIGHT_PX / 20); l++) {
          sprintf(fucking_string,"%d",l);
          draw_rectangle_text(0,20*l,38,18,_RED,fucking_string);
        }
         stroke_rectangle(40*cursor_pos_x,20*cursor_pos_y,40,20, _RED);
      } else {
        draw_rectangle(0, 0, LCD_WIDTH_PX, LCD_HEIGHT_PX, _WHITE);
      }
    }
    redraw = false;
    int key = extapp_getKey(true, NULL);
    if(key == KEY_CTRL_EXIT || key == KEY_CTRL_MENU) {
      return;
    } else if (key == KEY_CTRL_LEFT) {
      if (cursor_pos_x > 0) {
        cursor_pos_x--;
      }
      redraw = partial_draw = true;
    } else if (key == KEY_CTRL_RIGHT) {
      cursor_pos_x++;
      redraw = partial_draw = true;
    } else if (key == KEY_CTRL_UP) {
      if (cursor_pos_y > 0){
        cursor_pos_y--;
      }
      redraw = partial_draw = true;
    } else if (key == KEY_CTRL_DOWN) {
      cursor_pos_y++;
      redraw = partial_draw = true;
    }
  }
}
