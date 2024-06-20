#ifndef RFIDREADER_H
#define RFIDREADER_H

#include "MFRC522.h"

class RFIDReader {
public:
    RFIDReader(PinName mosi, PinName miso, PinName sclk, PinName cs, PinName reset);
    void init();
    bool readCard();
    const MFRC522::Uid& getUID() const;
    
private:
    MFRC522 rfid;
};

#endif // RFIDREADER_H
