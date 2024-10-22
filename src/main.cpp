#include <Arduino.h>
#define PINO1 26
#define PINO2 27
// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int result = myFunction(2, 3);
  pinMode(PINO1, OUTPUT);
  pinMode(PINO2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("\tBRANCO\t");
  digitalWrite(PINO1, HIGH);
  digitalWrite(PINO2, LOW);
  delay(1000);
  Serial.println("\t  VERMELHO\t");
  digitalWrite(PINO1, LOW);
  digitalWrite(PINO2, HIGH);
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}