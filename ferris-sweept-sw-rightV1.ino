#include <Keyboard.h>

/*
21  20  19  18  7
1 10  16  14  15
6  5   4   3   2
9  8    -  -  -
*/

//declaring button pins
const int buttonPin[] = {21, 20, 19, 18, 7, 1, 10, 16, 14, 15, 6, 5, 4, 3, 2, 9, 8};
const int buttonSym[] = {'y'/*(mindfuck'z')*/, 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 10, 'n', 'm', ',', '.', 132, 32, 8};

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
