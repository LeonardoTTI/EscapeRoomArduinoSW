
DFRobotDFPlayerMini myDFPlayer;



SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
void printDetail(uint8_t type, int value);

#define pinButtonExt 12
#define pinButtonInt 13
#define pinControlloUscita 14//A0
int a = 0;

#define pinRele1  4//Portellone Entrata 9
#define pinRele2  3//Portellone Uscita 8
#define pinRele3  8//Luce Rossa Fuori 7 
#define pinRele4  9//Luce Verde Fuori 6 
#define pinRele5  6//Luce Rossa Dentro 5 
#define pinRele6  7//Luce Verde Dentro 4
#define pinRele7  0//Pedana 3
#define pinRele8  5//Pistoni Entrata -
//A
#define pressed7a 15756231
#define pressed8a 15756232
#define pressed9a 15756233
#define pressed10a 15756234
#define pressed11a 15756235
#define pressed12a 15756236
#define pressed13a 15756237
#define pressed14a 15756238
//B
#define pressed7b 9196599
#define pressed8b 9196600
#define pressed9b 9196601
#define pressed10b 9196602
#define pressed11b 9196603
#define pressed12b 9196604
#define pressed13b 9196605
#define pressed14b 9196606

void zoneReset(){
  digitalWrite(pinRele1,HIGH);
  digitalWrite(pinRele2,HIGH);
  digitalWrite(pinRele3,LOW);
  digitalWrite(pinRele4,HIGH);
  digitalWrite(pinRele5,LOW);
  digitalWrite(pinRele6,HIGH);
  digitalWrite(pinRele7,LOW);
  digitalWrite(pinRele8,LOW);
}

void brutteCose(){
      digitalWrite(pinRele7,LOW);
      delay(300);
      digitalWrite(pinRele7,HIGH);
      delay(150);
      digitalWrite(pinRele7,LOW);
      delay(300);
      digitalWrite(pinRele7,HIGH);
      delay(200);
      digitalWrite(pinRele7,LOW);
      delay(200);
      digitalWrite(pinRele7,HIGH);
      delay(150);
      digitalWrite(pinRele7,LOW);
      delay(250);
      digitalWrite(pinRele7,HIGH);
      delay(100);
      digitalWrite(pinRele7,LOW);
      delay(1000);
}
void esterno(){
    myDFPlayer.playMp3Folder(1);
    //Serial.println("Scende");
    delay(6000);

    myDFPlayer.playMp3Folder(2);
    //Serial.println("Biing");
    
    delay(200);
    digitalWrite(pinRele3,HIGH);
    //Serial.println("Spengo rossa fuori");
    
    digitalWrite(pinRele4,LOW);
    //Serial.println("Accendo verde fuori");
    
    digitalWrite(pinRele1,LOW);
    //Serial.println("Apro portellone entrata");
    delay(1000);
    
    digitalWrite(pinRele8, LOW);
    //Serial.println("Apro pistoni entrata");

}

void interno(){
  
    digitalWrite(pinRele8, HIGH);
  
    digitalWrite(pinRele1,HIGH);
    //Serial.println("Chiudo portellone entrata");
    
    digitalWrite(pinRele4,HIGH);
    //Serial.println("Spengo verde fuori");
    
    digitalWrite(pinRele3,LOW);
    //Serial.println("Accendo rossa fuori");
    
    myDFPlayer.playMp3Folder(3);
    delay(3000);
    for(int i=0;i<3;i++){
      digitalWrite(pinRele5,HIGH);
      delay(800);
      digitalWrite(pinRele5,LOW);
      delay(800);  
    }
    digitalWrite(pinRele5,HIGH);
    delay(3000);
    //Serial.println("Accendo rossa dentro");
    digitalWrite(pinRele7,HIGH);
    
    delay(1000);
    brutteCose();
    digitalWrite(pinRele7,HIGH);
    
    delay(3000);
    myDFPlayer.playMp3Folder(4);
    delay(200);
    
    digitalWrite(pinRele6,LOW);
    Serial.println("Accesa verde dento");

    delay(500);
    digitalWrite(pinRele2,LOW);
    Serial.println("Apro portellone uscita");

    delay(1000);
    while(digitalRead(pinControlloUscita)==HIGH){
      a++;
      a--;
      delay(100);
    }
    zoneReset();
    Serial.println("Zona ripristinata_2");
}

void otto(int stato, unsigned long test, unsigned long res){
           //Serial.println("8a");  
          //Serial.println(res);
          stato = digitalRead(pinRele3);
          digitalWrite(pinRele3,!stato);
          test = mySwitch.getReceivedValue();
          //Serial.println(test);
          while(test==res){
            delay(70); 
            //Serial.println("Dentro");
            test = mySwitch.getReceivedValue();
            mySwitch.resetAvailable();                  
          }  
          digitalWrite(pinRele3,stato); 
          //Serial.println("fine8a");   
}

