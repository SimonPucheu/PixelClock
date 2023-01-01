#include <ArduinoJson.h>

StaticJsonDocument<256> filtrer;
StaticJsonDocument<256> style;
char* buffer = "";

void setup() {
  Serial.begin(9600);
  filtrer["background"]["color"]["hex"]["24"] = true;
  filtrer["number"]["color"]["hex"]["24"] = true;
  filtrer["number"]["size"] = true;
  filtrer["margin"]["left"] = true;
  filtrer["margin"]["top"] = true;
  filtrer["padding"] = true;
  filtrer["landscape"] = true;
}

void loop() {
  int availableBytes = Serial.available();
  for (int i = 0; i < availableBytes; i++)
  {
    char r = Serial.read();
    if (r == '.')
    {
      //buffer = "{\"padding\":0}";
      //Serial.println("end");
      //Serial.println(buffer);
      DeserializationError err = deserializeJson(style, buffer, DeserializationOption::Filter(filtrer));
      //Serial.println(err == DeserializationError::Ok);
      serializeJsonPretty(style, Serial);
      buffer = "";
    }
    else
    {
      buffer[i] = r;
      //Serial.print(i); Serial.print(": "); Serial.println(buffer[i]);
    }
  }
  delay(1000);
}
