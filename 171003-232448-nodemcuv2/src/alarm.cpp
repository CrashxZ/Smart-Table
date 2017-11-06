// #include <Arduino.h>
// #include <Wire.h>
// #include "RTClib.h"
//
// RTC_DS1307 rtc;
//
// char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//
//
// void buzzer()
// {
//   for(int i =0;i<5;i++)
//   {
//     digitalWrite(7,HIGH);
//     delay(100);
//     digitalWrite(7,LOW);
//     delay(100);
//     digitalWrite(7,HIGH);
//     delay(100);
//     digitalWrite(7,LOW);
//     delay(500);
//   }
// }
// void setup () {
//   //while (!Serial); // for Leonardo/Micro/Zero
//   pinMode(7,OUTPUT);
//   Serial.begin(9600);
//   if (! rtc.begin()) {
//     Serial.println("Couldn't find RTC");
//     while (1);
//   }
//
//   if (! rtc.isrunning()) {
//     Serial.println("RTC is NOT running!");
//     //following line sets the RTC to the date & time this sketch was compiled
//     rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
//     //This line sets the RTC with an explicit date & time, for example to set
//   //  January 21, 2014 at 3am you would call:
//   //  rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
//   }
// }
//
// void loop () {
//     DateTime now = rtc.now();
//     Serial.print(now.year(), DEC);
//     Serial.print('/');
//     Serial.print(now.month(), DEC);
//     Serial.print('/');
//     Serial.print(now.day(), DEC);
//     Serial.print(" (");
//     Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
//     Serial.print(") ");
//     Serial.print(now.hour(), DEC);
//     Serial.print(':');
//     Serial.print(now.minute(), DEC);
//     Serial.print(':');
//     int val = now.second();
//     Serial.print(val);
//     Serial.println();
//     //val = (val/16*10) + (val%16);
//     if(val==0)
//     {
//       buzzer();
//     }
//
// //    Serial.print(" since midnight 1/1/1970 = ");
// //    Serial.print(now.unixtime());
// //    Serial.print("s = ");
// //    Serial.print(now.unixtime() / 86400L);
// //    Serial.println("d");
//
//
//     Serial.println();
//     delay(1000);
// }
