//temperature sensor part starts
#include <DallasTemperature.h>
#include <OneWire.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
//temperature sensor part ends


//buzzer part
int buzzer = 7 ;
//buzzer part ends

                
//Keypad part starts
#include <Keypad.h>
const byte ROWS = 1;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','4'}
};
byte rowPins[ROWS] = {A4};
byte colPins[COLS] = {A3,A2,A1,A0};
Keypad kepad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
//Keypad part ends

//servo part starts
#include<Servo.h>
Servo servoobj1;
//Servo servoobj2;
Servo servoobj3;
int pin1 = 3;
//int pin2 = 5;
int pin3 = 6;
int Servodelay = 25;
//servo part ends

//LCD part starts
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
//LCD part ends

void setup()
{
 Serial.begin(9600); 
  lcd.begin(16, 2);                         //initializing LCD..
  sensors.begin();
   analogWrite(A0, 1024);
   analogWrite(A1, 1024);
   analogWrite(A2, 1024);
   analogWrite(A3, 1024);
   analogWrite(A4, 1024);
   servoobj1.attach(pin1);
  // servoobj2.attach(pin2);
   servoobj3.attach(pin3);
   pinMode(buzzer,OUTPUT);
  
}


void loop()
{
  char key = kepad.getKey();
  //int n=2;
  //Serial.print(n);
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("1.tea 2.Coffee");
   // delay(500);
    lcd.setCursor(0,1);
    lcd.print("3.kheer 4.tadka");
   // delay(500);
   //Serial.println(n+1);
    Serial.println(key);
   if (key){
Serial.println(key);
Serial.println("test1");
      if(key=='1'){
        tea();
      }
       if(key=='2'){
        coffee();
      }
       if(key=='3'){
        kheer();
      }
       if(key=='4'){ 
        tadka();
      }
   }
} 

//functions which are being called in void loop


void tea(){
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Preparing");
     delay(500);
     lcd.setCursor(0,1);
     lcd.print("Ur dish");
      delay(500);
Serial.println("test2");
    for(int pos3=20; pos3<=150  ;pos3++){                     //to be filled
       servoobj3.write(pos3);
       delay(40);
    }
        int n=1;
Serial.println("test3");
        while(n){
         sensors.requestTemperatures();
         float temp = sensors.getTempCByIndex(0);
Serial.println(temp);
            if(temp>=23){
            n=0;
             for(int pos33=150;pos33>=40;pos33--){
             servoobj3.write(pos33);
             delay(60);
             }
              for(int pos1=15;pos1<=120;pos1++){
              servoobj1.write(pos1);
             // servoobj2.write(pos1);
              delay(40);
               }
          }
              else{
                n=1;
              }
          }
          Serial.println("test4");
         delay(8000);
         digitalWrite(buzzer,HIGH);
} 
void coffee(){
     lcd.setCursor(0,0);
     lcd.print("Preparng");
     lcd.setCursor(0,0);
     lcd.print("Ur dish");
     for(int pos3=15  ; pos3<=150  ;pos3++){                     //to be filled
       servoobj3.write(pos3);
       delay(40);
    }
        int n=1;
        while(n){
         sensors.requestTemperatures();
          float temp = sensors.getTempCByIndex(0);
            if(temp>=75){
            n=0;
          for(int pos33=150;pos33>=15;pos33--){
               servoobj3.write(pos33);
               delay(60);
          }
              for(int pos1=15;pos1<=120;pos1++){
              servoobj1.write(pos1);
              //servoobj2.write(pos1);
              delay(40);
                   if(pos1==120){
                   delay(8000);
                   for(int pos11=120;pos11>=15;pos11--){
                   servoobj1.write(pos11);
                   //servoobj2.write(pos11);
                   delay(40);
                  }
            }
        }
              }
              else{
                n=1;
              }
          }
           delay(180000);
         digitalWrite(buzzer,HIGH);
}
void kheer(){
     lcd.setCursor(0,0);
     lcd.print("Preparng");
     lcd.setCursor(0,0);
     lcd.print("Ur dish?");
    for(int pos3=15 ; pos3<=150 ;pos3++){                     //to be filled
       servoobj3.write(pos3);
       delay(40);
    }
        int n=1;
        while(n){
         sensors.requestTemperatures();
         float temp = sensors.getTempCByIndex(0);
            if(temp>=75){
            n=0;
          for(int pos33=150; pos33>=15 ;pos33--){
               servoobj3.write(pos33);
               delay(60);
          }
              for(int pos1=15; pos1<=120 ;pos1++){
              servoobj1.write(pos1);
              //servoobj2.write(pos1);
              delay(40);
                   if(pos1==120){
                   delay(8000);
                   for(int pos11=120;pos11>=15;pos11--){
                   servoobj1.write(pos11);
                  // servoobj2.write(pos11);
                   delay(40);
                  }
            }
        }
              }
              else{
                n=1;
              }
          }
           delay(180000);
         digitalWrite(buzzer,HIGH);
} 
void tadka(){
     lcd.setCursor(0,0);
     lcd.print("Preparng");
     lcd.setCursor(0,0);
     lcd.print("Ur dish");
    for(int pos3= 15 ; pos3>=150 ;pos3++){                     //to be filled
       servoobj3.write(pos3);
       delay(40);
    }
        int n=1;
        while(n){
         sensors.requestTemperatures();
         float temp = sensors.getTempCByIndex(0);
            if(temp>=75){
            n=0;
          for(int pos33=150;pos33>=15;pos33--){
               servoobj3.write(pos33);
               delay(60);
          }
              for(int pos1=15;120;pos1++){
              servoobj1.write(pos1);
             // servoobj2.write(pos1);
              delay(40);
                   if(pos1==120){
                   delay(8000);
                   for(int pos11=120;15;pos11--){
                   servoobj1.write(pos11);
                 //  servoobj2.write(pos11);
                   delay(40);
                  }
            }
        }
              }
              else{
                n=1;
              }
          }
           delay(180000);
         digitalWrite(buzzer,HIGH);
}
