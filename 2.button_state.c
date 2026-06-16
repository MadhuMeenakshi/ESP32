void setup() {
  // put your setup code here, to run once:
  pinMode(4, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  int state = digitalRead(4);
  Serial.println(state);
  delay(100);

}
