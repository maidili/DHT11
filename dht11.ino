#include <DHT.h>

#define DHTPIN 2 //untuk esp32 pakai pin 4 yahh
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(1000);

  float k = dht.readHumidity();
  float s = dht.readTemperature();

  if(isnan(k)  ||  isnan(s)){
    Serial.println("nilai sensor tidak terbaca");
    return;

  }

  Serial.print("kelembapan: ");
  Serial.print(k);
  Serial.print("%\t");

  Serial.print("suhu: ");
  Serial.print(s);
  Serial.println(" *C ");

}