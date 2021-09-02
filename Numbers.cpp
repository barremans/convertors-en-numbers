

#include "Arduino.h"
#include "Numbers.h"

//general
int i;
// for randomVoltage
    long ADCrandNbr;
// for randomDecimal
    long DrandNumber;
    float flrandNumber;
// for HEX and UID
byte uuidNumber[16]; // UUIDs in binary form are 16 bytes long
// for randomSUM and random number
  long randNumber; //random number
  long ResultNbr;  // result of the calculation
  long S_ResultNbr; // holds the result for the second calculation
  boolean didMyOneTimeAction = false; // first time calculate with the startnumber, then with the previous



void randomVoltage(float min, float vol){
      //generate a random voltage source  10Bit
    ADCrandNbr = random(min,1024); // min 217V max 245V
  //display the random number on the serial monitor
  Serial.print("The Rvoltage = ");
  Serial.println((ADCrandNbr* vol)/1023.00); // 245 is voltage
}

void randomDecimal(int min, int max){
  // Generate a new random Decimal number
DrandNumber = random(min,max); // min and max
flrandNumber = (float)DrandNumber / 100.00;
  Serial.print("A random RDecimal: ");
  Serial.println (flrandNumber);
}

void randomByte(){
  // Generate a new random Byte
    Serial.print("A random Rbyte: ");
  Serial.println(TrueRandom.randomByte(),DEC);
}

void randomBit(){
  // Generate a new random Bit
    Serial.print("A random Rbit: ");
  Serial.println(TrueRandom.randomBit());
}

void randomI(int min, int digits, int max){
   // Generate a new random number
    Serial.print("Random Rdigits: ");
  for (i=min;i<=digits;i++) Serial.print(random(max));
  Serial.println();
}


void printHex(byte number) {
  int topDigit = number >> 4;
  int bottomDigit = number & 0x0f;
  // Print high hex digit
  Serial.print( "0123456789ABCDEF"[topDigit] );
  // Low hex digit
  Serial.print( "0123456789ABCDEF"[bottomDigit] );
}

void printUuid(byte* uuidNumber) {
  for (i=0; i<16; i++) {
    if (i==4) Serial.print("-");
    if (i==6) Serial.print("-");
    if (i==8) Serial.print("-");
    if (i==10) Serial.print("-");
    printHex(uuidNumber[i]);
  }
}

void randomUID(){
  // Generate a new UUID
  TrueRandom.uuid(uuidNumber);
    Serial.print("The UUID Rnumber is ");
  printUuid(uuidNumber);
  Serial.println();
}

void randomNbr(int first, int last){
   //generate a random number
    randNumber = random(first,last); // min and max
  //display the random number on the serial monitor
  Serial.print("The Random Nbr is = ");
  Serial.println(randNumber);
}

void bitconv(int Blength, int data){  
// convert number to bit, bit lengt then converting number
//declaration  
String Sstrn = ""; // Bit holder
String strnB ="";
int length;
int RealBit = Blength - 1;
    if (Sstrn.length() < Blength) // if length not equal to bit length than add 0 until bit length
  {
for (int i = 0; i <= RealBit; i++) {
  Sstrn =  String(Sstrn + "0");
  length = Sstrn.length();
}
// fill string array with bit 0 according the length
char strnA[Sstrn.length() + 1];
strcpy(strnA, Sstrn.c_str()); // Place incoming route in char array
strnB = strcpy(strnA, Sstrn.c_str()); // placeholder for the bit array
  }

 // convert number into bit 
  if (Sstrn.length() == Blength){
  for (int i = 0; i <= RealBit; i++) {
  strnB[i] = bitRead(data, RealBit - i) + 48;      
  }   
  }
Serial.println(strnB); 
}

void randomSUM(int min, int max, int startnbr){
    //display add the random number to the start number and then to the previous 
   //generate a random number
    randNumber = random(min,max); // min and max

 if (didMyOneTimeAction == false){
    didMyOneTimeAction = true;
   Serial.print("startnbr: ");
   Serial.println(startnbr);
    ResultNbr = randNumber + startnbr;
    S_ResultNbr = ResultNbr;
      Serial.print("The Random Nbr is = ");
   Serial.println(randNumber);
   Serial.print("Result: ");
   Serial.println(ResultNbr);
    Serial.println("--------------------");
   S_ResultNbr = ResultNbr;
 }
  if(didMyOneTimeAction == true){
//////////////
      Serial.print("Previous: ");
      Serial.println(S_ResultNbr);
  ResultNbr = randNumber + S_ResultNbr;
  Serial.print("The Random Nbr is = ");
  Serial.println(randNumber);
     S_ResultNbr = ResultNbr;
      Serial.print("Result: ");
      Serial.println(S_ResultNbr);
      Serial.println("--------------------");
  }
}
