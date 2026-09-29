#include <Arduino.h>

constexpr uint8_t CLK_PIN = 25;
constexpr uint8_t D_PIN   = 27;
constexpr uint8_t Q_PIN   = 26;

void setup()
{
    Serial.begin(115200);

    pinMode(CLK_PIN, OUTPUT);
    pinMode(D_PIN, OUTPUT);
    pinMode(Q_PIN, INPUT);

    digitalWrite(CLK_PIN, LOW);
    digitalWrite(D_PIN, LOW);

    Serial.println("74HC175 experiment");
}

void loop()
{
    // Put D = 1
    digitalWrite(D_PIN, HIGH);

    // Rising edge of clock
    digitalWrite(CLK_PIN, HIGH);
    delayMicroseconds(500);

    // Read Q
    int q = digitalRead(Q_PIN);

    digitalWrite(CLK_PIN, LOW);
    delayMicroseconds(500);

    Serial.print("D = 1, Q = ");
    Serial.println(q);

    // Put D = 0
    digitalWrite(D_PIN, LOW);

    // Rising edge of clock
    digitalWrite(CLK_PIN, HIGH);
    delayMicroseconds(500);

    // Read Q
    q = digitalRead(Q_PIN);

    digitalWrite(CLK_PIN, LOW);
    delayMicroseconds(500);

    Serial.print("D = 0, Q = ");
    Serial.println(q);
}
