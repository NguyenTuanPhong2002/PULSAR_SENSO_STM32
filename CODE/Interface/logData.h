/*
 * logData.h
 *
 *  Created on: Jan 25, 2024
 *      Author: ACER
 */

#ifndef LOGDATA_H_
#define LOGDATA_H_


class logData
{
private:
    /* data */
    logData *instancePtr;

    logData(/* args */);
    ~logData();

public:
    logData *getInstance(){
        if(instancePtr == nullptr){
            instancePtr = new logData;
        }
        return instancePtr;
    }

};

logData::logData(/* args */)
{
}

logData::~logData()
{
}



#endif /* LOGDATA_H_ */
