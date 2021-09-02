#include "TrueRandom.h"
#include "Numbers.h"

int ledpin = 7;

/*
  long randNumber; //random number
  long ResultNbr;  // result of the calculation
  long S_ResultNbr; // holds the result for the second calculation
  boolean didMyOneTimeAction = false; // first time calculate with the startnumber, then with the previous
*/

void setup() {
  pinMode(ledpin, OUTPUT); // Declare the LED as an output

  Serial.begin(115200); // Any baud rate should work
  delay(2);
  Serial.println("Hello Arduino\n");

}

void loop() {

  // randomSUM(-10,10,100);  //min,max,start number

  // randomNbr(-2,10);  // min, max

  // randomUID();

  // randomI(1,2, 10); // min , #digits , max

  //  printHex(26);

  // randomBit();

  // randomByte();

  // randomDecimal(-26000,26000);  // min , max

  // randomVoltage(910.69,245); // min , max

  //bitconv(16,46);  // #byte , number to convert

  delay(3000);

}
