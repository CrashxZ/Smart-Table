#include <ESP8266WiFi.h>
#include <LiquidCrystal.h>
#include<Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>// must be included here so that Arduino library object file references work
#include <RtcDS1307.h>



#define countof(a) (sizeof(a) / sizeof(a[0]))
#define I2C_ADDR          0x27        //Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN      3
#define En_pin             2
#define Rw_pin             1
#define Rs_pin             0
#define D4_pin             4
#define D5_pin             5
#define D6_pin             6
#define D7_pin             7

// Wi-Fi Settings
const char* ssid = "Crash"; // your wireless network name (SSID)
const char* password = "bhooljao"; // your Wi-Fi network password

WiFiClient client;



// ThingSpeak Settings
const int channelID = 351468;
String writeAPIKey = "20TOLUXU2P6JG8BN"; // write API key for your ThingSpeak Channel
const char* server = "api.thingspeak.com";


//Initialise the LCD
LiquidCrystal_I2C      lcd(I2C_ADDR, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);
RtcDS1307<TwoWire> Rtc(Wire);


int pir = 14;

int light = 12;
void lcdwrite(char l1[16],String l2)
{
  lcd.setCursor(0,0);
  lcd.print(l1);
  lcd.setCursor(0,2);
  lcd.print(l2);
}

void postData(char checkupdate[2])
{
  int c = atoi(checkupdate);
  if (client.connect(server, 80)&& (c % 20 == 0))
    {


    int value1 = analogRead(pir);
    value1=value1>0?1:0;

    // Construct API request body
    String body = "field1=";
           body += String(value1);



    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + writeAPIKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(body.length());
    client.print("\n\n");
    client.print(body);
    client.print("\n\n");
    client.stop();

  }
}


void printDateTime(const RtcDateTime& dt)
{

    char datestring[20];

    snprintf_P(datestring,
            countof(datestring),
            PSTR("      %02u:%02u"),
            dt.Hour(),
            dt.Minute());
    Serial.print(datestring);


    lcdwrite(datestring,"");
    char timevar[2]={datestring[12],datestring[13]};
    Serial.println(timevar);
    postData(timevar);
}

void setTime()
{

    //RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    RtcDateTime compiled = RtcDateTime("2017/11/05","06:12:00");
    //printDateTime(compiled);
    delay(10000);

    if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        Rtc.SetIsRunning(true);
    }
    Rtc.SetDateTime(compiled);

   lcdwrite("Setting","");
   delay(3000);
    // RtcDateTime now = Rtc.GetDateTime();
    // if (now < compiled)
    // {
    //     Serial.println("RTC is older than compile time!  (Updating DateTime)");
    //     Rtc.SetDateTime(compiled);
    // }
    // else if (now > compiled)
    // {
    //     Serial.println("RTC is newer than compile time. (this is expected)");
    // }
    // else if (now == compiled)
    // {
    //     Serial.println("RTC is the same as compile time! (not expected but all is fine)");
    // }

    //Rtc.SetSquareWavePin(DS1307SquareWaveOut_Low);
}
void setup ()
{
    Serial.begin(57600);
    WiFi.begin(ssid, password);

    lcd.begin (16,2);
    lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
    lcd.setBacklight(HIGH);
    Rtc.Begin();
    lcd.setCursor(0,0);
    //pinMode(pir,INPUT);
    pinMode(light,OUTPUT);





    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
    }
    lcdwrite("","Connected");
    delay(3000);
    setTime();
    lcd.clear();
    lcdwrite("Hello Human!", "Welcome ! :)");
    delay(3000);
    lcd.clear();

}

void loop ()
{
    RtcDateTime now = Rtc.GetDateTime();
    printDateTime(now);
    Serial.println();
    //digitalWrite(light,HIGH);

    int x = analogRead(pir);
    if(x==1023)
    {
      digitalWrite(light,HIGH);
      lcdwrite("","Status: Engaged");

    }
    else
    {
      lcdwrite("","                ");
      digitalWrite(light,LOW);
      lcdwrite("","   Available");

    }
    Serial.println(x);
    //delay(1000);
}
