#include <SPI.h>
#include <SD.h>

#define SD_CS 5

void setup()
{
    Serial.begin(115200);
    delay(2000);

    Serial.println("Starting...");

    if (!SD.begin(SD_CS))
    {
        Serial.println("SD Failed");
        return;
    }

    Serial.println("SD OK");

    File file = SD.open("/test.txt", FILE_WRITE);

    if (!file)
    {
        Serial.println("Open Failed");
        return;
    }

    Serial.println("File Opened");

    file.println("Hello ESP32");

    Serial.println("Data Written");

    file.close();

    Serial.println("File Closed");
}

void loop()
{
}