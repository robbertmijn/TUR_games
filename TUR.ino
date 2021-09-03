
const int buttonPin = 6;     // the number of the pushbutton pin
const int led1 =  5;      // the number of the LED pin (early)
const int led2 =  4;      // the number of the LED pin (correct)
const int led3 =  3;      // the number of the LED pin (late)

const int ledT =  2;      // the number of the LED pin (yellow)

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int rt = 0;

void doTrial() {
  allDown(); // turn all leds off
  delay( random( 1000, 2000)); // wait a random period between 1 and 2 seconds (prevent rhythmic timing)

  rt = millis(); // (Response Time) save time when ledT turns on
  digitalWrite(ledT, HIGH); // turn ledT (yellow) on

  while(digitalRead(buttonPin) == LOW) {
    // do nothing until button press, mine bitcoin
  }

  rt = millis() - rt; // calculate response time 
  digitalWrite(ledT, LOW); // turn off led

  // Show feedback for 2 seconds
  if(rt < 750 * .85) {
     digitalWrite(led1, HIGH);
  } else {
    if(rt > 750 * 1.15) {
      digitalWrite(led3, HIGH);
    } else {
      digitalWrite(led2, HIGH);
    }
  }
  delay( 2000 )  ;
}

void allDown() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(ledT, LOW);
}

void setup() {
  // initialize the LED pin as an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(ledT, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
doTrial(); //keep looping the trial function
}
