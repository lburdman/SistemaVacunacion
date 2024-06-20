#include "ble_com.h"
#include "config.h"
#include "mbed.h"

#define BLE_COM_BAUDRATE 9600

UnbufferedSerial bleCom(PIN_BLE_TX, PIN_BLE_RX, BLE_COM_BAUDRATE);

void bleComInit() {
    bleCom.baud(BLE_COM_BAUDRATE);
}

void bleComUpdate() {
    char c;
    if (bleCom.readable()) {
        bleCom.read(&c, 1);
        if (c == '1') {
            bleComStringWrite("Comando 1 recibido\r\n");
        } else if (c == '2') {
            bleComStringWrite("Comando 2 recibido\r\n");
        } else {
            bleComStringWrite("Comando desconocido\r\n");
        }
    }
}

void bleComStringWrite(const char* s) {
    bleCom.write(s, strlen(s));
}
