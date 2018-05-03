//
//  DUObject.cpp
//  NNNN
//
//  Created by 方程 on 17/1/17.
//  Copyright © 2017年 lianshi. All rights reserved.
//

#include "DUObject.h"
#include "DUScheduler.h"
#include <stdarg.h>

void MyLog(const char* format, ...)
{
    va_list list;
    va_start(list, format);
    vprintf(format, list);
    va_end(list);
}

static unsigned int __objectCount = 0;

DUObject::DUObject()
{
    __objectCount++;
    DU_LOG("object count is %d\n", __objectCount);
    m_Count = 1;
}

DUObject::~DUObject()
{
    DUScheduler::GetInstance()->UnScheduleByObject(this);
    __objectCount--;
    DU_LOG("~object count is %d\n", __objectCount);
}

DUObject* DUObject::Retain()
{
    m_Count++;
    return this;
}

void DUObject::Release()
{
    m_Count--;
    if(m_Count <= 0)
    {
        delete this;
    }
}

void DUObject::PrintCount()
{
    DU_LOG("count is %d\n", m_Count);
}
