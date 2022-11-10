#pragma once
#undef UNICODE
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <Winsock2.h>
#include <WS2tcpip.h>

#include <iostream>

// link to Ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

struct DBConnection
{
	std::string m_DBADDRESS;
	int m_DBPORT;
	std::string m_DBID;
	std::string m_DBPASSWORD;
	std::string m_DBNAME;
	std::string m_PUBLICIP;
	std::string m_PRIVATEIP;
};

class ServerDatabase
{
public:
	int getPublicIP();
};

DBConnection DB;
ServerDatabase SD;