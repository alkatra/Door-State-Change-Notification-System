const int REED = D0;
const int LED = D7;

// state = false if door is open
bool state = false;
int val = 0;

void setup() {
	pinMode(REED, INPUT_PULLUP);
	pinMode(LED, OUTPUT);
    val = digitalRead(REED);
    state = val == 0 ? true : false;
}

void loop() {
    val = digitalRead(REED);
    // val is 0 if door is closed, val is 1 if door is open
    if(val == 1 && state == false) {
        state = !state;
        digitalWrite(LED, LOW);
        // Publishing state as False means Door is open.
        Particle.publish("state", "False");

    }
    else if(val == 0 && state == true) {
        state = !state;
        digitalWrite(LED, HIGH);
        // Publishing state as True means Door is closed.
        Particle.publish("state", "True");
    }
}

