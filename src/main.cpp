#include <Arduino.h>

int rannums(String arr, String ran){
  
  
  for(int i = 0; i <= arr.length();){
    if( ran != String(arr.charAt(i))){
      i++;
      if (i == arr.length()){
        arr.concat(ran);
        break;
      }
    }
    else{
      Serial.println("el caracter que quiere agregar ya esta agregado");
    }
  }
  return arr.toInt();
}

void setup() {
  Serial.begin(9600);
}
void loop() {
  delay(500);
  Serial.print(rannums("132", "3"));
}

