#include <Timino.h>
#include <Clock.h>

Date time(millis(), 12, 0);
Clock clock(10, 9, 8);
int oldMinute = -1;
char* buffer = "";
StaticJsonDocument<256> json;

void setup() {
  Serial.begin(9600);
  clock.setup();
}

void loop() {
  if (Serial.available() > 0)
  {
    char c = Serial.read();
    if (c == '.')
    {
      Serial.println(buffer);
      //deserializeJson(json, buffer);
      //serializeJsonPretty(json, Serial);
      buffer = "";
    }
    else
    {
      buffer += c;
    }
  }
  time.setTimestamp(millis());
  if (time.getMinutes() != oldMinute)
  {
    clock.drawTime(time.getHours(), time.getMinutes());
    oldMinute = time.getMinutes();
  }
  delay(1000);
}
