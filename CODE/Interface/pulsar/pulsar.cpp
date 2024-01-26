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

