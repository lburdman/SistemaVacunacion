#ifndef CONFIG_H
#define CONFIG_H

// Configuración del puerto serial
#define SERIAL_BAUD 115200

// Definición de los pines para el módulo RFID
#define PIN_RFID_MOSI PA_7
#define PIN_RFID_MISO PA_6
#define PIN_RFID_SCLK PA_5
#define PIN_RFID_CS   PE_3
#define PIN_RFID_RESET PG_1

// Definición de los pines para el módulo BLE
#define PIN_BLE_TX PD_6
#define PIN_BLE_RX PD_5
#define PIN_BLE_STATE PD_4

#endif // CONFIG_H

