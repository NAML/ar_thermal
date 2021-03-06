/*************************************************** 
  This is a library for the Adafruit Thermal Printer
  
  Pick one up at --> http://www.adafruit.com/products/597
  These printers use TTL serial to communicate, 2 pins are required

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#ifndef Thermal_h
#define Thermal_h

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "SoftwareSerial.h"
#else
 #include "WProgram.h"
 #include "WConstants.h"
 #include "NewSoftSerial.h"
#endif

#define UPC_A 0
#define UPC_E 1 
#define EAN13 2
#define EAN8  3 
#define CODE39 4
#define I25   5 
#define CODEBAR 6 
#define CODE93 7 
#define CODE128 8 
#define CODE11  9
#define MSI 10


class Adafruit_Thermal : public Print {
  public:

  Adafruit_Thermal(int RX_Pin, int TX_Pin);  // constructor
    void begin();
    void setDefault();
    void test();
#if ARDUINO >= 100
    size_t write(uint8_t c);
#else
    void write(uint8_t c);
#endif

    void inverseOn();
    void inverseOff();
    void doubleHeightOn();
    void doubleHeightOff();
    void boldOn();
    void boldOff();
    void underlineOn();
    void underlineOff();
    
    void justify(char value);
    void feed(uint8_t x = 1);
    void sleep();
    void wake();

    void setCharSpacing(int spacing);
    void setSize(char value);
    void setLineHeight(int val = 32);

    void printBarcode(char * text, uint8_t type);
    void setBarcodeHeight(int val);
    void setBottomUp(int up);

    void printBitmap(uint8_t w, uint8_t h,  const unsigned char *bitmap); //uint8_t
    void printBitmapMirrorH(uint8_t w, uint8_t h,  const unsigned char *bitmap); //uint8_t
    void printBitmapMirrorV(uint8_t w, uint8_t h,  const unsigned char *bitmap); //uint8_t
    
    unsigned char invertbits(unsigned char val);
    unsigned char swap8(unsigned char val);

    // ??
    void tab();
    
 private:
#if ARDUINO >= 100
    SoftwareSerial * _printer;
#else
    NewSoftSerial * _printer;
#endif
    boolean linefeedneeded;
    

    // little helpers to make code easier to read&use
    void writeBytes(uint8_t a, uint8_t b);
    void writeBytes(uint8_t a, uint8_t b, uint8_t c);
    void writeBytes(uint8_t a, uint8_t b, uint8_t c, uint8_t d);

    int _RX_Pin;
    int _TX_Pin;
    
    int heatTime;
    int heatInterval;
    char printDensity;
    char printBreakTime;
};

#endif
