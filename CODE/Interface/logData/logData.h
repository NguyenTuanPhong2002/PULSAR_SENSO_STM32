/*
 * logData.h
 *
 *  Created on: Jan 25, 2024
 *      Author: ACER
 */

#ifndef LOGDATA_H_
#define LOGDATA_H_

#include "main.h"

extern UART_HandleTypeDef huart5;

#define LOGI(comment, ...) LogInfor(comment, __VA_ARGS__)

class logData
{
private:
    /* data */
    logData *instancePtr;

    struct logDataConfig
    {
        /* data */
        UART_HandleTypeDef *uart{&huart5};
    };

    logData(/* args */);
    ~logData();

public:
    logData *getInstance()
    {
        if (instancePtr == nullptr)
        {
            instancePtr = new logData;
        }
        return instancePtr;
    }
};

#endif /* LOGDATA_H_ */
