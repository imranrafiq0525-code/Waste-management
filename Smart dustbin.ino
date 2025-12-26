#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define trigPin 9
#define echoPin 10
#define buzzer 6
#define led 5

LiquidCrystal_I2C lcd(0x27, 16, 2);

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Waste Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Ultrasonic trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  lcd.setCursor(0, 0);
  lcd.print("Waste Level: ");

  // LOW LEVEL
  if (distance > 20) {
    lcd.setCursor(0, 1);
    lcd.print("LOW        ");
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
  }

  // MEDIUM LEVEL
  else if (distance <= 20 && distance > 10) {
    lcd.setCursor(0, 1);
    lcd.print("MEDIUM     ");
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
  }

  // HIGH LEVEL (Overflow)
  else if (distance <= 10) {
    lcd.setCursor(0, 1);
    lcd.print("HIGH       ");
    digitalWrite(buzzer, HIGH);

    // LED blink 1 sec ON / OFF
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }

  delay(500);
}
