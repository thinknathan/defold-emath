#include <dmsdk/sdk.h>

static int emath_clamp(lua_State* L) {
    double number = luaL_checknumber(L, 1);
    double lower = luaL_checknumber(L, 2);
    double upper = luaL_checknumber(L, 3);
    
    double result = (number < lower) ? lower : ((number > upper) ? upper : number);
    
    lua_pushnumber(L, result);
    return 1;
}

static int emath_round(lua_State* L) {
    double number = luaL_checknumber(L, 1);
    
    double result = (number > 0.0) ? floor(number + 0.5) : ceil(number - 0.5);
    
    lua_pushnumber(L, result);
    return 1;
}

static const luaL_Reg emath_functions[] = {
    {"clamp", emath_clamp},
    {"round", emath_round},
    {0, 0}
};

static void LuaInit(lua_State* L) {
    int top = lua_gettop(L);
    luaL_register(L, "emath", emath_functions);
    lua_pop(L, 1);
}

static dmExtension::Result InitializeMyExtension(dmExtension::Params* params) {
    LuaInit(params->m_L);
    dmLogInfo("Registered %s Extension\n", "emath");
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(emath, "emath", 0, 0, InitializeMyExtension, 0, 0, 0)
