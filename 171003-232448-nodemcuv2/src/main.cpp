// #include <Arduino.h>
// #include <LiquidCrystal.h>
// #include<Wire.h>
// #include <LCD.h>
// #include <LiquidCrystal_I2C.h>
// #include <RtcDS1307.h>
//
// #define countof(a) (sizeof(a) / sizeof(a[0]))
//
// #define I2C_ADDR          0x27        //Define I2C Address where the PCF8574A is
// #define BACKLIGHT_PIN      3
// #define En_pin             2
// #define Rw_pin             1
// #define Rs_pin             0
// #define D4_pin             4
// #define D5_pin             5
// #define D6_pin             6
// #define D7_pin             7
//
// //Initialise the LCD
// LiquidCrystal_I2C      lcd(I2C_ADDR, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
// RtcDS1307<TwoWire> Rtc(Wire);
//
// //Pin Definition
// int buzz = 7;
//
// void printDateTime(const RtcDateTime& dt)
// {
//     char datestring[20];
//
//     snprintf_P(datestring,
//             countof(datestring),
//             PSTR("%02u/%02u/%02u %02u:%02u:%02u"),
//             dt.Month(),
//             dt.Day(),
//             dt.Year(),
//             dt.Hour(),
//             dt.Minute(),
//             dt.Second() );
//     Serial.print(datestring);
// }
//
// // void displaytime(String time)
// // {
// //   lcd.setCursor(0,0);
// //   lcd.print(time);
// // }
//
// void buzzer()
// {
//   for(int i =0;i<5;i++)
//   {
//     digitalWrite(buzz,HIGH);
//     delay(100);
//     digitalWrite(buzz,LOW);
//     delay(100);
//     digitalWrite(buzz,HIGH);
//     delay(100);
//     digitalWrite(buzz,LOW);
//     delay(500);
//   }
// }
// void setup ()
// {
//   Rtc.Begin();
//
//
//   pinMode(7,OUTPUT);
//   Serial.begin(57600);
//
//   //LCD
//
//   //Define the LCD as 16 column by 2 rows
//     lcd.begin (16,2);
//
//     //Switch on the backlight
//     lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
//     lcd.setBacklight(HIGH);
//
//     //goto first column (column 0) and first line (Line 0)
//
// }
//
//
// void loop () {
//     RtcDateTime now = Rtc.GetDateTime();
//
//     printDateTime(now);
//     Serial.println();
//     Serial.println();
//     lcd.setCursor(0,0);
//     lcd.print("Hello");
//     delay(1000);
// }
