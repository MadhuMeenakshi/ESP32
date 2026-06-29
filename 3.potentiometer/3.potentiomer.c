

void setup()
{
   
    Serial.begin(115200);
}

void loop()
{
    int sensor_val = analogRead(34);
    Serial.println(sensor_val);
    delay(200);
}