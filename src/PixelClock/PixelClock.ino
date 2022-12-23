#include <TimeLib.h>
#include <Screen.h>

Time time(millis(), 16, 0);
Screen screen(10, 9, 8);
int oldMinute = -1;
//StaticJsonDocument<200> json;

void setup() {
  Serial.begin(9600);
  //serializeJson(screen.style, Serial);
  //Serial.println();
  screen.setup();
}

void loop() {
  time.setTimestamp(millis());
  if (time.getMinutes() != oldMinute)
  {
    screen.drawTime(time.getHours(), time.getMinutes());
    oldMinute = time.getMinutes();
  }
  delay(1000);
}
