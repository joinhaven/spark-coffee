// see http://docs.particle.io/core/cli/

#define PIN D7
int state = 0;

void setup() {
    Serial.begin(9600);
    //tell the device we want to write to this pin
    pinMode(PIN, OUTPUT);
}

void loop() {
    //alternate the PIN between high and low
    digitalWrite(PIN, (state) ? HIGH : LOW);

    //invert the state
    state = !state;
    Serial.println("Flipping state");

    //wait half a second
    delay(1000);
}
