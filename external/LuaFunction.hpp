#pragma once

#ifdef __cplusplus
extern "C" {
#endif
#include "lua.h"
#include "lauxlib.h"
#ifdef __cplusplus
}
#endif

#include <string>

class LuaRef {
public:
    LuaRef();
    LuaRef(lua_State* aL, int index);
    virtual ~LuaRef();
    LuaRef(const LuaRef& other);
    LuaRef& operator=(const LuaRef& rhs);
    LuaRef(LuaRef&& other);
    LuaRef& operator=(LuaRef&& rhs);
    explicit operator bool() const;
    void reset(lua_State* aL, int index);
    void push() const;
    lua_State* state() const;
protected:
    void unref() const;
protected:
    lua_State* L;
    int ref_;
};



class LuaFunction : public LuaRef
{
public:
    LuaFunction();
    LuaFunction(lua_State* aL, int index, int);
    LuaFunction(const LuaFunction& other);
    LuaFunction& operator=(const LuaFunction& rhs);
    LuaFunction(LuaFunction&& other);
    LuaFunction& operator=(LuaFunction&& rhs);

    void operator()() const;
    void ppush() const;
    void pcall() const;
    template<typename...Args>
    void operator()(Args&...args) const
    {
        ppush();
        pusharg(args...);
        pcall();
    }
    void pusharg(bool v) const;
    void pusharg(float v) const;
    void pusharg(double v) const;
    void pusharg(int v) const;
	void pusharg(unsigned int v) const;
    void pusharg(const std::string& v) const;
    void pusharg(const char* v) const;
    template<typename T, typename... Args>
    inline void pusharg(T first, Args... args) const {
        pusharg(first);
        pusharg(args...);
    }
private:
    mutable int trackback_;
};
