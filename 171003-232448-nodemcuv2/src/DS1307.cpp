// #include <LiquidCrystal.h>
// #include<Wire.h>
// #include <LCD.h>
// #include <LiquidCrystal_I2C.h>// must be included here so that Arduino library object file references work
// #include <RtcDS1307.h>
//
//
// #define countof(a) (sizeof(a) / sizeof(a[0]))
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
//
// int pir = 14;
//
// int light = 2;
// void lcddate(char l1[16],char l2[16])
// {
//   lcd.setCursor(0,0);
//   lcd.print(l1);
//   lcd.setCursor(0,2);
//   lcd.print(l2);
// }
//
// void printDateTime(const RtcDateTime& dt)
// {
//     char datestring[20];
//
//     snprintf_P(datestring,
//             countof(datestring),
//             PSTR("%02u/%02u %02u:%02u:%02u"),
//             dt.Month(),
//             dt.Day(),
//             dt.Hour(),
//             dt.Minute(),
//             dt.Second() );
//     Serial.print(datestring);
//
//
//     lcddate(datestring,"");
// }
//
//
// void setup ()
// {
//     Serial.begin(57600);
//
//     lcd.begin (16,2);
//     lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
//     lcd.setBacklight(HIGH);
//     Rtc.Begin();
//     lcd.setCursor(0,0);
//     //pinMode(pir,INPUT);
//     pinMode(light,OUTPUT);
// }
//
// void loop ()
// {
//     RtcDateTime now = Rtc.GetDateTime();
//     printDateTime(now);
//     Serial.println();
//
//     int x = analogRead(pir);
//
//     if(x!=0)
//     {
//       digitalWrite(light,HIGH);
//     }
//     Serial.println(x);
//     delay(1000);
// }
