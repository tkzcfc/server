//
//  DUScheduler.hpp
//  NNNN
//
//  Created by ·½³Ì on 16/11/14.
//  Copyright ? 2016Äê lianshi. All rights reserved.
//


#ifndef DUScheduler_hpp
#define DUScheduler_hpp


#include <string>
#include <vector>
#include <mutex>
#include "uthash.h"
#include "DUSchedulerTimer.h"


struct HashSchedulerUpdateEntry;

class DUScheduler : public DUObject
{
    static DUScheduler* DUSchedulerInstance;
    DUScheduler();
public:
    
    static DUScheduler* GetInstance();
    
    ~DUScheduler();
    
    void Update(float delay);
    
public:
    
    //add
    void Schedule(DUScheduler_SEL pfnSelector, DUObject *pTarget, float fInterval, unsigned int repeat, float delay, bool paused = false, bool infinite = false);
    
    void Schedule(DUScheduler_SEL pfnSelector, DUObject *pTarget, float fInterval, bool bPaused = false);
    
    void ScheduleSelector(const duSchedulerFunc& callback, void *target, float interval, unsigned int repeat, float delay, bool paused, const std::string& key, bool infinite = false);
    
    void ScheduleSelector(const duSchedulerFunc& callback, void *target, float interval, bool paused, const std::string& key);
    
    void ScheduleSelector(const duSchedulerFunc& callback, float interval, unsigned int repeat, float delay, bool paused, const std::string& key, bool infinite = false);
    
    void ScheduleSelector(const duSchedulerFunc& callback, float interval, bool paused, const std::string& key);
    
    //pause
    void PauseSchedule(DUObject* pTarget);
    
    void PauseSchedule(DUObject *pTarget, DUScheduler_SEL pfnSelector);
    
    void PauseSchedule(void *pTarget, const std::string& key);
    
    void PauseSchedule(const std::string& key);
    
    //resume
    void ResumeSchedule(DUObject* pTarget);
    
    void ResumeSchedule(DUObject *pTarget, DUScheduler_SEL pfnSelector);
    
    void ResumeSchedule(void *pTarget, const std::string& key);
    
    void ResumeSchedule(const std::string& key);
    
    //cancel
    void UnScheduleBySelector(DUScheduler_SEL pfnSelector, DUObject *pTarget);
    
    void UnScheduleByObject(DUObject *pTarget);
    
    void UnScheduleSeletorByKey(void *pTarget, const std::string& key);
    
    void UnScheduleSeletorByKey(const std::string& key);
    
    void UnScheduleSeletorByObject(void *pTarget);
    
    void UnScheduleAll();
    
protected:
    
    void addTimerForHashMap(DUObject *pTarget, SchedulerTimer* timerData);
    
    SchedulerTimerPtr findSchedulerTimer(HashSchedulerUpdateEntry* hashMap, DUObject *pTarget, SchedulerTimerPtr timer);
    
    void ClearOperationEntry();
    
    void RemoveEntryFormHash(HashSchedulerUpdateEntry* entry);
    
protected:
    
    struct HashSchedulerUpdateEntry* m_CurrentRunEntry;
    struct HashSchedulerUpdateEntry* m_OperationEntry;
    
    std::mutex m_Mutex;
};

#endif /* DUScheduler_hpp */
