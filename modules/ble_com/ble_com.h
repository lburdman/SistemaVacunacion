/*! @file ble_com.h Header file for the Bluetooth Communication module.
 *
 * @note This module handles the Bluetooth user interface.
 */

#ifndef _BLE_COM_H_
#define _BLE_COM_H_

#include "config.h"

//=====[Declarations (prototypes) of public functions]=========================

/**
 * @brief Initializes Bluetooth Communication module.
 * 
 */
void bleComInit();

/**
 * @brief Updates Bluetooth Communication.
 * 
 */
void bleComUpdate();

/**
 * @brief Sends a string through Bluetooth.
 * 
 * @param[in] s String to send.
 */
void bleComStringWrite(const char* s);

#endif // _BLE_COM_H_
