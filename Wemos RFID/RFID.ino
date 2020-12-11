#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  D3
#define SS_PIN   D2

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  ShowReaderDetails();
  Serial.println(F("Scan PICC to use UID, type, and data block ...  "));
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()){
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()){
    return;
  }
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
void ShowReaderDetails(){
  byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  Serial.print(F("MFRC522 Sofware Version: 0x"));
  Serial.print(v, HEX);
  if (v == 0x91)
    Serial.print(F(" = v1.0"));
  else if (v == 0x92)
    Serial.print(F("= v2.0"));
  else
    Serial.print(F("(unknown)"));
  Serial.println("");
  if ((v == 0x00) || (v == 0xFF)){
    Serial.println(F("WARNING: Communication Failure, is the MFRC522 properly connected ?"));
  }
}
