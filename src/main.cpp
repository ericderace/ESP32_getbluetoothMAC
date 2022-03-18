// ESP32_getbluetoothMAC
//
// Get Bluetooth MAC address, print it to serial and on OLED display
// Board: Heltec WiFi Kit 32
//
// (c) Eric Hebert 2022
//

#include <Arduino.h>
#include <Ps3Controller.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, 16, 15, 4);

void setup()
{
  Serial.begin(115200);
  u8g2.begin();

  Ps3.begin();
  String address = Ps3.getAddress();
  Serial.print("Bluetooth MAC: ");
  Serial.println(address);
  u8g2.clearBuffer();                  
  u8g2.setFont(u8g2_font_6x13_mf);  
  u8g2.drawStr(0, 10, "Bluetooth MAC:");
  u8g2.drawStr(1, 25, address.c_str()); 
  u8g2.sendBuffer();
}

void loop()
{
}