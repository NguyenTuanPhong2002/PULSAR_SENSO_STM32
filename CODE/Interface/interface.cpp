/*
 * interface.cpp
 *
 *  Created on: Jan 25, 2024
 *      Author: ACER
 */


#include "interface.h"

interface *interface::instancePtr = nullptr;

interface::interface(/* args */)
{
}

interface::~interface()
{
}

void interface::initMain(void){
    //logData::getInstance()->LogInfor("init");
	LOGI("MCU %s","start");
}
