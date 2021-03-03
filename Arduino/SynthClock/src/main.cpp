#include <Arduino.h>
#include <SimpleTimer.h>
#include <TM1637Display.h>

const int div1Pin = 8;
const int div2Pin = 9;
const int div4Pin = 7;
const int div8Pin = 6;
const int displayClockPin = 5;
const int displayDataPin = 4;
const int pushButtonPin = A1;
const int potPin = A2;

SimpleTimer timer;

TM1637Display display(displayClockPin, displayDataPin);

int count = 0;
int potBpm = 80;
int potValue;
int oldPotValue = 0;
int tapBpm = 80;
int lastTap;
int oldBpm = 80;
int bpm = 80;
bool useTapBpm = false;

int bpmMultiplier = 4;

void setup() {
    Serial.begin(9600);
    pinMode(div1Pin, OUTPUT);
    pinMode(div2Pin, OUTPUT);
    pinMode(div4Pin, OUTPUT);
    pinMode(div8Pin, OUTPUT);
    pinMode(displayClockPin, OUTPUT);
    pinMode(displayDataPin, OUTPUT);
    pinMode(pushButtonPin, INPUT);
    pinMode(potPin, INPUT);

    display.setBrightness(0x0f);
    display.showNumberDec(0, false);

    lastTap = millis();

    timer.setInterval(60000 / potBpm);
}

bool checkButton() { // Quick debounce function
    static int isButtonPressed = 0;

    if (analogRead(pushButtonPin) > 512) {
        isButtonPressed++;
    } else {
        isButtonPressed = 0;
    }

    if (isButtonPressed == 10) {
        return true;
    } else {
        return false;
    }
}

void loop() {
    // Read the pot
    potValue = analogRead(potPin);
    if ((oldPotValue - potValue > 15) || (oldPotValue - potValue < -15)) {  // Fix potmeter hysteresis
        oldPotValue = potValue;
        potBpm = map(potValue, 0, 1023, 70, 150);
        useTapBpm = false;
    }

    // Read the Tap button
    if (checkButton()) {
        int currentTime = millis();
        int delta = currentTime - lastTap;
        Serial.println(delta);
        if ((delta < (60000 / 70)) && (delta > (60000 / 150))) {
            tapBpm = 60000 / delta;
            useTapBpm = true;
        }
        lastTap = currentTime;
    }

    // Switch between tap or pot for BPM source
    if (useTapBpm) {
        bpm = tapBpm * bpmMultiplier;
    } else {
        bpm = potBpm * bpmMultiplier;
    }

    if (oldBpm != bpm) {
        display.showNumberDec(bpm / bpmMultiplier);
        oldBpm = bpm;
    }

    if (timer.isReady()) {
        timer.reset();
        timer.setInterval(60000 / bpm);

        digitalWrite(div1Pin, HIGH);
        if (count % 2 == 0)
            digitalWrite(div2Pin, HIGH);
        if (count % 4 == 0)
            digitalWrite(div4Pin, HIGH);
        if (count % 8 == 0) {
            digitalWrite(div8Pin, HIGH);
            count = 0;
        }

        count++;

        delay(10);

        digitalWrite(div1Pin, LOW);
        digitalWrite(div2Pin, LOW);
        digitalWrite(div4Pin, LOW);
        digitalWrite(div8Pin, LOW);
    }
}