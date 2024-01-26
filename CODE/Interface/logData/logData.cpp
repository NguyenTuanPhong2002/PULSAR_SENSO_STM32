/*
 * logData.c
 *
 *  Created on: Jan 25, 2024
 *      Author: ACER
 */
#include <cstring> // Include the header for strlen
#include <stdio.h>
#include <cstdarg> // Include the necessary header for va_list, va_start, va_end

#include "logData.h"

logData *logData::instancePtr = nullptr;

logData::logData(/* args */)
{
}

logData::~logData()
{
}
