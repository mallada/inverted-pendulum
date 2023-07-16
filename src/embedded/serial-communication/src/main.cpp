#include <Arduino.h>

#define LED 12

long last_update = 0;
int dt = 10;

float state[] = {0,0,0,0,0,0};
float control[] = {0};

void setup() {
  Serial.begin(500000);
  Serial.setTimeout(dt);
  pinMode(LED, OUTPUT);
}

void loop() {
  while (millis() - last_update < dt) {}

  last_update = (millis() / dt) * dt;

  Serial.write('x');
  Serial.write('s');
  Serial.write('t');
  Serial.write((uint8_t*)state, sizeof(state));
  digitalWrite(LED, HIGH);

  while (!Serial.available()) {}
  digitalWrite(LED, LOW);

  Serial.readBytes((char*)control, sizeof(control));
  state[0] = control[0];
}