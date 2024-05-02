#define sensorPower 7  // Set the pin that will give the sensor POWER
#define sensorPin A0   // Set the pin that will receive info from the sensor


int blueLED = 13;      // Set the pin that will give the BLUE LED POWER
int greenLED = 12;     // Set the pin that will give the GREEN LED POWER
int yellowLED = 11;    // Set the pin that will give the YELLOW LED POWER
int redLED = 10;       // Set the pin that will give the RED LED POWER


void setup() {

  // Setup Code: What we need to do before we start to "set up" the circuit

  pinMode(sensorPower, OUTPUT);     // Set the SENSOR POWER pin to "output"
  digitalWrite(sensorPower, LOW);   // Set the SENSOR POWER pin to "low"

  pinMode(blueLED, OUTPUT);         // Set the BLUE LED POWER pin to "output"
  pinMode(greenLED, OUTPUT);        // Set the GREEN LED POWER pin to "output"
  pinMode(yellowLED, OUTPUT);       // Set the YELLOW LED POWER pin to "output"
  pinMode(redLED, OUTPUT);          // Set the RED LED POWER pin to "output"

  Serial.begin(9600);               // Turn on the Serial Monitor, so we can observe the moisture sensor readings
}


void loop() {

  // put your main code here, to run repeatedly:

  Serial.print("Analog output: ");    // Print statement, which we can see in the Serial Monitor
	Serial.println(readSensor());       // Print statement, so we can see the moisture readings in the Serial Monitor

  digitalWrite(blueLED, LOW);         // Turn off all of the LEDs at first
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);

  if (readSensor() <= 450){           // If the soil is super wet, turn on the BLUE LED
    digitalWrite(blueLED, HIGH);
  }
  else if (readSensor() <= 600){      // Else if the soil is moderately wet, turn on the GREEN LED
    digitalWrite(greenLED, HIGH);
  }
  else if (readSensor() <= 750){      // Else if the soil is moderately dry, turn on the YELLOW LED
    digitalWrite(yellowLED, HIGH);
  }
  else if (readSensor() <= 1010){     // Else if the soil is super dry, turn on the RED LED
    digitalWrite(redLED, HIGH);
  }
  else {
    digitalWrite(blueLED, HIGH);      // Flash all of the LEDs if the moisture reading failed
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, HIGH);
  }
  
	delay(1000); // Delay a few seconds, so that we can get a fresh reading on the next loop
}


int readSensor() {

  // The "readSensor" function will give us the readings that we can use in the "loop" function.

	digitalWrite(sensorPower, HIGH);	// Turn the sensor ON
	delay(10);							          // Allow power to settle
	int val = analogRead(sensorPin);	// Read the analog value from sensor
	digitalWrite(sensorPower, LOW);		// Turn the sensor OFF
	return val;							          // Return analog moisture value
}