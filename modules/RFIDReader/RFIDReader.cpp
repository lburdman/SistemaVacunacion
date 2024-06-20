#include "RFIDReader.h"

RFIDReader::RFIDReader(PinName mosi, PinName miso, PinName sclk, PinName cs, PinName reset)
    : rfid(mosi, miso, sclk, cs, reset) {}

void RFIDReader::init() {
    rfid.PCD_Init();
}

bool RFIDReader::readCard() {
    return rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial();
}

const MFRC522::Uid& RFIDReader::getUID() const {
    return rfid.uid;
}
