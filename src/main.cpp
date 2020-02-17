#include <Arduino.h>


int randNum;

String addcharToArr(String array, String _char){
  for(int i = 0; i <= array.length();){
    if( _char != String(array.charAt(i))){
      if (i == array.length()){
        array.concat(_char);
        //Serial.print("caracter agregado: ");
        //Serial.println(_char);
        //Serial.print("el array hasta el momento es: ");
        //Serial.println(array);
        //Serial.println("array realmente returnado");
        break;
      }
      i++;
    }
    else{
      Serial.println("el caracter que quiere agregar ya esta agregado");
      break;
    }
  }

  return array;
  
}

String RandNums(int max){
  String sRandNums = String(random(1,5));
  while(sRandNums.length() < max) {
    sRandNums = addcharToArr(sRandNums, String(random(1, 5)));
    Serial.println(sRandNums);
  }

  return sRandNums;
}

void setup() {
  Serial.begin(9600);
  //Serial.println(RandNums(4));
}
void loop() {
  delay(2000);
  Serial.println(RandNums(4));

}

