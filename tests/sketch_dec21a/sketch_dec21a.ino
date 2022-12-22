#include <ArduinoJson.h>

StaticJsonDocument<200> defaultStyle;
StaticJsonDocument<200> style;
StaticJsonDocument<200> json;

void setup() {
  Serial.begin(9600);
  defaultStyle["background"]["color"]["hex"]["24"] = true;
  defaultStyle["number"]["color"]["hex"]["24"] = true;
  defaultStyle["number"]["size"] = true;
  defaultStyle["margin"]["left"] = true;
  defaultStyle["margin"]["top"] = true;
  defaultStyle["padding"] = true;
}

void loop() {
  if (Serial.available())
  {
    Serial.println("something on serial");
    DeserializationError error = deserializeJson(json, Serial, DeserializationOption::Filter(defaultStyle));
    if (error == DeserializationError::Ok)
    {
      Serial.println("good");
      style = json;
      serializeJson(style, Serial);
    }
    else
    {
      Serial.println("nop");
      Serial.println(error.c_str());
      while (Serial.available())
      {
        Serial.read();
      }
    }
  }
}
