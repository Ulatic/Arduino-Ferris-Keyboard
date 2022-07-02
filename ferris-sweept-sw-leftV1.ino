#include <Keyboard.h>

/*
7  18  19  20  21
15 14  16  10  1
2  3   4   5   6
-  -  -  8  9
*/

//declaring button pins
const int buttonPin[] = {7, 18, 19, 20, 21, 15, 14, 16, 10, 1, 2, 3, 4, 5, 6, 8, 9};
const int buttonSym[] = {'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z'/*(mindfuck'y')*/, 'x', 'c', 'v', 'b', KEY_LEFT_SHIFT, 32};

int previousButtonState[17] = {HIGH};
int buttonState[17] = {LOW};

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; buttonPin[i] != '\0'; i++){
    pinMode(buttonPin[i], INPUT_PULLUP);
  }
  Keyboard.begin();
}

void loop() {
  
  //checking the state of the button
  for(int i = 0; buttonPin[i] != '\0'; i++){
    buttonState[i] = digitalRead(buttonPin[i]);
  }
  
 //button press
 for(int i = 0; buttonPin[i] != '\0'; i++){
  if (buttonState[i] == LOW && previousButtonState[i] == HIGH) {
      // and it's currently pressed:
    Keyboard.press(buttonSym[i]);
    delay(50);
  }
 }
 for(int i = 0; buttonPin[i] != '\0'; i++){
  if (buttonState[i] == HIGH && previousButtonState[i] == LOW) {
      // and it's currently released:
      Keyboard.release(buttonSym[i]);
    delay(50);
  }
 }
 for(int i = 0; buttonPin[i] != '\0'; i++){
  previousButtonState[i] = buttonState[i];
  }
}
