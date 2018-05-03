
#include "lua_modules.h"



#if __cplusplus
extern "C" {
#endif

#include "lfs.h"

#if __cplusplus
}
#endif



#ifdef __cplusplus
extern "C" {
#endif
	extern int luaopen_protobuf_c(lua_State *L);
#ifdef __cplusplus
}
#endif





void preload_lua_modules(lua_State *L)
{
	// load pbc
	luaopen_protobuf_c(L);
	// lfs
	luaopen_lfs(L);
}
