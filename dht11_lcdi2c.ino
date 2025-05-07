#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2         // Ubah ke pin 4 jika pakai ESP32
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Alamat I2C bisa juga 0x3F tergantung modul LCD

void setup() {

// Wire.begin(21, 22); // SDA = GPIO 21, SCL = GPIO 22  uncomment jika menggunakan esp32

  dht.begin();
  lcd.print("Tes Sensor DHT11");
  lcd.setCursor(0, 1);
  lcd.print("Suhu & Kelembapn");
  delay(1000);
}

void loop() {
  delay(1000);

  float k = dht.readHumidity();
  float s = dht.readTemperature();

  if (isnan(k) || isnan(s)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor error");
    return;
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Suhu: ");
  lcd.print(s);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Lembab: ");
  lcd.print(k);
  lcd.print(" %");
}
