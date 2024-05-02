int buttonPin = 13;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

String morseCode = "";

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  // pinMode(LED2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    buttonState1 = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == LOW) {
    delay(1000);
    buttonState2 = digitalRead(buttonPin);
    if (buttonState2 == LOW){
      delay(1000);
      buttonState3 = digitalRead(buttonPin);
      if (buttonState3 == LOW){
        Serial.print("_");
        // Serial.println();
        morseCode = morseCode + " ";
        delay(1000);
      }
      else{
        Serial.print("-");
        morseCode = morseCode + "-";
      }      
    }
    else {
      Serial.print(".");
      morseCode = morseCode + ".";
    }
  }

  // Serial.print("hi");
}
