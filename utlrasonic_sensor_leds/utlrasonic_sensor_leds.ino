const int trigPin = 5;
const int echoPin = 6;

int ledBlue = 13;
int ledRed = 12;
int ledYellow = 11;
int ledGreen = 10;

// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);

  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= 15) {
    digitalWrite(ledBlue, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
  }

  if (distance > 15 && distance <= 30) {
    digitalWrite(ledBlue, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
  } 

  if (distance > 30 && distance <= 45) {
    digitalWrite(ledBlue, HIGH);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
  }

  if (distance > 45 && distance <= 60) {
    digitalWrite(ledBlue, HIGH);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, LOW);
  } 

  if (distance > 60) {
    digitalWrite(ledBlue, HIGH);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, HIGH);
  } 

}