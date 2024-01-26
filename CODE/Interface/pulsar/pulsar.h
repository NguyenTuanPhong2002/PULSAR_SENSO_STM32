/*
 * pulsar.h
 *
 *  Created on: Jan 26, 2024
 *      Author: ACER
 */

#ifndef PULSAR_PULSAR_H_
#define PULSAR_PULSAR_H_

#include "main.h"

extern UART_HandleTypeDef huart3;
extern DMA_HandleTypeDef hdma_usart3_rx;

class pulsar
{
private:
	/* data */
	pulsar(/* args */);
	~pulsar();

	struct pulsarConfig
	{
		/* data */
		UART_HandleTypeDef *uart{&huart3};
		DMA_HandleTypeDef *dma{&hdma_usart3_rx};
	};

	typedef struct modbusData
	{
		/* data */
		uint8_t address = 0x126;	// Device Address
		uint8_t function = 0x03;	// Function Code
		uint16_t startAddr; // Starting Address for data to read
		uint16_t numPoints; // Number of data points to read
		uint16_t crc;		// CRC (Cyclic Redundancy Check)
	};
	static pulsar *instancePtr;

	void modbusOnPower();
	void modbusOffPower();

	void modbusOnTransmit();
	void modbusOffTransmit();
	
	void modbusOnReceive();
	void modbusOffReceive();

public:
	static pulsar *getInstance()
	{
		if (instancePtr == nullptr)
		{
			instancePtr = new pulsar;
		}
		return instancePtr;
	}
};

#endif /* PULSAR_PULSAR_H_ */
