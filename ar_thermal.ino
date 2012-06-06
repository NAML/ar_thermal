#include <Adafruit_Thermal.h>


/*************************************************** 
  This is an example sketch for the Adafruit Thermal Printer
  
  Pick one up at --> http://www.adafruit.com/products/597
  These printers use TTL serial to communicate, 2 pins are required

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  MIT license, all text above must be included in any redistribution
 ****************************************************/


// if you're using Arduino 1.0 uncomment the next line
#include "SoftwareSerial.h"
// if you're using Arduino 23 or earlier, uncomment the next line
//#include "NewSoftSerial.h"

#include "sem_256.cpp"


int printer_RX_Pin = 2;  // this is the green wire
int printer_TX_Pin = 3;  // this is the yellow wire

Adafruit_Thermal printer(printer_RX_Pin, printer_TX_Pin);


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



}

int timer;
void loop(){
  //  printer.setBottomUp(1);
    //printer.feed(4);
    //printer.test();
    // h x w  = 150 * 143
    printer.printBitmap(256, 256, semilla);
    printer.feed(1);
    while(1){;}
//  delay(500);
  
}
