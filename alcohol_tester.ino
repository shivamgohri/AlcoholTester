#include <Adafruit_GFX.h>
#if defined(_GFXFONT_H_)           //are we using the new library?
#include <Fonts/FreeSans9pt7b.h>
#define ADJ_BASELINE 11            //new fonts setCursor to bottom of letter
#else
#define ADJ_BASELINE 0             //legacy setCursor to top of letter
#endif
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;

#define TS_MINX 125
#define TS_MINY 85
#define TS_MAXX 965
#define TS_MAXY 905

//colors defined
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GREY    0x7BEF

#include <stdio.h>

uint16_t ID;

uint8_t conv2d(const char* p)
{
  uint8_t v = 0;
  if ('0' <= *p && *p <= '9') v = *p - '0';
  return 10 * v + *++p - '0';
}

void setup(void)
{
  Serial.begin(9600);
  
  tft.reset();
  ID = tft.readID();
  Serial.print("TFT ID = 0x");
  Serial.println(ID, HEX);  
  tft.begin(ID);
  
  tft.setRotation(0);
  tft.fillScreen(BLACK);
}

void loop(void)
{
  tft.fillScreen(BLACK);
  
  tft.drawLine(30,120,210,120,WHITE);
  tft.drawLine(30,200,210,200,WHITE);
  tft.drawLine(30,120,30,200,WHITE);
  tft.drawLine(210,120,210,200,WHITE);

  tft.setCursor(180,20);
  tft.setTextSize(1.5);
  tft.print(millis()/1000);
  tft.print(" sec");
  
  tft.setCursor(30,100);
  tft.setTextSize(2);
  tft.setTextColor(RED);
  tft.print("Alcohol Tester");
  delay(100000);


}
