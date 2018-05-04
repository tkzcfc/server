/*
** Lua binding: dubase
** Generated automatically by tolua++-1.0.92 on 05/04/18 12:12:50.
*/

#include "tolua_fix.h"
#include "tolua++.h"
#include <string>


/* Exported function */
TOLUA_API int  tolua_dubase_open (lua_State* tolua_S);

#include "DUObject.h"
#include "DUScheduler.h"
#include "DUServer.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_DUServer (lua_State* tolua_S)
{
 DUServer* self = (DUServer*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_DUObject (lua_State* tolua_S)
{
 DUObject* self = (DUObject*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"DUScheduler");
 tolua_usertype(tolua_S,"DUObject");
 
 tolua_usertype(tolua_S,"DUServer");
}

/* method: new of class  DUObject */
#ifndef TOLUA_DISABLE_tolua_dubase_DUObject_new00
static int tolua_dubase_DUObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DUObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DUObject* tolua_ret = (DUObject*)  Mtolua_new((DUObject)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DUObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  DUObject */
#ifndef TOLUA_DISABLE_tolua_dubase_DUObject_new00_local
static int tolua_dubase_DUObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DUObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DUObject* tolua_ret = (DUObject*)  Mtolua_new((DUObject)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DUObject");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  DUObject */
#ifndef TOLUA_DISABLE_tolua_dubase_DUObject_delete00
static int tolua_dubase_DUObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUObject* self = (DUObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Retain of class  DUObject */
#ifndef TOLUA_DISABLE_tolua_dubase_DUObject_Retain00
static int tolua_dubase_DUObject_Retain00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUObject* self = (DUObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Retain'", NULL);
#endif
  {
   DUObject* tolua_ret = (DUObject*)  self->Retain();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DUObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Retain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Release of class  DUObject */
#ifndef TOLUA_DISABLE_tolua_dubase_DUObject_Release00
static int tolua_dubase_DUObject_Release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUObject* self = (DUObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Release'", NULL);
#endif
  {
   self->Release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PrintCount of class  DUObject */
#ifndef TOLUA_DISABLE_tolua_dubase_DUObject_PrintCount00
static int tolua_dubase_DUObject_PrintCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUObject* self = (DUObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PrintCount'", NULL);
#endif
  {
   self->PrintCount();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PrintCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetInstance of class  DUScheduler */
#ifndef TOLUA_DISABLE_tolua_dubase_DUScheduler_GetInstance00
static int tolua_dubase_DUScheduler_GetInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DUScheduler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DUScheduler* tolua_ret = (DUScheduler*)  DUScheduler::GetInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DUScheduler");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PauseSchedule of class  DUScheduler */
#ifndef TOLUA_DISABLE_tolua_dubase_DUScheduler_PauseSchedule00
static int tolua_dubase_DUScheduler_PauseSchedule00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUScheduler",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"DUObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUScheduler* self = (DUScheduler*)  tolua_tousertype(tolua_S,1,0);
  DUObject* pTarget = ((DUObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PauseSchedule'", NULL);
#endif
  {
   self->PauseSchedule(pTarget);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PauseSchedule'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PauseSchedule of class  DUScheduler */
#ifndef TOLUA_DISABLE_tolua_dubase_DUScheduler_PauseSchedule01
static int tolua_dubase_DUScheduler_PauseSchedule01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUScheduler",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  DUScheduler* self = (DUScheduler*)  tolua_tousertype(tolua_S,1,0);
  void* pTarget = ((void*)  tolua_touserdata(tolua_S,2,0));
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PauseSchedule'", NULL);
#endif
  {
   self->PauseSchedule(pTarget,key);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
tolua_lerror:
 return tolua_dubase_DUScheduler_PauseSchedule00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: PauseSchedule of class  DUScheduler */
#ifndef TOLUA_DISABLE_tolua_dubase_DUScheduler_PauseSchedule02
static int tolua_dubase_DUScheduler_PauseSchedule02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUScheduler",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  DUScheduler* self = (DUScheduler*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PauseSchedule'", NULL);
#endif
  {
   self->PauseSchedule(key);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
tolua_lerror:
 return tolua_dubase_DUScheduler_PauseSchedule01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResumeSchedule of class  DUScheduler */
#ifndef TOLUA_DISABLE_tolua_dubase_DUScheduler_ResumeSchedule00
static int tolua_dubase_DUScheduler_ResumeSchedule00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUScheduler",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"DUObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUScheduler* self = (DUScheduler*)  tolua_tousertype(tolua_S,1,0);
  DUObject* pTarget = ((DUObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResumeSchedule'", NULL);
#endif
  {
   self->ResumeSchedule(pTarget);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResumeSchedule'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResumeSchedule of class  DUScheduler */
#ifndef TOLUA_DISABLE_tolua_dubase_DUScheduler_ResumeSchedule01
static int tolua_dubase_DUScheduler_ResumeSchedule01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUScheduler",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  DUScheduler* self = (DUScheduler*)  tolua_tousertype(tolua_S,1,0);
  void* pTarget = ((void*)  tolua_touserdata(tolua_S,2,0));
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResumeSchedule'", NULL);
#endif
  {
   self->ResumeSchedule(pTarget,key);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
tolua_lerror:
 return tolua_dubase_DUScheduler_ResumeSchedule00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResumeSchedule of class  DUScheduler */
#ifndef TOLUA_DISABLE_tolua_dubase_DUScheduler_ResumeSchedule02
static int tolua_dubase_DUScheduler_ResumeSchedule02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUScheduler",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  DUScheduler* self = (DUScheduler*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResumeSchedule'", NULL);
#endif
  {
   self->ResumeSchedule(key);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
tolua_lerror:
 return tolua_dubase_DUScheduler_ResumeSchedule01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnScheduleByObject of class  DUScheduler */
#ifndef TOLUA_DISABLE_tolua_dubase_DUScheduler_UnScheduleByObject00
static int tolua_dubase_DUScheduler_UnScheduleByObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUScheduler",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"DUObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUScheduler* self = (DUScheduler*)  tolua_tousertype(tolua_S,1,0);
  DUObject* pTarget = ((DUObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UnScheduleByObject'", NULL);
#endif
  {
   self->UnScheduleByObject(pTarget);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnScheduleByObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnScheduleSeletorByKey of class  DUScheduler */
#ifndef TOLUA_DISABLE_tolua_dubase_DUScheduler_UnScheduleSeletorByKey00
static int tolua_dubase_DUScheduler_UnScheduleSeletorByKey00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUScheduler",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUScheduler* self = (DUScheduler*)  tolua_tousertype(tolua_S,1,0);
  void* pTarget = ((void*)  tolua_touserdata(tolua_S,2,0));
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UnScheduleSeletorByKey'", NULL);
#endif
  {
   self->UnScheduleSeletorByKey(pTarget,key);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnScheduleSeletorByKey'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnScheduleSeletorByKey of class  DUScheduler */
#ifndef TOLUA_DISABLE_tolua_dubase_DUScheduler_UnScheduleSeletorByKey01
static int tolua_dubase_DUScheduler_UnScheduleSeletorByKey01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUScheduler",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  DUScheduler* self = (DUScheduler*)  tolua_tousertype(tolua_S,1,0);
  const std::string key = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UnScheduleSeletorByKey'", NULL);
#endif
  {
   self->UnScheduleSeletorByKey(key);
   tolua_pushcppstring(tolua_S,(const char*)key);
  }
 }
 return 1;
tolua_lerror:
 return tolua_dubase_DUScheduler_UnScheduleSeletorByKey00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnScheduleSeletorByObject of class  DUScheduler */
#ifndef TOLUA_DISABLE_tolua_dubase_DUScheduler_UnScheduleSeletorByObject00
static int tolua_dubase_DUScheduler_UnScheduleSeletorByObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUScheduler",0,&tolua_err) ||
     !tolua_isuserdata(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUScheduler* self = (DUScheduler*)  tolua_tousertype(tolua_S,1,0);
  void* pTarget = ((void*)  tolua_touserdata(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UnScheduleSeletorByObject'", NULL);
#endif
  {
   self->UnScheduleSeletorByObject(pTarget);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnScheduleSeletorByObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UnScheduleAll of class  DUScheduler */
#ifndef TOLUA_DISABLE_tolua_dubase_DUScheduler_UnScheduleAll00
static int tolua_dubase_DUScheduler_UnScheduleAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUScheduler",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUScheduler* self = (DUScheduler*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UnScheduleAll'", NULL);
#endif
  {
   self->UnScheduleAll();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UnScheduleAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  DUServer */
#ifndef TOLUA_DISABLE_tolua_dubase_DUServer_new00
static int tolua_dubase_DUServer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DUServer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DUServer* tolua_ret = (DUServer*)  Mtolua_new((DUServer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DUServer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  DUServer */
#ifndef TOLUA_DISABLE_tolua_dubase_DUServer_new00_local
static int tolua_dubase_DUServer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DUServer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DUServer* tolua_ret = (DUServer*)  Mtolua_new((DUServer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DUServer");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  DUServer */
#ifndef TOLUA_DISABLE_tolua_dubase_DUServer_delete00
static int tolua_dubase_DUServer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUServer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUServer* self = (DUServer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: startServer of class  DUServer */
#ifndef TOLUA_DISABLE_tolua_dubase_DUServer_startServer00
static int tolua_dubase_DUServer_startServer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUServer",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUServer* self = (DUServer*)  tolua_tousertype(tolua_S,1,0);
  const char* ip = ((const char*)  tolua_tostring(tolua_S,2,0));
  int port = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'startServer'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->startServer(ip,port);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'startServer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: closeServer of class  DUServer */
#ifndef TOLUA_DISABLE_tolua_dubase_DUServer_closeServer00
static int tolua_dubase_DUServer_closeServer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUServer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUServer* self = (DUServer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'closeServer'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->closeServer();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'closeServer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isCloseFinish of class  DUServer */
#ifndef TOLUA_DISABLE_tolua_dubase_DUServer_isCloseFinish00
static int tolua_dubase_DUServer_isCloseFinish00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUServer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUServer* self = (DUServer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isCloseFinish'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isCloseFinish();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isCloseFinish'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCallFunc of class  DUServer */
#ifndef TOLUA_DISABLE_tolua_dubase_DUServer_setCallFunc00
static int tolua_dubase_DUServer_setCallFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DUServer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LuaFunction",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DUServer* self = (DUServer*)  tolua_tousertype(tolua_S,1,0);
  LuaFunction handle = (  LuaFunction(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCallFunc'", NULL);
#endif
  {
   self->setCallFunc(handle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCallFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_dubase_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"DUObject","DUObject","",tolua_collect_DUObject);
  #else
  tolua_cclass(tolua_S,"DUObject","DUObject","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"DUObject");
   tolua_function(tolua_S,"new",tolua_dubase_DUObject_new00);
   tolua_function(tolua_S,"new_local",tolua_dubase_DUObject_new00_local);
   tolua_function(tolua_S,".call",tolua_dubase_DUObject_new00_local);
   tolua_function(tolua_S,"delete",tolua_dubase_DUObject_delete00);
   tolua_function(tolua_S,"Retain",tolua_dubase_DUObject_Retain00);
   tolua_function(tolua_S,"Release",tolua_dubase_DUObject_Release00);
   tolua_function(tolua_S,"PrintCount",tolua_dubase_DUObject_PrintCount00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"DUScheduler","DUScheduler","DUObject",NULL);
  tolua_beginmodule(tolua_S,"DUScheduler");
   tolua_function(tolua_S,"GetInstance",tolua_dubase_DUScheduler_GetInstance00);
   tolua_function(tolua_S,"PauseSchedule",tolua_dubase_DUScheduler_PauseSchedule00);
   tolua_function(tolua_S,"PauseSchedule",tolua_dubase_DUScheduler_PauseSchedule01);
   tolua_function(tolua_S,"PauseSchedule",tolua_dubase_DUScheduler_PauseSchedule02);
   tolua_function(tolua_S,"ResumeSchedule",tolua_dubase_DUScheduler_ResumeSchedule00);
   tolua_function(tolua_S,"ResumeSchedule",tolua_dubase_DUScheduler_ResumeSchedule01);
   tolua_function(tolua_S,"ResumeSchedule",tolua_dubase_DUScheduler_ResumeSchedule02);
   tolua_function(tolua_S,"UnScheduleByObject",tolua_dubase_DUScheduler_UnScheduleByObject00);
   tolua_function(tolua_S,"UnScheduleSeletorByKey",tolua_dubase_DUScheduler_UnScheduleSeletorByKey00);
   tolua_function(tolua_S,"UnScheduleSeletorByKey",tolua_dubase_DUScheduler_UnScheduleSeletorByKey01);
   tolua_function(tolua_S,"UnScheduleSeletorByObject",tolua_dubase_DUScheduler_UnScheduleSeletorByObject00);
   tolua_function(tolua_S,"UnScheduleAll",tolua_dubase_DUScheduler_UnScheduleAll00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"DUServer","DUServer","DUObject",tolua_collect_DUServer);
  #else
  tolua_cclass(tolua_S,"DUServer","DUServer","DUObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"DUServer");
   tolua_function(tolua_S,"new",tolua_dubase_DUServer_new00);
   tolua_function(tolua_S,"new_local",tolua_dubase_DUServer_new00_local);
   tolua_function(tolua_S,".call",tolua_dubase_DUServer_new00_local);
   tolua_function(tolua_S,"delete",tolua_dubase_DUServer_delete00);
   tolua_function(tolua_S,"startServer",tolua_dubase_DUServer_startServer00);
   tolua_function(tolua_S,"closeServer",tolua_dubase_DUServer_closeServer00);
   tolua_function(tolua_S,"isCloseFinish",tolua_dubase_DUServer_isCloseFinish00);
   tolua_function(tolua_S,"setCallFunc",tolua_dubase_DUServer_setCallFunc00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_dubase (lua_State* tolua_S) {
 return tolua_dubase_open(tolua_S);
};
#endif

