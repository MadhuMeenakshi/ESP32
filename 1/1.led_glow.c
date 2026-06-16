

void setup()
{
    pinMode(2,OUTPUT);
    Serial.begin(115200);
}

void loop()
{
   Serial.println("LED ON");
   digitalWrite(2,HIGH);
   delay(1000);     
    
    Serial.println("LED OFF");  
    digitalWrite(2,LOW);
    delay(1000);    
}