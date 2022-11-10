#include "ServerDatabase.h"
#include <iostream>
#include <string>

int ServerDatabase::getPublicIP()
{
	WSADATA m_Data;
	WSAStartup(MAKEWORD(2, 2), &m_Data);
	HOSTENT* Host;
	char hostname[128] = { 0 };
	gethostname(hostname, 128);
	Host = gethostbyname(hostname);
	DB.m_PRIVATEIP = inet_ntoa(*(in_addr*)Host->h_addr_list[0]);
	DB.m_PUBLICIP = inet_ntoa(*(in_addr*)Host->h_addr_list[1]);
	WSACleanup();

	return (DB.m_PRIVATEIP.empty() && DB.m_PUBLICIP.empty()) ? 0 : 1;
}