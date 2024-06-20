#ifndef VACCINATIONSYSTEM_H
#define VACCINATIONSYSTEM_H

#include "config.h"
#include "RFIDReader.h"
#include "cow.h"
#include "ble_com.h"
#include "mbed.h"
#include <unordered_map>

class vaccinationSystem {
public:
    vaccinationSystem(PinName mosi, PinName miso, PinName sclk, PinName cs, PinName reset, PinName buttonPin);
    void run();
    
private:
    RFIDReader rfidReader;
    std::unordered_map<std::string, Cow> cows;
    InterruptIn button;
    void vaccinateCow();
    void printToConsole(const char* message);
};

#endif // VACCINATIONSYSTEM_H


