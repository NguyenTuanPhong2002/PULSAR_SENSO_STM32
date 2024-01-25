/*
 * logData.h
 *
 *  Created on: Jan 25, 2024
 *      Author: ACER
 */

#ifndef LOGDATA_H_
#define LOGDATA_H_
#include "main.h"

class logData
{
private:
    /* data */
    logData *instancePtr;

    struct logDataConfig
    {
        /* data */
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
