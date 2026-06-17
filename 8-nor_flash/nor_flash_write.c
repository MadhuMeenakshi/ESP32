#include <SPI.h>

#define FLASH_CS 5

void writeEnable()
{
  digitalWrite(FLASH_CS, LOW);
  SPI.transfer(0x06);      // Write Enable
  digitalWrite(FLASH_CS, HIGH);
}

uint8_t readStatus()
{
  digitalWrite(FLASH_CS, LOW);

  SPI.transfer(0x05);      // Read Status Register
  uint8_t status = SPI.transfer(0x00);

  digitalWrite(FLASH_CS, HIGH);

  return status;
}

void waitUntilReady()
{
  while (readStatus() & 0x01)
  {
    delay(1);
  }
}

void setup()
{
  Serial.begin(115200);
  delay(2000);

  pinMode(FLASH_CS, OUTPUT);
  digitalWrite(FLASH_CS, HIGH);

  SPI.begin();

  Serial.println("NOR Flash Test");

  // -------------------------
  // Write Enable
  // -------------------------
  writeEnable();

  // -------------------------
  // Write Data
  // -------------------------
  digitalWrite(FLASH_CS, LOW);

  SPI.transfer(0x02);      // Page Program Command

  SPI.transfer(0x00);      // Address Byte 1
  SPI.transfer(0x00);      // Address Byte 2
  SPI.transfer(0x00);      // Address Byte 3

  char text[] = "MADHU";

  for (int i = 0; i < strlen(text); i++)
  {
    SPI.transfer(text[i]);
  }

  digitalWrite(FLASH_CS, HIGH);

  waitUntilReady();

  Serial.println("Write Complete");

  // -------------------------
  // Read Data
  // -------------------------
  digitalWrite(FLASH_CS, LOW);

  SPI.transfer(0x03);      // Read Command

  SPI.transfer(0x00);
  SPI.transfer(0x00);
  SPI.transfer(0x00);

  Serial.print("Read Data: ");

  for (int i = 0; i < strlen(text); i++)
  {
    char c = SPI.transfer(0x00);
    Serial.print(c);
  }

  digitalWrite(FLASH_CS, HIGH);

  Serial.println();
}

void loop()
{
}