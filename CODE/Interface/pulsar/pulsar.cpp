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

void pulsar::modbusOnPower()
{
	HAL_GPIO_WritePin(config.powerPin.Port, config.powerPin.pin, GPIO_PIN_SET);
}

void pulsar::modbusOffPower()
{
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

void pulsar::modbusTransmit()
{
	modbusOnPower();
	HAL_GPIO_WritePin(config.DEPin.Port, config.DEPin.pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(config.REPin.Port, config.REPin.pin, GPIO_PIN_RESET);
}

void pulsar::modbusReceive()
{
	modbusOnPower();
	HAL_GPIO_WritePin(config.DEPin.Port, config.DEPin.pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(config.REPin.Port, config.REPin.pin, GPIO_PIN_SET);
}

void pulsar::modbusOff()
{
	HAL_GPIO_WritePin(config.DEPin.Port, config.DEPin.pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(config.REPin.Port, config.REPin.pin, GPIO_PIN_RESET);
	modbusOffPower();
}


/**
 * The function calculates a CRC (Cyclic Redundancy Check) value for a given data array using the
 * CRC-16 algorithm.
 * 
 * @param data A pointer to an array of uint8_t (unsigned 8-bit integer) values, representing the data
 * for which the CRC (Cyclic Redundancy Check) needs to be calculated.
 * @param length The "length" parameter represents the number of bytes in the "data" array that you
 * want to calculate the CRC for.
 * 
 * @return a uint16_t value, which is an unsigned 16-bit integer.
 */
uint16_t calculateCRC(uint8_t *data, int length)
{
	uint16_t crc = 0xFFFF;
	for (int i = 0; i < length; i++)
	{
		crc ^= data[i];
		for (int j = 0; j < 8; j++)
		{
			if (crc & 0x0001)
			{
				crc = (crc >> 1) ^ 0xA001;
			}
			else
			{
				crc = crc >> 1;
			}
		}
	}
	return crc;
}