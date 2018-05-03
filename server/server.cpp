
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#ifdef __cplusplus
}
#endif

#include "windows.h"


#include "lua-modules/lua_modules.h"
#include "DUScheduler.h"


void main()
{
	lua_State* L = luaL_newstate();

	luaL_openlibs(L);
	preload_lua_modules(L);

	luaL_dofile(L, "lua_code/main.lua");

	auto scheduler = DUScheduler::GetInstance();
	while (true)
	{
		scheduler->Update(0.05);
		Sleep(10);
	}

	lua_close(L);
	system("pause");
}

































//
//
//#include "uvtcp/TCPClient.h"
//#include "uvtcp/TCPServer.h"
//
//#include <iostream>
//
//
//void sendString(TCPSocket* s, char* szMsg)
//{
//	s->send(szMsg, strlen(szMsg));
//}
//
//void main()
//{
//	printf("ÇëÊäÈë¶Ë¿ÚºÅ:");
//	int port;
//	std::cin >> port;
//
//	auto instance = new TCPServer();
//	instance->startServer("0.0.0.0", port);
//
//	std::vector<ThreadMsg_S> msgs;
//	ThreadMsg_S msg;
//
//	TCPSocket* controlClient = NULL;
//
//	std::map<TCPSocket*, std::string> allsocket;
//	while (true)
//	{
//		if (instance->isCloseFinish())
//			break;
//
//		msgs.clear();
//		if (instance->getAllThreadMsg(&msgs))
//		{
//			for (int i = 0; i < msgs.size(); ++i)
//			{
//				msg = msgs[i];
//				switch (msg.msgType)
//				{
//				case CONNECT:
//				{
//					auto s = (TCPSocket*)msg.pSocket;
//
//					const char* szMsg = "you connect !!!!";
//					s->send((char*)szMsg, strlen(szMsg));
//
//					UV_LOG("[%s] connect\n", s->getIp().c_str());
//					allsocket[s] = s->getIp();
//
//					std::string str = s->getIp();
//					str.append(" join!!!");
//					for (auto &it : allsocket)
//					{
//						if(it.first != s)
//							it.first->send((char*)str.c_str(), str.size());
//					}
//				}break;
//				case DIS_CONNECT:
//				{
//					auto s = (TCPSocket*)msg.pSocket;
//					UV_LOG("[%s] disconnect\n", s->getIp().c_str());
//					auto it = allsocket.find(s);
//					if (it != allsocket.end())
//						allsocket.erase(it);
//
//					std::string str = s->getIp();
//					str.append(" exit!!!");
//					for (auto &it : allsocket)
//					{
//						it.first->send((char*)str.c_str(), str.size());
//					}
//				}break;
//				case EXIT_LOOP:
//				{
//					UV_LOG("loop exit\n");
//				}break;
//				case RECV_DATA:
//				{
//					auto s = (TCPSocket*)msg.pSocket;
//					std::string str = s->getIp();
//					str.append(" : ");
//					str.append((char*)msg.data);
//
//					for (auto &it : allsocket)
//					{
//						it.first->send((char*)str.c_str(), str.size());
//					}
//				}break;
//				default:
//					break;
//				}
//
//				if (msg.data)
//				{
//					fc_free(msg.data);
//				}
//			}
//		}
//		Sleep(2);
//	}
//
//	delete instance;
//
//	printMemInfo();
//
//	system("pause");
//}
