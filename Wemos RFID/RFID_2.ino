/*******************************************************
Program  : wemos dengan RFID MFRC-522
Chip     : wemos d1 
********************************************************/

#include <SPI.h> 
#include <MFRC522.h>
 
#define SS_PIN D2 // sda pin d2
#define RST_PIN D3 // reset pin d3
MFRC522 mfrc522(SS_PIN, RST_PIN); 
int buser=D4; 

void setup() 
{
  pinMode(buser,OUTPUT);
  Serial.begin(9600);   
  SPI.begin();      
  mfrc522.PCD_Init();   
  Serial.println("Dekatkan Tag RFID (Dapat berupa kartu atau gantungan kunci) ke RFID reader");
  Serial.println();
  
}
void loop() 
{
   if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Serial.print("UID tag :");
  //String content= "";
  //byte letter;
 
  for (int i = 0; i < mfrc522.uid.size; i++) 
  {
    // Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], DEC);
     //content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     //content.concat(String(mfrc522.uid.uidByte[i], HEX));
     digitalWrite(buser,HIGH);
     delay(10);
     digitalWrite(buser,LOW);
  }
    
  Serial.println();
  delay(1000);
}
