#include <Arduino.h>

byte Cyl1Push = 2, Cyl2Push = 3, Cyl3Push = 4, Cyl4Push  = 5, Cyl1Pull = 6, Cyl2Pull = 7, Cyl3Pull = 8, Cyl4Pull = 9;

int numElements;
String arr[20];

void setup() {
  String secExample = "A+A-B+C+B-C-";
  
  Serial.begin(9600);
  pinMode(A0, INPUT);
  
  fillArr(secExample);

  numElements = sizeof(arr) / sizeof(arr[0]);
  //Serial.println(numElements);

  CheckSecuence(arr, numElements);
}

void loop() {
  

}

void CheckSecuence(String arrf[],int numElments) {
  int counter = 0;
  int Cyl1, Cyl2, Cyl3, Cyl4;
  for(int i = 0;i < numElements;i++){
    if (arrf[i] != ""){
      counter++;
    }
  }
  
  for (int i = 0; i < counter; i++) {
    int Cyl;
    String minusorplus;

    //Serial.println(arrf[i].substring(0,1));

    if (arrf[i].substring(0,1) == "B"){
      Serial.println("cacas");
    }
  }
}

void fillArr(String estring) {
  for (int i = 0;i < estring.length()/2;i++){
    arr[i] = estring.substring(0 + i*2,2 + i*2);
  }
}