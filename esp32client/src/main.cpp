#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);

void setup() {
    Serial.begin(115200);

    u8g2.begin();

    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(0, 24, "Hello");
    u8g2.sendBuffer();

    Serial.println("Done drawing");
}

void loop() {
}
