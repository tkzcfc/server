//
//  DUScheduler.cpp
//  NNNN
//
//  Created by ·½³Ì on 16/11/14.
//  Copyright ? 2016Äê lianshi. All rights reserved.
//

#include "DUScheduler.h"

#define OPEN_DEBUG_SCHEDULER 1


#define SCHEDULER_TIMER_ITERATOR(vec)\
std::vector<SchedulerTimerPtr>::iterator itTimer;\
for(itTimer = vec.begin(); itTimer != vec.end(); ++itTimer)


typedef struct HashSchedulerUpdateEntry
{
    //Key
    void* Target;
    //Value
    std::vector<SchedulerTimerPtr> Timer;
    //Attribute
    bool Pause;
    bool Delete;
    //Hash
    UT_hash_handle hh;
}HashSchedulerUpdateEntry_t;


//******************

DUScheduler* DUScheduler::DUSchedulerInstance = NULL;

DUScheduler* DUScheduler::GetInstance()
{
    if(DUSchedulerInstance == NULL)
    {
        DUSchedulerInstance = new DUScheduler();
    }
    return DUSchedulerInstance;
}

DUScheduler::DUScheduler()
{
    m_CurrentRunEntry = NULL;
    m_OperationEntry = NULL;
}

DUScheduler::~DUScheduler()
{
    ClearOperationEntry();
    HashSchedulerUpdateEntry* data, *tmp;
    HASH_ITER(hh, m_CurrentRunEntry, data, tmp)
    {
        RemoveEntryFormHash(data);
    }
}

void DUScheduler::Update(float delay)
{
    ClearOperationEntry();
    HashSchedulerUpdateEntry* data, *tmp;
    HASH_ITER(hh, m_CurrentRunEntry, data, tmp)
    {
        if(data->Delete || data->Pause)
            continue;
        SCHEDULER_TIMER_ITERATOR(data->Timer)
        {
            (*itTimer)->update(delay);
        }
    }
}

void DUScheduler::Schedule(DUScheduler_SEL pfnSelector, DUObject *pTarget, float fInterval, unsigned int repeat, float delay, bool paused/* = false*/, bool infinite/* = false*/)
{
    if(pfnSelector == NULL || pTarget == NULL)
        return;
    TimerTargetSelector* selectorData = new TimerTargetSelector();
    selectorData->Init(this, pfnSelector, pTarget, fInterval, repeat, delay, infinite, paused);
    addTimerForHashMap(pTarget, selectorData);
    selectorData->Release();
}

void DUScheduler::Schedule(DUScheduler_SEL pfnSelector, DUObject *pTarget, float fInterval, bool bPaused/* = false*/)
{
    this->Schedule(pfnSelector, pTarget, fInterval, 0, 0.0f, bPaused, true);
}

void DUScheduler::ScheduleSelector(const duSchedulerFunc& callback, void *target, float interval, unsigned int repeat, float delay, bool paused, const std::string& key, bool infinite/* = false*/)
{
    if(callback == NULL)
        return;
    DU_ASSERT(key != "");
    TimerTargetCallback* callbackData = new TimerTargetCallback();
    callbackData->Init(this, callback, target, key, interval, repeat, delay, infinite, paused);
    addTimerForHashMap((DUObject*)target, callbackData);
    callbackData->Release();
}

void DUScheduler::ScheduleSelector(const duSchedulerFunc& callback, void *target, float interval, bool paused, const std::string& key)
{
    this->ScheduleSelector(callback, target, interval, 0, 0.0f, paused, key, true);
}

void DUScheduler::ScheduleSelector(const duSchedulerFunc& callback, float interval, unsigned int repeat, float delay, bool paused, const std::string& key, bool infinite/* = false*/)
{
    this->ScheduleSelector(callback, NULL, interval, repeat, delay, paused, key, infinite);
}

void DUScheduler::ScheduleSelector(const duSchedulerFunc& callback, float interval, bool paused, const std::string& key)
{
    this->ScheduleSelector(callback, NULL, interval, 0, 0.0f, paused, key, true);
}

//pause
void DUScheduler::PauseSchedule(DUObject* pTarget)
{
    std::vector<SchedulerTimerPtr>::iterator itTimer;
    HashSchedulerUpdateEntry *data, *tmp;
    HASH_ITER(hh, m_CurrentRunEntry, data, tmp)
    {
        if(data->Target == (void*)pTarget)
        {
            data->Pause = true;
            for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); ++itTimer)
            {
                (*itTimer)->m_Paused = true;
            }
        }
    }
    HASH_ITER(hh, m_OperationEntry, data, tmp)
    {
        if(data->Target == (void*)pTarget)
        {
            data->Pause = true;
            for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); ++itTimer)
            {
                (*itTimer)->m_Paused = true;
            }
        }
    }
}

void DUScheduler::PauseSchedule(DUObject *pTarget, DUScheduler_SEL pfnSelector)
{
    std::vector<SchedulerTimerPtr>::iterator itTimer;
    HashSchedulerUpdateEntry *data, *tmp;
    
    HASH_ITER(hh, m_CurrentRunEntry, data, tmp)
    {
        if(data->Target == (void*)pTarget)
        {
            for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); ++itTimer)
            {
                if((*itTimer)->isEqual(pfnSelector, pTarget))
                {
                    (*itTimer)->m_Paused = true;
                }
            }
        }
    }
    HASH_ITER(hh, m_OperationEntry, data, tmp)
    {
        if(data->Target == (void*)pTarget)
        {
            for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); ++itTimer)
            {
                if((*itTimer)->isEqual(pfnSelector, pTarget))
                {
                    (*itTimer)->m_Paused = true;
                }
            }
        }
    }
}

void DUScheduler::PauseSchedule(void *pTarget, const std::string& key)
{
    std::vector<SchedulerTimerPtr>::iterator itTimer;
    HashSchedulerUpdateEntry *data, *tmp;
    
    HASH_ITER(hh, m_CurrentRunEntry, data, tmp)
    {
        if(data->Target == (void*)pTarget)
        {
            for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); ++itTimer)
            {
                if((*itTimer)->isEqual(pTarget, key))
                {
                    (*itTimer)->m_Paused = true;
                }
            }
        }
    }
    HASH_ITER(hh, m_OperationEntry, data, tmp)
    {
        if(data->Target == (void*)pTarget)
        {
            for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); ++itTimer)
            {
                if((*itTimer)->isEqual(pTarget, key))
                {
                    (*itTimer)->m_Paused = true;
                }
            }
        }
    }
}

void DUScheduler::PauseSchedule(const std::string& key)
{
    this->PauseSchedule(NULL, key);
}

//resume
void DUScheduler::ResumeSchedule(DUObject* pTarget)
{
    std::vector<SchedulerTimerPtr>::iterator itTimer;
    HashSchedulerUpdateEntry *data, *tmp;
    
    HASH_ITER(hh, m_CurrentRunEntry, data, tmp)
    {
        if(data->Target == (void*)pTarget)
        {
            data->Pause = false;
            for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); ++itTimer)
            {
                (*itTimer)->m_Paused = false;
            }
        }
    }
    HASH_ITER(hh, m_OperationEntry, data, tmp)
    {
        if(data->Target == (void*)pTarget)
        {
            data->Pause = false;
            for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); ++itTimer)
            {
                (*itTimer)->m_Paused = false;
            }
        }
    }
}

void DUScheduler::ResumeSchedule(DUObject *pTarget, DUScheduler_SEL pfnSelector)
{
    std::vector<SchedulerTimerPtr>::iterator itTimer;
    HashSchedulerUpdateEntry *data, *tmp;
    
    HASH_ITER(hh, m_CurrentRunEntry, data, tmp)
    {
        if(data->Target == (void*)pTarget)
        {
            data->Pause = false;
            for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); ++itTimer)
            {
                if((*itTimer)->isEqual(pfnSelector, pTarget))
                {
                    (*itTimer)->m_Paused = false;
                }
            }
        }
    }
    HASH_ITER(hh, m_OperationEntry, data, tmp)
    {
        if(data->Target == (void*)pTarget)
        {
            data->Pause = false;
            for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); ++itTimer)
            {
                if((*itTimer)->isEqual(pfnSelector, pTarget))
                {
                    (*itTimer)->m_Paused = false;
                }
            }
        }
    }
}

void DUScheduler::ResumeSchedule(void *pTarget, const std::string& key)
{
    std::vector<SchedulerTimerPtr>::iterator itTimer;
    HashSchedulerUpdateEntry *data, *tmp;
    
    HASH_ITER(hh, m_CurrentRunEntry, data, tmp)
    {
        if(data->Target == (void*)pTarget)
        {
            data->Pause = false;
            for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); ++itTimer)
            {
                if((*itTimer)->isEqual(pTarget, key))
                {
                    (*itTimer)->m_Paused = false;
                }
            }
        }
    }
    HASH_ITER(hh, m_OperationEntry, data, tmp)
    {
        if(data->Target == (void*)pTarget)
        {
            data->Pause = false;
            for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); ++itTimer)
            {
                if((*itTimer)->isEqual(pTarget, key))
                {
                    (*itTimer)->m_Paused = false;
                }
            }
        }
    }
}

void DUScheduler::ResumeSchedule(const std::string& key)
{
    this->ResumeSchedule(NULL, key);
}

//cancel
void DUScheduler::UnScheduleBySelector(DUScheduler_SEL pfnSelector, DUObject *pTarget)
{
    HashSchedulerUpdateEntry* hashData;
    SchedulerTimerPtr curTimer = NULL;
    HASH_FIND_PTR(m_CurrentRunEntry, &pTarget, hashData);
    if(hashData)
    {
        SCHEDULER_TIMER_ITERATOR(hashData->Timer)
        {
            curTimer = (*itTimer);
            if(curTimer->isEqual(pfnSelector, pTarget))
            {
                curTimer->m_Delete = true;
            }
        }
    }
    HASH_FIND_PTR(m_OperationEntry, &pTarget, hashData);
    if(hashData)
    {
        SCHEDULER_TIMER_ITERATOR(hashData->Timer)
        {
            curTimer = (*itTimer);
            if(curTimer->isEqual(pfnSelector, pTarget))
            {
                curTimer->m_Delete = true;
            }
        }
    }
}

void DUScheduler::UnScheduleByObject(DUObject *pTarget)
{
    HashSchedulerUpdateEntry* hashData;
    HASH_FIND_PTR(m_CurrentRunEntry, &pTarget, hashData);
    if(hashData)
    {
        SCHEDULER_TIMER_ITERATOR(hashData->Timer)
        {
            (*itTimer)->m_Delete = true;
        }
    }
    HASH_FIND_PTR(m_OperationEntry, &pTarget, hashData);
    if(hashData)
    {
        SCHEDULER_TIMER_ITERATOR(hashData->Timer)
        {
            (*itTimer)->m_Delete = true;
        }
    }
}

void DUScheduler::UnScheduleSeletorByKey(void *pTarget, const std::string& key)
{
    HashSchedulerUpdateEntry* hashData;
    SchedulerTimerPtr curTimer = NULL;
    HASH_FIND_PTR(m_CurrentRunEntry, &pTarget, hashData);
    if(hashData)
    {
        SCHEDULER_TIMER_ITERATOR(hashData->Timer)
        {
            curTimer = (*itTimer);
            if(curTimer->isEqual(pTarget, key))
            {
                curTimer->m_Delete = true;
            }
#if OPEN_DEBUG_SCHEDULER == 1
            else
            {
                DU_LOG("no equal\n");
            }
#endif
        }
    }
    HASH_FIND_PTR(m_OperationEntry, &pTarget, hashData);
    if(hashData)
    {
        SCHEDULER_TIMER_ITERATOR(hashData->Timer)
        {
            curTimer = (*itTimer);
            if(curTimer->isEqual(pTarget, key))
            {
                curTimer->m_Delete = true;
            }
        }
    }
}

void DUScheduler::UnScheduleSeletorByKey(const std::string& key)
{
    this->UnScheduleSeletorByKey(NULL, key);
}

void DUScheduler::UnScheduleSeletorByObject(void *pTarget)
{
    HashSchedulerUpdateEntry* hashData;
    HASH_FIND_PTR(m_CurrentRunEntry, &pTarget, hashData);
    if(hashData)
    {
        SCHEDULER_TIMER_ITERATOR(hashData->Timer)
        {
            (*itTimer)->m_Delete = true;
        }
    }
    HASH_FIND_PTR(m_OperationEntry, &pTarget, hashData);
    if(hashData)
    {
        SCHEDULER_TIMER_ITERATOR(hashData->Timer)
        {
            (*itTimer)->m_Delete = true;
        }
    }
}

void DUScheduler::UnScheduleAll()
{
    HashSchedulerUpdateEntry *data, *tmp;
    HASH_ITER(hh, m_CurrentRunEntry, data, tmp)
    {
        data->Delete = true;
    }
    HASH_ITER(hh, m_OperationEntry, data, tmp)
    {
        data->Delete = true;
    }
}

void DUScheduler::ClearOperationEntry()
{
    std::vector<SchedulerTimerPtr>::iterator itTimer;
    HashSchedulerUpdateEntry *data, *tmp, *curData;
    SchedulerTimerPtr timerTmp = NULL;
    
    HASH_ITER(hh, m_CurrentRunEntry, data, tmp)
    {
        if(data->Delete)
        {
            RemoveEntryFormHash(data);
#if OPEN_DEBUG_SCHEDULER == 1
            DU_LOG("remove running data from hash Map\n");
#endif
        }
        else
        {
            for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); )
            {
                timerTmp = (*itTimer);
                if(timerTmp->m_Delete)
                {
                    timerTmp->PrintCount();
                    itTimer = data->Timer.erase(itTimer);
                    timerTmp->PrintCount();
#if OPEN_DEBUG_SCHEDULER == 1
                    DU_LOG("remove timer\n");
#endif
                }
                else
                {
                    itTimer++;
                }
            }
        }
    }
    timerTmp = NULL;
    if(HASH_COUNT(m_OperationEntry) <= 0)
        return;
#if OPEN_DEBUG_SCHEDULER == 1
    DU_LOG("m_OperationEntry hash Map count is : %d\n", HASH_COUNT(m_OperationEntry));
#endif
    //m_Mutex.lock();
    HASH_ITER(hh, m_OperationEntry, data, tmp)
    {
        HASH_FIND_PTR(m_CurrentRunEntry, &data->Target, curData);
        for(itTimer = data->Timer.begin(); itTimer != data->Timer.end(); )
        {
            timerTmp = (*itTimer);
            if(timerTmp->m_Delete == false)
            {
                if(curData)
                {
                    curData->Timer.push_back(*itTimer);
                }
                else
                {
                    curData = new HashSchedulerUpdateEntry();
                    curData->Delete = false;
                    curData->Pause = false;
                    curData->Target = data->Target;
                    curData->Timer.push_back(timerTmp);
                    HASH_ADD_PTR(m_CurrentRunEntry, Target, curData);
#if OPEN_DEBUG_SCHEDULER == 1
                    DU_LOG("Add new Data\n");
#endif
                }
                itTimer++;
            }
            else
            {
                itTimer = data->Timer.erase(itTimer);
            }
        }
    }
    HASH_ITER(hh, m_OperationEntry, data, tmp)
    {
        HASH_DELETE(hh, m_OperationEntry, data);
        DU_SAFE_DELETE(data);
    }
    //m_Mutex.unlock();
}

void DUScheduler::RemoveEntryFormHash(HashSchedulerUpdateEntry* entry)
{
    entry->Timer.clear();
    HASH_DELETE(hh, m_CurrentRunEntry, entry);
    DU_SAFE_DELETE(entry);
}

void DUScheduler::addTimerForHashMap(DUObject *pTarget, SchedulerTimer* timerData)
{
    SchedulerTimerPtr timer = findSchedulerTimer(m_CurrentRunEntry, pTarget, timerData);
    if(timer.GetPtr() && timer->m_Delete == false)
    {
        return;
    }
    timer = findSchedulerTimer(m_OperationEntry, pTarget, timerData);
    HashSchedulerUpdateEntry* hashData = NULL;
    if(timer == NULL)
    {
        hashData = new HashSchedulerUpdateEntry();
        hashData->Delete = false;
        hashData->Pause = false;
        hashData->Target = pTarget;
        hashData->Timer.push_back(timerData);
        m_Mutex.lock();
        HASH_ADD_PTR(m_OperationEntry, Target, hashData);
        m_Mutex.unlock();
    }
    else if(timer->m_Delete == false)
    {
        return;
    }
    else
    {
        HashSchedulerUpdateEntry* hashData;
        HASH_FIND_PTR(m_OperationEntry, &pTarget, hashData);
        if(hashData)
        {
            //m_Mutex.lock();
            hashData->Timer.push_back(timerData);
            //m_Mutex.unlock();
        }
    }
}

SchedulerTimerPtr DUScheduler::findSchedulerTimer(HashSchedulerUpdateEntry* hashMap, DUObject *pTarget, SchedulerTimerPtr timer)
{
    if(hashMap == NULL)
        return NULL;
    HashSchedulerUpdateEntry* hashData;
    HASH_FIND_PTR(hashMap, &pTarget, hashData);
    if(hashData)
    {
        std::vector<SchedulerTimerPtr>::iterator it;
        for(it = hashData->Timer.begin(); it != hashData->Timer.end(); ++it)
        {
            if((*it)->isEqual(timer))
            {
                return *it;
            }
        }
    }
    return NULL;
}
