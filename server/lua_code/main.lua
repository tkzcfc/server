
function sendStrToClient(client, msgstr)
    local m = { content = msgstr}
    sendMsgToGame(client, "net.speak", m)
end

function sendMsgToGame(client, msgKey, msg)
	
	local baseMsg = { msgName = msgKey }
    baseMsg.msgData = protobuf.encode(msgKey, msg)
    local data = protobuf.encode("__msg_base_", baseMsg)
    client:send(data, string.len(data))
end

function recvMsg(msgdata)
    local baseMsg = protobuf.decode("__msg_base_" , msgdata)

    if type(baseMsg) ~= "table" 
    or baseMsg.msgName == nil 
    or baseMsg.msgData == nil
    or baseMsg.msgName == "" 
    or baseMsg.msgData == "" then
        print("net : data is wrongful!!!")
        return "data is wrongful!!!"
    end 

    local msg = protobuf.decode(baseMsg.msgName, baseMsg.msgData)
    return msg.content
end



local function main()
	require("lua_code.utils.functions")
	require("lua_code.net.registerMsg")

    local clients = {}
    local sendMsg = ""

    local server = DUServer:new()
    server:startServer("0.0.0.0", 1234)
    server:setCallFunc(function(msgtype, client, msgdata)
    	if msgtype == "recv" then
			local s = client:getIp()..": "..recvMsg(msgdata)
    		for k,v in pairs(clients) do
    			sendStrToClient(v, s)
    		end

    	elseif msgtype == "connect" then

    		local s = client:getIp().." connect"
            print(s)
            for k,v in pairs(clients) do
                sendStrToClient(v, s)
            end

    		table.insert(clients, client)

    	elseif msgtype == "disconnect" then

    		for k,v in pairs(clients) do
    			if v == client then
    				table.remove(clients, k)
    			end
    		end

			local s = client:getIp().." disconnect"
            print(s)
    		for k,v in pairs(clients) do
    			sendStrToClient(v, s)
    		end

    	elseif msgtype == "loopexit" then
    		print("loopexit")
    	end
    end)

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