#include <LiquidCrystal.h>
#include <Servo.h>
#include <SPI.h>
#include <RFID.h>
RFID rfid(53, 49);
const int rled = 10;
const int gled = 9 ;
const int bled = 8 ;
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
Servo ag90;
Servo ag901;
void setup() {
  lcd.begin(16, 2);
  ag901.attach(13);
  ag90.attach(3);
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
  pinMode(2, OUTPUT);
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(bled, OUTPUT);
}
//Rfid seri kart numarasını buraya gir
byte normal[2][5] = {{0x88, 0x4, 0x66, 0x97, 0x7D}, {0x88, 0x4, 0x6A, 0x97, 0x71}};
byte lpg[2][5] = {{0x88, 0x4, 0x6E, 0x97, 0x75}, {0x88, 0x4, 0x85, 0x96, 0x9F}};
byte calinti[2][5] = {{0x88, 0x4, 0x81, 0x96, 0x9B}, {0x88, 0x4, 0x72, 0x97, 0x69}};
byte korona[2][5] = {{0x88, 0x4, 0x79, 0x96, 0x63}, {0x88, 0x4, 0x7D, 0x96, 0x67}};
void loop() {
  ag901.write(0);
  boolean gecerlikart = true;
  if (rfid.isCard())
  {
    if (rfid.readCardSerial())
    {

      Serial.print("Kart ID: ");
      for (int i = 0; i < 5; i++)
      {
        Serial.println(rfid.serNum[i], HEX);
      }



      for (int i = 0; i < 5; i++)
      {
        if (rfid.serNum[i] == normal[0][i] || rfid.serNum[i] == normal[1][i])
        {
          gecerlikart = true;
        }
        else
        {
          gecerlikart = false;
        }
      }


      if (gecerlikart == true)
      {
        Serial.println("Normal");
        lcd.print("normal arac");
        ag90.write(0);
        digitalWrite(gled, HIGH);
        digitalWrite(2, HIGH);
        delay(1000);
        digitalWrite(2, LOW);
        delay(4000);
        digitalWrite(gled, LOW);
        ag90.write(90);
        lcd.clear();
      }
      rfid.halt();
    }



    for (int i = 0; i < 5; i++)
    {
      if (rfid.serNum[i] == lpg[0][i] || rfid.serNum[i] == lpg[1][i])
      {
        gecerlikart = true;
      }
      else
      {
        gecerlikart = false;
      }
    }


    if (gecerlikart == true)
    {
      Serial.println("lpg");


      lcd.print("lpgli arac");
      digitalWrite(rled, HIGH);
      digitalWrite(2, HIGH);
      delay(1000);
      digitalWrite(2, LOW);
      delay(1000);
      digitalWrite(2, HIGH);
      delay(1000);
      digitalWrite(2, LOW);
      delay(1000);
      digitalWrite(2, HIGH);
      delay(1000);
      digitalWrite(2, LOW);
      digitalWrite(rled, LOW);
      lcd.clear();
    }


    rfid.halt();


    for (int i = 0; i < 5; i++)
    {
      if (rfid.serNum[i] == calinti[0][i] || rfid.serNum[i] == calinti[1][i])
      {
        gecerlikart = true;
      }
      else
      {
        gecerlikart = false;
      }
    }


    if (gecerlikart == true)
    {
      ag901.write(90);
      Serial.println("calinti");
      lcd.print("calinti arac");
      digitalWrite(2, HIGH);
      digitalWrite(rled, HIGH);
      delay(700);
      digitalWrite(rled, LOW);
      digitalWrite(gled, HIGH);
      delay(700);
      digitalWrite(gled, LOW);
      digitalWrite(bled, HIGH);

      digitalWrite(rled, HIGH);
      delay(700);
  
      digitalWrite(gled, HIGH);
      delay(700);

      digitalWrite(bled, HIGH);
      digitalWrite(rled, LOW);
      delay(700);
      digitalWrite(gled, LOW);
      digitalWrite(bled, HIGH);
      
      digitalWrite(2, LOW);
      
      
      delay(500);
      digitalWrite(bled, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(rled, HIGH);
      delay(700);
      digitalWrite(rled, LOW);
      digitalWrite(gled, HIGH);
      delay(700);
      digitalWrite(gled, LOW);
      digitalWrite(bled, HIGH);
      delay(700);
      digitalWrite(bled, LOW);
      digitalWrite(rled, HIGH);
      digitalWrite(gled, HIGH);
      digitalWrite(gled, LOW);
      delay(1000);
      digitalWrite(rled, HIGH);
      digitalWrite(bled, HIGH);
      delay(1000);
      digitalWrite(bled, LOW);
      digitalWrite(rled, LOW);
      
      lcd.clear();
      digitalWrite(2, LOW);
      ag901.write(0);
    }
    rfid.halt();
    for (int i = 0; i < 5; i++)
    {
      if (rfid.serNum[i] == korona[0][i] || rfid.serNum[i] == korona[1][i])
      {
        gecerlikart = true;
      }
      else
      {
        gecerlikart = false;
      }
    }


    if (gecerlikart == true)
    {
      ag901.write(90);
      Serial.println("kovid");
      lcd.print("kovidli sofor");
      digitalWrite(2, HIGH);
      digitalWrite(rled, HIGH);
      delay(700);
      digitalWrite(rled, HIGH);
      digitalWrite(gled, HIGH);
      digitalWrite(2, LOW);
      delay(700);
      digitalWrite(gled, HIGH);
      digitalWrite(bled, HIGH);
      delay(500);
      digitalWrite(bled, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(rled, HIGH);
      delay(700);
      digitalWrite(rled, HIGH);
      digitalWrite(gled, HIGH);
      delay(700);
      digitalWrite(gled, LOW);
      digitalWrite(bled, HIGH);
      delay(700);
      digitalWrite(bled, LOW);
      digitalWrite(rled, HIGH);

      delay(1000);
      digitalWrite(rled, LOW);
      lcd.clear();
      digitalWrite(2, LOW);
      ag901.write(0);
    }
    rfid.halt();
  }

}
