#include<SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int sensorPin = A0; //pin yg di gunakan

int sensorValue = 0;

int led = 3; // pin led yg di gunakan
int led2 = 4; // pin led yg di gunakan

int buzzer = 7; // pin buzzer

void setup(){
  
   Serial.begin(9600);
   pinMode(led, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(buzzer, OUTPUT);
   lcd.begin ();  // Set lcd 
   lcd.backlight();
   lcd.setCursor(5,0);
   lcd.print("IOT");
   lcd.setCursor(3,1);
   lcd.print("BISMILLAH");
   delay(5000);
   lcd.clear();
   
   lcd.setCursor(0, 0);
   lcd.print("RUANGAN");
   
   lcd.setCursor(0, 1);
   lcd.print("AMAN");
   lcd.clear();
  
 
  }

void loop()
{
  Serial.println("pembacaan sensor api");

  sensorValue = analogRead(sensorPin);

  Serial.println(sensorValue);

  if (sensorValue < 100)
  {
    lcd.setCursor(0, 0);
    lcd.print("   TERDETEKSI");
    lcd.setCursor(0, 1);
    lcd.print("     API!!! ");
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(1000);
    lcd.clear();
    }
  lcd.setCursor(0, 0);
  lcd.print("     RUANGAN");
  lcd.setCursor(0, 1);
  lcd.print("      AMAN");
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(buzzer, LOW);
  delay(sensorValue);
  
  }
