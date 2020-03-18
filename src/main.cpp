#include <Arduino.h>

byte Cyl1Push = 2, Cyl2Push = 3, Cyl3Push = 4, Cyl4Push  = 5, Cyl1Pull = 6, Cyl2Pull = 7, Cyl3Pull = 8, Cyl4Pull = 9;

bool ActualCyl1push, ActualCyl1pull, ActualCyl2push, ActualCyl2pull, ActualCyl3push, ActualCyl3pull, ActualCyl4push, ActualCyl4pull;
int numElements;
String SecuenceElements[20];
bool GoodSoFar;
int index = 0;

void fillArr(String estring) {
  for (int i = 0;+i < +estring.length()/2;i++){
    SecuenceElements[i] = estring.substring(0 + i*2,2 + i*2);
  }
}

void setup() {

  ActualCyl1push = digitalRead(Cyl1Push);
  ActualCyl1pull = digitalRead(Cyl1Pull);
  ActualCyl2push = digitalRead(Cyl2Push);
  ActualCyl2pull = digitalRead(Cyl2Pull);
  ActualCyl3push = digitalRead(Cyl3Push);
  ActualCyl3pull = digitalRead(Cyl3Pull);
  ActualCyl4push = digitalRead(Cyl4Push);
  ActualCyl4pull = digitalRead(Cyl4Pull);

  String secExample = "A+A-B+C+B-C-";
  
  Serial.begin(9600);
  pinMode(A0, INPUT);
  
  fillArr(secExample);

  numElements = sizeof(SecuenceElements) / sizeof(SecuenceElements[0]);
  //Serial.println(numElements);

  CheckCylinders(SecuenceElements, numElements);

}

void loop() {
  if (digitalRead(Cyl1Push) != ActualCyl1push) {
    CheckCylinders(SecuenceElements, numElements);

    ActualCyl1push = !ActualCyl1push;
  }

  if (digitalRead(Cyl1Pull) != ActualCyl1pull) {
    CheckCylinders(SecuenceElements, numElements);

    ActualCyl1pull = !ActualCyl1pull;
  }

  if (digitalRead(Cyl2Push) != ActualCyl2push) {
    CheckCylinders(SecuenceElements, numElements);

    ActualCyl2push = !ActualCyl2push;
  }

  if (digitalRead(Cyl2Pull) != ActualCyl2pull) {
    CheckCylinders(SecuenceElements, numElements);

    ActualCyl2pull = !ActualCyl2pull;
  }

  if (digitalRead(Cyl3Push) != ActualCyl3push) {
    CheckCylinders(SecuenceElements, numElements);

    ActualCyl3push = !ActualCyl3push;
  }

  if (digitalRead(Cyl3Pull) != ActualCyl3pull) {
    CheckCylinders(SecuenceElements, numElements);

    ActualCyl3pull = !ActualCyl3pull;
  }

  if (digitalRead(Cyl4Push) != ActualCyl4push) {
    CheckCylinders(SecuenceElements, numElements);

    ActualCyl4push = !ActualCyl4push;
  }

  if (digitalRead(Cyl4Pull) != ActualCyl4pull) {
    CheckCylinders(SecuenceElements, numElements);

    ActualCyl4pull = !ActualCyl4pull;
  }
}



void CheckCylinders(String SecElmnts[], int numElmnts) {

  int counter = 0;

  for(int i = 0;i < numElmnts;i++){
    if (SecElmnts[i] != ""){
      counter++;
    }
  }

  if (SecElmnts[index].substring(0,1) == "A"){
    if(SecElmnts[index].substring(1,2) == "+"){
      if (digitalRead(Cyl1Push) == 1){
        GoodSoFar = true;
      }
      else{
        GoodSoFar = false;
      }
    }
    else if (SecElmnts[0].substring(1,2) == "-"){
      if (digitalRead(Cyl1Pull) == 1){
        GoodSoFar = true;
      }
      else{
        GoodSoFar = false;
      }
    }
  }


  else if (SecElmnts[index].substring(0,1) == "B"){
    if(SecElmnts[index].substring(1,2) == "+"){
      if (digitalRead(Cyl2Push) == 1){
        GoodSoFar = true;
      }
      else{
        GoodSoFar = false;
      }
    }
    else if (SecElmnts[0].substring(1,2) == "-"){
      if (digitalRead(Cyl2Pull) == 1){
        GoodSoFar = true;
      }
      else{
        GoodSoFar = false;
      }
    }
  }

  else if (SecElmnts[index].substring(0,1) == "C"){
    if(SecElmnts[index].substring(1,2) == "+"){
      if (digitalRead(Cyl3Push) == 1){
        GoodSoFar = true;
      }
      else{
        GoodSoFar = false;
      }
    }
    else if (SecElmnts[index].substring(1,2) == "-"){
      if (digitalRead(Cyl3Pull) == 1){
        GoodSoFar = true;
      }
      else{
        GoodSoFar = false;
      }
    }
  }

  else if (SecElmnts[index].substring(0,1) == "C"){
    if(SecElmnts[index].substring(1,2) == "+"){
      if (digitalRead(Cyl4Push) == 1){
        GoodSoFar = true;
      }
      else{
        GoodSoFar = false;
      }
    }
    else if (SecElmnts[index].substring(1,2) == "-"){
      if (digitalRead(Cyl4Pull) == 1){
        GoodSoFar = true;
      }
      else{
        GoodSoFar = false;
      }
    }
  }

  if (index == counter) {
    if(GoodSoFar) {
      Serial.print("You Won");
    }
    else {
      Serial.print("You Failed");
    }
  }

  index++;

}



