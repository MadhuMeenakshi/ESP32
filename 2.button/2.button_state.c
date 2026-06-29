void setup() {
  pinMode(4, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {

  int state = digitalRead(4);

  if(state == LOW)
  {
    Serial.println("BUTTON PRESSED");
  }
  else
  {
    Serial.println("BUTTON RELEASED");
  }

  delay(100);
}