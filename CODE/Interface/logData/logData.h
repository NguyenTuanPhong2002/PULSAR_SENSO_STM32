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
#pragma once

#define LOGI(comment, ...) logData::getInstance()->LogInfor(comment, __VA_ARGS__)
#define LOGW(comment, ...) logData::getInstance()->LogWarning(comment, __VA_ARGS__)
#define LOGE(comment, ...) logData::getInstance()->LogError(comment, __VA_ARGS__)

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
    
    void LogInfor(const char *format, ...);
    void LogWarning(const char *format, ...);
    void LogError(const char *format, ...);
};

#endif /* LOGDATA_H_ */
