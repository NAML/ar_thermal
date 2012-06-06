#include <Adafruit_Thermal.h>


/*************************************************** 
 * This is an example sketch for the Adafruit Thermal Printer
 * 
 * Pick one up at --> http://www.adafruit.com/products/597
 * These printers use TTL serial to communicate, 2 pins are required
 * 
 * Adafruit invests time and resources providing this open source code, 
 * please support Adafruit and open-source hardware by purchasing 
 * products from Adafruit!
 * 
 * Written by Limor Fried/Ladyada for Adafruit Industries.  
 * MIT license, all text above must be included in any redistribution
 ****************************************************/


// if you're using Arduino 1.0 uncomment the next line
#include "SoftwareSerial.h"
// if you're using Arduino 23 or earlier, uncomment the next line
//#include "NewSoftSerial.h"

#include "sem_256_f.cpp"
#include "sem_256.cpp"
#include "wei.cpp"
#include "wei_f.cpp"

int printer_RX_Pin = 2;  // this is the green wire
int printer_TX_Pin = 3;  // this is the yellow wire

Adafruit_Thermal printer(printer_RX_Pin, printer_TX_Pin);

//unsigned char * frases [] = {
//  "Lei Feng is just a discarded political doll of the regime.",};


void setup(){
  Serial.begin(9600);

  ////////////////////////////////////////////////////////////////////
  //Following are in setup, but do not need to be. Use them anywhere. 
  //Just here so they do not just keep printing over and over
  //Printer will ignore commands during printing, so use delay(3000)
  //after prints to ensure it see everything you want to print.
  //SOME FUNCTIONS WILL FEED A LINE WHEN CALLED TO SOLIDIFY SETTING
  ////////////////////////////////////////////////////////////////////

  printer.begin();
  printer.setDefault();


  delay(1000);
  randomSeed(analogRead(0));

  pinMode(13, OUTPUT);
}

int timer;

void loop(){

  digitalWrite(13, LOW);

  long random_option =  random(0,1000);
  long direccion_wei = random(0,30);
  long idioma_texto = random(0,100);
  int  mugre = (int) random(0,10);
  
  int option = 0;

  if(random_option < 450){
    option = 0;
 //   ledBlink(1);
  } 
  else if (random_option < 900) {
    option = 1;
 //   ledBlink(2);
  } 
  else if (random_option < 980) {
    option = 2;
 //   ledBlink(3);
  }
  else {
    option = 3;
 //   ledBlink(4);
  }

//  delay(1000);




  // engania pichanga
  //option = 3;

   printer.begin();
   printer.setDefault();

  switch(option) {

  case 0:
    printer.printBitmap(256, 256, semilla_f + mugre);
    break;

  case 1:
    printer.printBitmap(256, 256, semilla + mugre);
    break;

  case 2:
  
    printer.printBitmap(144,180, wei_f);
    
    if(direccion_wei < 29){
  
    } else {
    //  printer.printBitmap(151,189, wei);
    }
    
    break;

  case 3:
    printer.inverseOn();
    printer.upsideDownOn();
    printer.doubleHeightOn();
    printer.doubleWidthOn();

    char * eng = 
      "  of the regime."
      " political doll "
      "just a discarded"
      "Lei Feng is ";

    char * esp = 
    "  por el regimen"
    "tica abandonada "
    " marioneta poli-"
    " simplemente una"   
    "Lei Feng es"; 
    

    if(idioma_texto < 50){
      printer.println(eng);
    }else {
      printer.println(esp);
    }
    break;
  }
  
    delay(6000);
}


void ledBlink(int times){

  for(int i = 0; i < times ; i++){
    delay(100);
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
  }
}




