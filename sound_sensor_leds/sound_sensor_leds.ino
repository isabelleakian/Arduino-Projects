int ledBlue = 13;
int ledRed = 12;
int ledYellow = 11;
int ledGreen = 10;
float sensorPin = 4;

float volume = 0;

void setup() {
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  volume = digitalRead(sensorPin);
  Serial.println(volume);

  if (volume < 1) {
    digitalWrite(ledBlue, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
  } else {
    digitalWrite(ledBlue, HIGH);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, HIGH);
  }
}
