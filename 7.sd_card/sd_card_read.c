#include <SPI.h>
#include <SD.h>

#define SD_CS 5

void setup()
{
    Serial.begin(115200);
    delay(2000);

    if (!SD.begin(SD_CS))
    {
        Serial.println("SD Failed");
        return;
    }

    File file = SD.open("/test.txt");

    if (!file)
    {
        Serial.println("File Not Found");
        return;
    }

    Serial.println("Reading File:");

    while (file.available())
    {
        char c = file.read();
        Serial.print(c);
    }

    file.close();

    Serial.println("\nRead Complete");
}

void loop()
{
}