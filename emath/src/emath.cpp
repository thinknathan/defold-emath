#include <dmsdk/sdk.h>
#include <cmath>

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

static int emath_sign(lua_State* L) {
    double number = luaL_checknumber(L, 1);
    
    double result = (number > 0) ? 1 : ((number < 0) ? -1 : 0);
    
    lua_pushnumber(L, result);
    return 1;
}

static int emath_deg_to_rad(lua_State* L) {
    double degrees = luaL_checknumber(L, 1);
    double radians = degrees * M_PI / 180.0;
    
    lua_pushnumber(L, radians);
    return 1;
}

static int emath_rad_to_deg(lua_State* L) {
    double radians = luaL_checknumber(L, 1);
    double degrees = radians * 180.0 / M_PI;
    
    lua_pushnumber(L, degrees);
    return 1;
}

static int emath_distance2d(lua_State* L) {
    double x1 = luaL_checknumber(L, 1);
    double y1 = luaL_checknumber(L, 2);
    double x2 = luaL_checknumber(L, 3);
    double y2 = luaL_checknumber(L, 4);
    
    double dx = x2 - x1;
    double dy = y2 - y1;
    
    double distance = sqrt(dx * dx + dy * dy);
    
    lua_pushnumber(L, distance);
    return 1;
}

static int emath_distance3d(lua_State* L) {
    double x1 = luaL_checknumber(L, 1);
    double y1 = luaL_checknumber(L, 2);
    double z1 = luaL_checknumber(L, 3);
    double x2 = luaL_checknumber(L, 4);
    double y2 = luaL_checknumber(L, 5);
    double z2 = luaL_checknumber(L, 6);
    
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    
    double distance = sqrt(dx * dx + dy * dy + dz * dz);
    
    lua_pushnumber(L, distance);
    return 1;
}

static const luaL_Reg emath_functions[] = {
    {"clamp", emath_clamp},
    {"round", emath_round},
    {"sign", emath_sign},
    {"deg_to_rad", emath_deg_to_rad},
    {"rad_to_deg", emath_rad_to_deg},
    {"distance2d", emath_distance2d},
    {"distance3d", emath_distance3d},
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
