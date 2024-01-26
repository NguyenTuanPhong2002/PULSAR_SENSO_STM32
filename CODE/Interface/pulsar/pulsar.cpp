/*
 * pulsar.cpp
 *
 *  Created on: Jan 26, 2024
 *      Author: ACER
 */

#include "pulsar.h"

pulsar *pulsar::instancePtr = nullptr;

pulsar::pulsar(/* args */)
{
}

pulsar::~pulsar()
{
}


void pulsar::modbusOnPower(){
	HAL_GPIO_WritePin(config.powerPin.Port, config.powerPin.pin, GPIO_PIN_SET);
}

void pulsar::modbusOffPower(){
	HAL_GPIO_WritePin(config.powerPin.Port, config.powerPin.pin, GPIO_PIN_RESET);
}

// + 5V VCC(MAX485)
// │                    │
// ├────────────────────┤
// │                    │
// ├───┐                └── RO(Receiver Output)
// │   │
// │   │
// │   │
// │   └── DI(Driver Input)
// │
// ├────── DE(Driver Enable)
// │
// ├────── RE(Receiver Enable)
// │
// ├── A(A)A(RS485 twisted pair)
// │
// └── B(B)B(RS485 twisted pair)

void pulsar::modbusTransmit(){
	modbusOnPower();
	HAL_GPIO_WritePin(config.DEPin.Port, config.DEPin.pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(config.REPin.Port, config.REPin.pin, GPIO_PIN_RESET);
}

void pulsar::modbusReceive(){
	modbusOnPower();
	HAL_GPIO_WritePin(config.DEPin.Port, config.DEPin.pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(config.REPin.Port, config.REPin.pin, GPIO_PIN_SET);
}

void pulsar::modbusOff(){
	HAL_GPIO_WritePin(config.DEPin.Port, config.DEPin.pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(config.REPin.Port, config.REPin.pin, GPIO_PIN_RESET);
	modbusOffPower();
}