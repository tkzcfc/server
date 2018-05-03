

local function main()
	require("lua_code.functions")
    --require("lua_code.test")
    require("lua_code.fstest")
end




__G__TRACKBACK__ = function(msg)
    local msg = debug.traceback(msg, 3)
    local logmsg = os.date() .. ":"..msg
    print(msg)
    return msg
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
end