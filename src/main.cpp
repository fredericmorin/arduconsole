
#include "Arduino.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306.h"
#include "Console.hpp"
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
#define OLED_DC     9
#define OLED_CS     10
#define OLED_RESET  8
Console console(OLED_DC, OLED_RESET, OLED_CS);

void setup()
{
  console.begin(SSD1306_SWITCHCAPVCC);
  console.display();

  printf("Console ready\n");

  Serial.begin(115200);
}

void loop()
{
  int16_t c = Serial.read();
  if (c != -1) {
    console.console_put(c);
  }
}
