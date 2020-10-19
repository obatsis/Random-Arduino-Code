#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include <epd.h>
#include <Fonts/FreeSans24pt7b.h>

const int led = LED_BUILTIN;                    
const int wake_up = 15;
const int reset = 14;

Adafruit_epd disp(wake_up, reset);
int i=0;
void setup(void)
{
  /*
  user led init
  */
  pinMode(led, OUTPUT);
  disp.wakeup();
  disp.set_memory(MEM_NAND);
  disp.set_color(BLACK,WHITE);
  disp.setFont(&FreeSans24pt7b);
}

void loop(void)
{
  disp.clear();
  disp.setTextSize(4);
  disp.setTextColor(BLACK);
  disp.setCursor(20,150);
  disp.print("TWA");
  disp.setCursor(0,550);
  disp.setTextSize(9);
  disp.print('.');
  disp.print((int)random(0, 360));
  disp.udpate();
  delay(2000);
  disp.clear();
  disp.setTextSize(4);
  disp.setTextColor(BLACK);
  disp.setCursor(150,150);
  disp.print("TWA");
  disp.setCursor(0,550);
  disp.setTextSize(9);
  disp.print((int)random(0, 360));
  disp.print('.');
  disp.udpate();
  delay(2000);
  disp.clear();
  disp.setTextSize(4);
  disp.setTextColor(BLACK);
  disp.setCursor(350,150);
  disp.print("TWS");
  disp.setCursor(0,550);
  disp.setTextSize(9);
  disp.print((float)random(0, 400)/10);
  disp.udpate();
  delay(2000);
}
