#include <Arduino.h>

#include <LiquidCrystal.h>

#define pinTemp 0
#define buttonPin 7
#define LCD_LIGHT_PIN A4

int buttonState = 0;

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
int temperatura;

void setup()
{
    pinMode(buttonPin, INPUT);
    pinMode(LCD_LIGHT_PIN, OUTPUT);
    lcd.begin(16, 2);
    // lcd.noDisplay();
    digitalWrite(LCD_LIGHT_PIN, LOW);
    Serial.begin(9600);
    // put your setup code here, to run once:
}

void loop()
{
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH)
    {
        digitalWrite(LCD_LIGHT_PIN, HIGH);
        lcd.setCursor(0, 0);
        for (int on = 10; on > 0; on--)
        {
            lcd.clear();
            lcd.print("Temperatura");
            lcd.setCursor(13, 0);
            lcd.print(on);
            lect_temp();
        }
        lcd.clear();
        digitalWrite(LCD_LIGHT_PIN, LOW);
    }
}

float getTemp()
{
    float voltage = analogRead(pinTemp);
    float temp = (voltage * 5.0 / 1024) * 100;
    return temp;
}

void lect_temp()
{
    float temperatura = getTemp();
    lcd.setCursor(0, 1);
    lcd.print(temperatura);
    lcd.setCursor(6, 3);
    lcd.print("Grados C");
    Serial.println(temperatura);
    delay(1000);
}
