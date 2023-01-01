#include <VirtualDate.h>
#include <Clock.h>

Date time(millis(), 12, 0);
Clock clock(10, 9, 8);
int oldMinute = -1;
char* buffer = "";

void setup() {
  Serial.begin(9600);
  clock.setup();
}

void loop() {
  if (Serial.available() > 0)
  {
    char r = Serial.read();
    if (r == '.')
    {
      deserializeJson(clock.style, buffer, DeserializationOption::Filter(clock.filtrer));
      buffer = "";
    }
    else
    {
      buffer += r;
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
