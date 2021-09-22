
/*
 * Elevator by L.Mugnetti
 * V 1.0 28/01/2021
 */
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "functions.h"
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  pinMode(pinButtonExt,INPUT);
  digitalWrite(pinButtonExt, HIGH);
  pinMode(pinButtonInt,INPUT_PULLUP);
  pinMode(pinControlloUscita,INPUT_PULLUP);
  //pinMode(pinControlloEntrata,INPUT_PULLUP);
  pinMode(pinRele1,OUTPUT);
  pinMode(pinRele2,OUTPUT);
  pinMode(pinRele3,OUTPUT);
  pinMode(pinRele4,OUTPUT);
  pinMode(pinRele5,OUTPUT);
  pinMode(pinRele6,OUTPUT);
  pinMode(pinRele7,OUTPUT);

  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  mySwitch.enableReceive(0);
   
  Serial.println();
  zoneReset();
  Serial.println("Zona ripristinata_1");
  
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
   
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
   
  myDFPlayer.volume(29);  //Set volume value. From 0 to 30
  
}

void loop() {
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  } 

  if (mySwitch.available()) {
     int value = mySwitch.getReceivedValue();     
     if (mySwitch.getReceivedValue()){
        process();
     }
  }
  mySwitch.resetAvailable();
  
  if(digitalRead(pinButtonExt)==HIGH && digitalRead(pinControlloUscita)==LOW){
    Serial.println("Premuto Button EXT");
    delay(1250);
    esterno();
    delay(1000);
  }

  if(digitalRead(pinButtonInt)==HIGH && digitalRead(pinControlloUscita)==LOW){
    Serial.println("Premuto button INT");
    delay(500);
    interno();
    delay(1000);
  }
}

void process()
{
  unsigned long* res 
  *res = mySwitch.getReceivedValue(); 
  unsigned long* test;
  int* stato;
  switch (res) // CASI
     {
     case pressed7a:        
          esterno();
     break; 
     
     case pressed7b:        
          esterno();                          
     break;
                               
     case pressed8a:      
          otto(*stato, *test, *res);                     
     break; 
      
     case pressed8b: 
          otto(*stato, *test, *res);                        
     break;  
     
     case pressed9a:        
          stato = digitalRead(pinRele4);
          digitalWrite(pinRele4,!stato);       
          test = mySwitch.getReceivedValue();
          //Serial.println(test);
          while(test==res){
            delay(70); 
            //Serial.println("Dentro");
            test = mySwitch.getReceivedValue();
            mySwitch.resetAvailable();                  
          }  
          digitalWrite(pinRele4,stato);                        
     break;  
     
     case pressed9b:    
          stato = digitalRead(pinRele4);    
          digitalWrite(pinRele4,!stato);       
          test = mySwitch.getReceivedValue();
          //Serial.println(test);
          while(test==res){
            delay(70); 
            //Serial.println("Dentro");
            test = mySwitch.getReceivedValue();
            mySwitch.resetAvailable();                  
          }  
          digitalWrite(pinRele4,stato);                           
     break;  
     
     case pressed10a:        
          stato = digitalRead(pinRele5);
          digitalWrite(pinRele5,!stato);       
          test = mySwitch.getReceivedValue();
          //Serial.println(test);
          while(test==res){
            delay(70); 
            //Serial.println("Dentro");
            test = mySwitch.getReceivedValue();
            mySwitch.resetAvailable();                  
          }   
          digitalWrite(pinRele5,stato);                          
     break;  
     
     case pressed10b:   
          stato = digitalRead(pinRele5);     
          digitalWrite(pinRele5,!stato);       
          test = mySwitch.getReceivedValue();
          //Serial.println(test);
          while(test==res){
            delay(70); 
            //Serial.println("Dentro");
            test = mySwitch.getReceivedValue();
            mySwitch.resetAvailable();                  
          }  
          digitalWrite(pinRele5,stato);                         
     break;
     
     case pressed11a: 
          stato = digitalRead(pinRele6);
          digitalWrite(pinRele6,!stato);       
          test = mySwitch.getReceivedValue();
          //Serial.println(test);
          while(test==res){
            delay(70); 
            //Serial.println("Dentro");
            test = mySwitch.getReceivedValue();
            mySwitch.resetAvailable();                  
          }   
          digitalWrite(pinRele6,stato);                        
     break;  
     
     case pressed11b:        
          stato = digitalRead(pinRele5);
          digitalWrite(pinRele6,!stato);       
          test = mySwitch.getReceivedValue();
          //Serial.println(test);
          while(test==res){
            delay(70); 
            //Serial.println("Dentro");
            test = mySwitch.getReceivedValue();
            mySwitch.resetAvailable();                  
          }   
          digitalWrite(pinRele6,stato);                           
     break;

     case pressed12a:    
          Serial.println("portellone entrata si apre");    
          digitalWrite(pinRele1,LOW);//Stacco magnete
          delay(1000);
          digitalWrite(pinRele1,HIGH);//Attacco magnete                            
     break;  
     
     case pressed12b:      
          Serial.println("portellone entrata si apre");   
          digitalWrite(pinRele1,LOW);//Stacco magnete
          delay(1001);
          digitalWrite(pinRele1,HIGH);//Attacco magnete                           
     break;   
     
     case pressed13a:   
          stato = digitalRead(pinRele7);     
          digitalWrite(pinRele7,!stato);       
          test = mySwitch.getReceivedValue();
          //Serial.println(test);
          while(test==res){
            delay(70); 
            //Serial.println("Dentro");
            test = mySwitch.getReceivedValue();
            mySwitch.resetAvailable();                  
          }  
          digitalWrite(pinRele7,stato);                             
     break;  
     
     case pressed13b:        
          stato = digitalRead(pinRele7);       
          digitalWrite(pinRele7,!stato);       
          test = mySwitch.getReceivedValue();
          //Serial.println(test);
          while(test==res){
            delay(70); 
            //Serial.println("Dentro");
            test = mySwitch.getReceivedValue();
            mySwitch.resetAvailable();                  
          }  
          digitalWrite(pinRele7, stato);                           
     break; 
      
     case pressed14a: 
          Serial.println("portellone uscita si apre");       
          digitalWrite(pinRele2,LOW);//Stacco magnete
          delay(1000);
          digitalWrite(pinRele2,HIGH);//Attacco magnete                      
     break;  
     
     case pressed14b: 
          Serial.println("portellone uscita si apre");        
          digitalWrite(pinRele2,LOW);//Stacco magnete
          delay(1001);
          digitalWrite(pinRele2,HIGH);//Attacco magnete                            
     break;   
  }    
}

void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
  }
} 
