#include <M5StickCPlus.h>
#define LGFX_AUTODETECT
#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include <LGFX_AUTODETECT.hpp> 
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = 9; // M5StickC内蔵LED
static LGFX lcd;
IRsend irsend(kIrLed,true);  // Set the GPIO to be used to sending the message.GPIO inv.

void setup() {
  irsend.begin();
  M5.begin();             // Init M5StickCPlus.
  lcd.init();
  lcd.setFont(&fonts::FreeMono9pt7b);
  lcd.setRotation(0);  // Rotate the screen.
  lcd.setCursor(0, 0);  //Cursor set
  lcd.print("Descrete\r\ncode sender");

}

void loop() {
    M5.update();  // Read the press state of the key.

    if (M5.BtnA.wasPressed()) {  // If the button A is pressed.
        lcd.setCursor(0, 48);
        lcd.print("send");
        irsend.sendSony(0xf50, 12, 2);  //  Power Off (discrete),12 bits,2repeats
    }
    if (M5.BtnA.wasReleased()) {  // If the button A is pressed.
        lcd.setCursor(0, 48);
        lcd.print("    ");
    }
  delay(200);
}
