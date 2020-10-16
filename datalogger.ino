

/*

  FPS.pde
  
  >>> Before compiling: Please remove comment from the constructor of the 
  >>> connected graphics display (see below).
  
  Universal 8bit Graphics Library, https://github.com/olikraus/u8glib/
  
  Copyright (c) 2012, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  

  ST7920_192X32, SPI:    FPS: Box=7.6   @=9.8                iFPS: Box=11.4  @=14.7
  ST7920_192X32, 8Bit:   FPS: Box=6.2   @=7.5                iFPS: Box=9.3 @=11.2
  DOGM128 SW SPI:         FPS: Box=5.1   @=5.9  Pix=2.6               iFPS: Box=10.2 @=11.8 Pix=5.2
  DOGM128 HW SPI:         FPS: Box=5.5   @=6.3               iFPS: Box=11.0 @=12.6
  DOGXL160 SW SPI:         FPS: Box=1.7   @=1.9               iFPS: Box=6.9 @=7.7
  DOGXL160 HW SPI:         FPS: Box=1.8   @=2.1               
  
  NHD27OLED_BW, SW SPI: FPS: Box=3.0  @=3.7
  NHD27OLED_BW, HW SPI: FPS: Box=3.5  @=4.5
  NHD27OLED_2X_BW, SW SPI: FPS: Box=3.8  @=4.9
  NHD27OLED_2X_BW, HW SPI: FPS: Box=4.6  @=6.4
  
  30 Sep 2012
  NHD27OLED_BW, SW SPI: FPS: Clip=9.2 Box=3.9  @=4.4		NEW_CODE
  NHD27OLED_BW, SW SPI: FPS: Clip=9.2 Box=3.6  @=4.5
  NHD27OLED_BW, HW SPI: FPS: Clip=16.3 Box=4.7  @=5.6
  NHD27OLED_2X_BW, SW SPI: FPS: Clip=9.7 Box=4.5  @=5.8
  NHD27OLED_2X_BW, SW SPI: FPS: Clip=18.0 Box=5.8  @=7.9

  1 Oct 2012
  ST7920_192X32, 8Bit:   FPS: Box=7.2   @=10.0                
  DOGM128 SW SPI:         FPS: Box=5.2   @=6.6  Pix=2.6               
  DOGM128 HW SPI:         FPS: Clip=33.2 Box=5.5   @=7.1
  DOGXL160 SW SPI:         FPS: Box=1.7   @=2.0
  DOGXL160 HW SPI:         FPS: Box=1.8   @=2.2

  DOGXL160 GR SW SPI:         FPS: Box=1.1   @=1.3

  1 Mar 2013
  ST7920_192X32_1X, SPI:    FPS: Clip=10.3 Box=5.5  @=7.2 Pix=3.9
  ST7920_192X32_4X, SPI:    FPS: Clip=10.9 Box=6.7  @=8.8 Pix=7.4
  ST7920_192X32_1X, 8Bit:    FPS: Clip=14.2 Box=6.1  @=8.4 Pix=4.2
  ST7920_192X32_4X, 8Bit:    FPS: Clip=14.2 Box=7.8  @=10.7 Pix=8.7
  ST7920_192X32_1X, HW SPI:    FPS: Clip=14.2 Box=6.3  @=8.7 Pix=4.3
  ST7920_192X32_4X, HW SPI:    FPS: Clip=15.3 Box=8.0  @=11.2 Pix=9.0

  2 Jun 2013
  U8GLIB_DOGM128 SW SPI:		FPS: Clip=23.9 Box=4.5  @=6.6 Pix=2.1
  U8GLIB_DOGM128_2X SW SPI:	FPS: Clip=28.5 Box=6.6  @=9.7 Pix=3.9
  U8GLIB_DOGM128_2X HW SPI:	FPS: Clip=40.8 Box=7.1  @=10.8 Pix=4.1
  
  3 Jun 2013
  U8GLIB_ST7920_192X32_1X -Os	SW SPI	FPS: Clip=11.0 Box=5.4  @=7.1 Pix=3.9	Size=11828
  U8GLIB_ST7920_192X32_1X -O3	SW SPI	FPS: Clip=10.9 Box=5.6  @=7.5 Pix=4.0	Size=13800
  U8GLIB_ST7920_192X32_1X -Os	SW SPI	FPS: Clip=16.8 Box=6.7  @=9.6 Pix=4.5	Size=11858	(new seq data output)
  U8GLIB_ST7920_192X32_1X -Os	HW SPI	FPS: Clip=25.7 Box=7.5  @=11.3 Pix=4.8	(new seq data output)
  
  6 Jun 2013
  U8GLIB_DOGS102 u8g(13, 11, 10, 9);    STD SW SPI	FPS: Clip=9.5 Box=7.6  @=8.2 Pix=6.2	Size=15652
  U8GLIB_DOGS102 u8g(13, 11, 10, 9);    SW SPI	        FPS: Clip=19.1 Box=12.8  @=14.0 Pix=9.2	Size=15532


  12 Jun 2013
  SSD1351_128X128_332	SW SPI Clip=1.3 Box=0.7  @=0.9 Pix=0.4
  SSD1351_128X128_332	HW SPI Clip=3.6 Box=1.1  @=1.5 Pix=0.5

  24 Jun 2013
  Uno SSD1351_128X128_332				SW SPI Clip=1.4 Box=0.8  @=0.9 Pix=0.4
  
  Uno SSD1351_128X128_332					HW SPI Clip=4.4 Box=1.2  @=1.6 Pix=0.5
  Uno SSD1351_128X128_HICOLOR			HW SPI Clip=3.7 Box=0.8  @=1.0 Pix=0.3

  Mega2560 SSD1351_128X128_332			HW SPI Clip=4.4 Box=1.2  @=1.6 Pix=0.5
  Mega2560 SSD1351_128X128_4X_332			HW SPI Clip=4.6 Box=2.3  @=2.8 Pix=1.5
  Mega2560 SSD1351_128X128_HICOLOR		HW SPI Clip=3.6 Box=0.8  @=1.0 Pix=0.3
  Mega2560 SSD1351_128X128_4X_HICOLOR	HW SPI Clip=4.2 Box=1.7  @=2.1 Pix=1.0

  Due SSD1351_128X128_332					HW SPI Clip=24.6 Box=6.3  @=7.8 Pix=2.8
  Due SSD1351_128X128_4X_332 				HW SPI Clip=28.1 Box=13.0  @=15.1 Pix=8.5
  Due SSD1351_128X128_HICOLOR			HW SPI Clip=20.8 Box=3.4  @=4.5 Pix=1.4
  Due SSD1351_128X128_4X_HICOLOR			HW SPI Clip=26.3 Box=8.9  @=11.1 Pix=4.8

  Due SSD1351_128X128_4X_HICOLOR			SW SPI Clip=0.4 Box=0.4  @=0.4 Pix=0.4
  
  Due DOGS102 u8g(13, 11, 10, 9);    			SW SPI	        FPS: Clip=19.1 Box=13.1  @=14.3 Pix=9.4
  Due DOGS102 u8g(10, 9);    					HW SPI	        FPS: Clip=128.9 Box=30.7  @=40.6 Pix=15.4

  Due NHD27OLED_BW u8g(10, 9)				HW SPI		FPS: Clip=53.0 Box=19.6  @=23.8 Pix=10.6
  Due NHD27OLED_2X_BW u8g(10, 9)			HW SPI		FPS: Clip=57.0 Box=25.3  @=31.7 Pix=18.1
  Due NHD27OLED_GR u8g(10, 9)				HW SPI		FPS: Clip=34.1 Box=11.7  @=13.7 Pix=5.6
  Due NHD27OLED_2X_GR u8g(10, 9)			HW SPI		FPS: Clip=38.1 Box=15.5  @=20.0 Pix=8.8

В конструкторе класса указывается цифровой вход кнопки. А также четыре необязательных параметра:

--Таймаут для игнорирования дребезга контактов (По умолчанию 50 мс )
--Время длинного нажатия кнопки, мс. Если 0, то длинное нажатие не фиксируется. (По умолчанию отключено)
--Время удержания кнопки, после которого происходит автонажатие кнопки. Если 0, то не происходит. (По умолчанию отключено)
--Интервал срабатывания кнопки при автонажатии (По умолчанию 500 мс)
*/



#include <TinyGPS.h>
#include <SoftwareSerial.h>
#include "sav_button.h"
#include <Adafruit_MLX90614.h>
#include <SD.h>
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif



SButton button1(4,50,2000,0,0);
SButton button2(5,50,2000,0,0);
TinyGPS gps;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
File logFile;

unsigned long currentTime;
unsigned long loopTime;

unsigned long date, gpstime;
unsigned long g_speed;

String filename = "";
String path = "";
String dirname = "";

bool rec=false;

 int runMinutes=0;
  int runSeconds=0;
  int runDecSec=0;
  unsigned long StartTimer=0;
  unsigned long runMillis=0;
 
  
static void smartdelay(unsigned long ms);
static void print_float(float val, float invalid, int len, int prec);
static void print_int(unsigned long val, unsigned long invalid, int len);
static void print_date(TinyGPS &gps);
static void print_str(const char *str, int len);


int val_f,val_r,lapCount;
int i=1;
int pingPin = 7;//пин для выхода trig
int inPin = 6;//пин для выхода echo
long cm_tmp1=0,cm_tmp2=0;

 int IRpin = 15; 

long microsecondsToCentimeters(long microseconds)

{
//скорость звука 340 м/с или 29,412 микросекунд/см, а поскольку звук летит до помехи и обратно, делим результат на двое 

return microseconds / 2.9412 / 2;

}

//U8GLIB_ST7920_128X64_4X u8g(14, 15, 16);	// SPI Com: SCK = en = 18, MOSI = rw = 16, CS = di = 17
U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 12 /* A4 */ , /* data=*/ 11 /* A2 */, /* CS=*/ 10 /* A3 */, /* reset=*/8 );
//U8G2_ST7920_128X64_F_HW_SPI u8g2(U8G2_R0, /* CS=*/ 10, /* reset=*/ 8);
 float flat=0, flon=0;
   unsigned long age=0;

   int frt_t=0;
void wheel_temp(float flat, float flon, int frt_t) {
//  float flat, flon;
   unsigned long age;
//int drawtime, olddraw;
//olddraw=micros();
    u8g2.clearBuffer();
 
  val_r = analogRead(3);
   u8g2.setFont(u8g2_font_6x10_tf);
//    u8g2.setDefaultForegroundColor();
  u8g2.setCursor(3, 18);
  u8g2.print(frt_t);
  u8g2.setCursor(53, 18);
  u8g2.print(val_r);

  // graphic commands to redraw the complete screen should be placed here  
  u8g2.setFont(u8g2_font_6x10_tf);
  //u8g2.setFont(u8g_font_osb21);
  u8g2.drawStr( 0, 9, "FRONT");
  u8g2.drawStr( 50, 9, "REAR");

  
  u8g2.setCursor(3, 27);
  u8g2.print(flat, 6);
  //print_float(flat, TinyGPS::GPS_INVALID_F_ANGLE, 10, 6);
//  u8g2.setPrintPos(3, 36);
  //print_float(flon, TinyGPS::GPS_INVALID_F_ANGLE, 11, 6);
  u8g2.print(flon, 6);
//  u8g2.setPrintPos(3, 45);
  //print_float(gps.f_altitude(), TinyGPS::GPS_INVALID_F_ALTITUDE, 7, 2);
//  u8g2.print(gps.f_altitude(), 2);
//  u8g2.setPrintPos(43, 45);
//print_time(gps);
  
  u8g2.drawStr( 0, 54, "Speed:");
  u8g2.setCursor(47, 54);
  u8g2.print(gps.f_speed_kmph(), 2);
//  u8g2.setPrintPos(40, 54);
//  u8g2.drawStr( 71, 54, "Sat:");
//  u8g2.setPrintPos(97, 54);
//  print_int(gps.satellites(), TinyGPS::GPS_INVALID_SATELLITES, 5);
 
 

 
 u8g2.sendBuffer();
// drawtime=olddraw-micros();
//  Serial.println(drawtime);
  
}

void suspension(int cm,long duration, bool rec) { 
   u8g2.clearBuffer();
   u8g2.setFont(u8g_font_6x10);
//    u8g2.setDefaultForegroundColor();
  u8g2.setCursor(2, 9);
  u8g2.print("Distance sonic:");
//если помех не обнаружено сообщаем что расстояние более 1.5 метра
if(duration>15000){
 u8g2.setCursor(62, 9);
u8g2.print(">1.5m");}

else { u8g2.print(cm); //иначе выводим расстояние до помехи в сантиметрах 

//delay(10);
} 
  
//    u8g2.setPrintPos(2, 27);
//  u8g2.print(rec);
  u8g2.sendBuffer();
}

void lap_timer(int lapCount, int runMinutes, int runSeconds, int runDecSec) {
//  int drawtime, olddraw;
//olddraw=micros();
u8g2.clearBuffer();
u8g2.setFontMode(1);
u8g2.setDrawColor(1);
    u8g2.drawBox(0,0,128,9);
    u8g2.setFont(u8g2_font_haxrcorp4089_tr);
//    u8g2.setDefaultBackgroundColor();
    u8g2.setCursor(50, 8);
    u8g2.setDrawColor(2);
    u8g2.print("LAP ");
   u8g2.print(lapCount);
 u8g2.setCursor(8, 48);
//   u8g2.setDefaultForegroundColor();
   u8g2.setFont(u8g2_font_fub30_tn);
  
 static char str[12];
 sprintf(str, "%01d:%02d:%01d", runMinutes, runSeconds, (runDecSec/10));
 u8g2.print(str);
// u8g2.setDefaultForegroundColor();
   u8g2.drawBox(0,55,128,64);
     u8g2.setFont(u8g2_font_haxrcorp4089_tr);
//     u8g2.setDefaultBackgroundColor();
   u8g2.drawStr( 5, 63, "BEST:");

 u8g2.sendBuffer();
// drawtime=olddraw-micros();
//  Serial.println(drawtime);
}
void lap() {
  lap_timer(lapCount, runMinutes, runSeconds, runDecSec); 
  StartTimer=millis();
  lapCount++; 
    
}

void setup(void) {
    u8g2.begin();
  // flip screen, if required
  // u8g2.setRot180();
  
  // set SPI backup if required
  //u8g2.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
 /* if ( u8g2.getMode() == U8G_MODE_R3G3B2 ) {
    u8g2.setColorIndex(255);     // white
  }
  else if ( u8g2.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g2.setColorIndex(3);         // max intensity
  }
  else if ( u8g2.getMode() == U8G_MODE_BW ) {
    u8g2.setColorIndex(1);         // pixel on
  }
  else if ( u8g2.getMode() == U8G_MODE_HICOLOR ) {
    u8g2.setHiColorByRGB(255,255,255);
  }*/
  attachInterrupt(0, lap, RISING);

  pinMode(inPin, INPUT);
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
   Serial.begin(57600);
   Serial1.begin(57600);

    button1.begin();
    button2.begin();

    mlx.begin();  
 /* 
   // Serial.println("LAT | LON | Speed | Sat | FR_temp | RR_temp | Lap | FR_distance | RR_ distance | GPS_Time" );
     if (!SD.begin(53)) {
  //  Serial.print("Card failed, or not present");
    // don't do anything more:
    while (1);
  } else {
    //Serial.print("SD Card OK!");
   
        }
        */
currentTime = millis();
loopTime = currentTime; 
u8g2.clearDisplay(); 
}
void loop(void) {

  String dataString = "";
  String dataStringPort = "";
 
////////Timing

if (rec == false) { runMillis=0; } else {
   runMillis= millis()-StartTimer; }
/*
  unsigned long allSeconds=runMillis/1000;
  unsigned long alldecSeconds=runMillis/100;
//  unsigned long allSeconds=(millis()-StartTimer)/1000;
//  unsigned long alldecSeconds=(millis()-StartTimer)/100;
  int runHours= allSeconds/3600;
  int secsRemaining=allSeconds%36000;
  int decsecsRemaining=alldecSeconds%3600;
  int runMinutes=secsRemaining/60;
  int runSeconds=secsRemaining%60;
  int runDecSec= decsecsRemaining%10;
*/
  unsigned long allSeconds=runMillis/1000;
  unsigned long alldecSeconds=runMillis/1;
//  unsigned long allSeconds=(millis()-StartTimer)/1000;
//  unsigned long alldecSeconds=(millis()-StartTimer)/100;
  int runHours= allSeconds/3600;
  int secsRemaining=allSeconds%36000;
  int decsecsRemaining=alldecSeconds%360000;
  int runMinutes=secsRemaining/60;
  int runSeconds=secsRemaining%60;
  int runDecSec= decsecsRemaining%1000;



if (button2.Loop() == SB_CLICK) {
  rec=!rec;
  StartTimer=millis();
  lapCount=0;
  if (rec) {
   
     dirname = "/";
     dirname += date;
     dirname += "/";
     if (!SD.exists(dirname)) {
      SD.mkdir(dirname); 
     }
     filename = gpstime;
     filename += ".csv";
     path = dirname;
     path += filename;
    
     logFile = SD.open(path, FILE_WRITE);
  /*    if (logFile) {
        Serial.println("open file done.");
      } else {
        Serial.println("error open file.");
      }
      */
  } else {
    logFile.close();
  }
  }
///////End Timing
///////Distance Ultrasonic
long duration, cm,tmp1;//объявляем переменные //посылаем датчику сигнал начала замера (высокий уровень на 10 мкс)
digitalWrite(pingPin, HIGH);
delayMicroseconds(10);
digitalWrite(pingPin, LOW); //делаем паузу чтобы датчик успел среагировать
delayMicroseconds(500); //засекаем время в микросекундах (500) 
tmp1=micros(); //ждем пока сигнал на выходе echo не станет низкий
while(digitalRead(inPin)==HIGH)
{
//если долго нет ответа от датчика, значит препятствий в зоне видимости нет, выходим по таймауту 
if(micros()-tmp1 > 15000) {duration=16000; break;}
} 
//вычисляем время "полета" ультразвукового сигнала
duration=micros()-tmp1;
cm = microsecondsToCentimeters(duration);//переводим время в сантиметры
cm=(cm+cm_tmp1+cm_tmp2)/3;
cm_tmp2=cm_tmp1;
cm_tmp1=cm;
////////End Distance Ultrasonic
//////Distance IR
//GP2Y0A02YK0F 
//  float volts = analogRead(IRpin)*0.0048828125;   // считываем значение сенсора и переводим в напряжение
//  float ir_cm = 65*pow(volts, -1.10);
//  int ir_mm = int(ir_cm*10);
////////Temperature
frt_t = mlx.readObjectTempC();
////////End Temperature

   
  // picture loop
// currentTime = millis();                           // считываем время, прошедшее с момента запуска программы
 
//u8g2.firstPage();  
  
//  do {
//if (!rec) {
 /*  switch (i)
    { case 1: wheel_temp(flat, flon, frt_t);
      break;
      case 2: suspension(cm, duration, rec);
      break;
      case 3: lap_timer(lapCount, runMinutes, runSeconds, runDecSec);    
      break;
    }
    */
//}
//  } 
//  while( u8g2.nextPage() );
 
//  loopTime = currentTime;
  
  
  // rebuild the picture after some delay



if (button1.Loop() == SB_CLICK) {
       if (i<3) {
                i=i+1;
              }
        else {
                i=1; 
            }
    }

/*Serial.println("   LAT     |      LON    | Speed | Sat | FR | RR_temp | Lap | FR_distance | RR_ distance | GPS_Time" );
Serial.print(flat);
Serial.print(" | ");
Serial.print(flon);
Serial.print(" | ");
print_float_ser(gps.f_speed_kmph(), TinyGPS::GPS_INVALID_F_SPEED, 6, 2);
Serial.print("|  ");
Serial.print(gps.satellites());
Serial.print("  | ");
Serial.print(frt_t);
Serial.print(" | ");
Serial.print(val_r);
Serial.print(" | ");
Serial.print(cm);
Serial.print(" | ");
Serial.print(cm);
Serial.print(" | ");
Serial.print(date);
Serial.println(gpstime);
*/
//Serial.println(dataString);
//Serial.println(filename);
   gps.f_get_position(&flat, &flon, &age);
 gps.get_datetime(&date, &gpstime, &age);
// if (logFile) {   
dataString = String(flat, 6);
dataString += "|";
dataString += String(flon, 6);
dataString += "|";
//dataString += date;
dataString += String(gps.f_speed_kmph(), 2);
dataString += "|";
dataString += gps.satellites();
dataString += "|";
dataString += frt_t;
dataString += "|";
dataString += cm;
dataString += "|";
dataString += lapCount;
dataString += "|";
//dataString += runMinutes;
//dataString += ":";
//dataString += runSeconds;
//dataString += ":";
static char strtime[12];
 sprintf(strtime, "%01d:%02d:%03d", runMinutes, runSeconds, runDecSec);
 dataString += strtime;
//dataString += runDecSec;
dataString += "|";
dataString += gpstime;
logFile.println(dataString);
dataStringPort = frt_t;
dataStringPort += "|";
dataStringPort += cm;
dataStringPort += "|";
dataStringPort += lapCount;
dataStringPort += "|";
sprintf(strtime, "%01d|%02d|%01d", runMinutes, runSeconds, runDecSec);
dataStringPort += strtime;

Serial.println(dataStringPort);
 //}
smartdelay(0);
}
/*void blink(){
  if (i<3) {
      i=i+1;
      
  }
  else {
    i=1;
   
  } 
        rec = !rec;
}
*/



static void smartdelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (Serial1.available())
      gps.encode(Serial1.read());
  } while (millis() - start < ms);
}

static void print_float(float val, float invalid, int len, int prec)
{
  if (val == invalid)
  {
    while (len-- > 1)
      u8g2.print('*');
    u8g2.print(' ');
  }
  else
  {
    u8g2.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      u8g2.print(' ');
  }
  smartdelay(0);
}
/*
static void print_float_ser(float val, float invalid, int len, int prec)
{
  if (val == invalid)
  {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  }
  else
  {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      Serial.print(' ');
  }
  smartdelay(0);
}
*/
static void print_int(unsigned long val, unsigned long invalid, int len)
{
  char sz[32];
  if (val == invalid)
    strcpy(sz, "*******");
  else
    sprintf(sz, "%ld", val);
  sz[len] = 0;
  for (int i=strlen(sz); i<len; ++i)
    sz[i] = ' ';
  if (len > 0) 
    sz[len-1] = ' ';
  u8g2.print(sz);
  smartdelay(0);
}

static void print_date(TinyGPS &gps)
{
  int year;
  byte month, day, hour, minute, second, hundredths;
  unsigned long age;
  gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &age);
  if (age == TinyGPS::GPS_INVALID_AGE)
    u8g2.print("********** ******** ");
  else
  {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d %02d:%02d:%02d ",
        month, day, year, hour, minute, second);
    u8g2.print(sz);
  }
  print_int(age, TinyGPS::GPS_INVALID_AGE, 5);
  smartdelay(0);
}
static void print_time(TinyGPS &gps)
{
  int year;
  byte month, day, hour, minute, second, hundredths;
  unsigned long age;
  gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &age);
  if (age == TinyGPS::GPS_INVALID_AGE)
    u8g2.print("********** ******** ");
  else
  {
    char sz[32];
    sprintf(sz, "%02d:%02d:%02d ",
         hour, minute, second);
    u8g2.print(sz);
  }
  print_int(age, TinyGPS::GPS_INVALID_AGE, 5);
  smartdelay(0);
}
static void print_str(const char *str, int len)
{
  int slen = strlen(str);
  for (int i=0; i<len; ++i)
    u8g2.print(i<slen ? str[i] : ' ');
  smartdelay(0);
}

