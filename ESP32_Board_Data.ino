#include <Arduino.h>

void printHeader() {
  Serial.println("//////////////////////////////////////////////////////");
  Serial.println("///////////////// ESP32 Board Data ///////////////////");
  Serial.println("//////////////////////////////////////////////////////");
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  printHeader();
  Serial.println();
  // Heap
  Serial.println("Data of the Heap");
  Serial.print("Heap Size: ");  
  Serial.print(ESP.getHeapSize() / 1024, DEC); // Output in KB //total heap size
  Serial.println(" KB");

  Serial.print("Available Heap Size: ");  
  Serial.print(ESP.getFreeHeap() / 1024, DEC); // Output in KB ////available heap
  Serial.println(" KB"); 

  Serial.print("lowest level of free heap since boot: ");  
  Serial.print(ESP.getMinFreeHeap() / 1024, DEC); // Output in KB 
  Serial.println(" KB");

  Serial.print("largest block of heap that can be allocated at once: ");  
  Serial.print(ESP.getMaxAllocHeap() / 1024, DEC); // Output in KB 
  Serial.println(" KB");

  Serial.println();

  //SPI RAM
  Serial.println("Data of the PSRAM");  
  Serial.print("PSRAM Size: ");  
  Serial.print(ESP.getPsramSize() / 1024, DEC); // Output in KB
  Serial.println(" KB");

  Serial.print("Free PSRAM Size: ");  
  Serial.print(ESP.getFreePsram() / 1024, DEC); // Output in KB 
  Serial.println(" KB");

  Serial.print("Min_Free PSRAM Size: ");  
  Serial.print(ESP.getMinFreePsram() / 1024, DEC); // Output in KB 
  Serial.println(" KB");

  Serial.print("Free PSRAM Size: ");  
  Serial.print(ESP.getMaxAllocPsram() / 1024, DEC); // Output in KB 
  Serial.println(" KB");
  Serial.println();

  Serial.println("chip data");
    //Chip
  Serial.print("Chip Revision: ");  
  Serial.println(ESP.getChipRevision()); 

  Serial.print("Chip Model: ");  
  Serial.println(ESP.getChipModel()); 

  Serial.print("Chip Cores: ");  
  Serial.println(ESP.getChipCores()); 

  Serial.print("Chip Freq: ");  
  Serial.print(ESP.getCpuFreqMHz());
  Serial.println(" MHz"); 
  Serial.println();

  Serial.println("Data of the Flash memory");
  //Flash
  Serial.print("Flash Size: ");
  Serial.print(ESP.getFlashChipSize() / 1024, DEC); // Output in KB
  Serial.println(" KB");

  Serial.print("Flash Chip speed: ");
  Serial.println(ESP.getFlashChipSpeed());

  Serial.print("Flash Chip Mode: ");
  Serial.println(ESP.getFlashChipMode());

  Serial.println();

  Serial.println("Data of the sketch");
    // Sketch
  Serial.print("Sketch Size: ");
  Serial.print(ESP.getSketchSize() / 1024, DEC); // Output in KB   
  Serial.println(" KB");

  Serial.print("Sketch Size MD5: ");
  Serial.println(ESP.getSketchMD5());

  Serial.print("Free sketch Space: ");
  Serial.print(ESP.getFreeSketchSpace() / 1024, DEC); // Output in KB 
  Serial.println(" KB");  
  
  Serial.println();
  Serial.println("Fuse: ");
    uint64_t macAddress = ESP.getEfuseMac();
    Serial.print("MAC Address: ");
    Serial.print((macAddress >> 40) & 0xFF, HEX); // First Byte
    Serial.print(':');
    Serial.print((macAddress >> 32) & 0xFF, HEX); // Second Byte
    Serial.print(':');
    Serial.print((macAddress >> 24) & 0xFF, HEX); // Third Byte
    Serial.print(':');
    Serial.print((macAddress >> 16) & 0xFF, HEX); // Fourth Byte
    Serial.print(':');
    Serial.print((macAddress >> 8) & 0xFF, HEX);  // Fifth Byte
    Serial.print(':');
    Serial.println(macAddress & 0xFF, HEX);       // Sixth Byte
}

void loop() {
  // Do nothing
}