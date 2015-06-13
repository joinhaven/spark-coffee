int sent = 0;
int buttonPressed = 0;

void setup() {
    Serial.begin(9600);
    pinMode(D0, INPUT);
    pinMode(D7, OUTPUT);
}

void loop() {
    delay(500);

    buttonPressed = digitalRead(D0);
    digitalWrite(D7, buttonPressed);
}
