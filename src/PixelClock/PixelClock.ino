#include <Timino.h>
#include <Clock.h>

Date time(millis(), 12, 0, 0, 0, 1.00001);
Clock clock(10, 9, 8);
int oldMinute = -1;
String buffer = "";

void setup() {
  Serial.begin(9600);
  clock.setup();
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      time = Date(millis(), buffer);
      Serial.print("Hour successfully updated to "); Serial.println(buffer);
      buffer = "";
    } else {
      buffer += c;
    }
  }
  time.setTimestamp(millis());
  if (time.getMinutes() != oldMinute) {
    clock.drawTime(time.getHours(), time.getMinutes());
    oldMinute = time.getMinutes();
  }
  delay(1000);
}
