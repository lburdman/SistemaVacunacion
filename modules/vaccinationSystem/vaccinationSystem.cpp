#include "vaccinationSystem.h"
#include "config.h"

vaccinationSystem::vaccinationSystem(PinName mosi, PinName miso, PinName sclk, PinName cs, PinName reset, PinName buttonPin)
    : rfidReader(mosi, miso, sclk, cs, reset), button(buttonPin) {
    button.fall(callback(this, &vaccinationSystem::vaccinateCow));
    bleComInit();
}

void vaccinationSystem::run() {
    rfidReader.init();
    printToConsole("Iniciando lector RFID\n");

    while (true) {
        if (rfidReader.readCard()) {
            const MFRC522::Uid& uid = rfidReader.getUID();
            std::string uidStr;
            for (uint8_t i = 0; i < uid.size; i++) {
                char aux[10];
                sprintf(aux, "%02X", uid.uidByte[i]);
                uidStr += aux;
            }
            printToConsole(("Card UID: " + uidStr + "\n").c_str());
            bleComStringWrite(("Card UID: " + uidStr + "\n").c_str());
            
            if (cows.find(uidStr) == cows.end()) {
                cows[uidStr] = Cow(uidStr);
            }
            ThisThread::sleep_for(500ms); // Esperar 500 ms antes de volver a verificar
        }
        bleComUpdate(); // Actualizar el estado del BLE
    }
}

void vaccinationSystem::vaccinateCow() {
    printToConsole("Vaca vacunada\n");
    bleComStringWrite("Vaca vacunada\n");
}

void vaccinationSystem::printToConsole(const char* message) {
    static BufferedSerial pc(USBTX, USBRX, SERIAL_BAUD);
    pc.write(message, strlen(message));
}

