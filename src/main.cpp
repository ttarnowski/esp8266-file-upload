#include <Arduino.h>
#include <LittleFS.h>

const char *filename = "2MB.txt";

void setup() {
  Serial.begin(115200);
  delay(5000);

  LittleFS.begin();

  File file = LittleFS.open(filename, "r");

  if (!file) {
    Serial.println("could not open file for reading");
  } else {

    while (file.available()) {
      char buf[32];

      size_t bytesRead = file.readBytes(buf, sizeof(buf) - 1);
      buf[bytesRead] = '\0';

      Serial.print(buf);

      yield();
    }

    file.close();
  }

  LittleFS.end();
}

void loop() {}