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
#include <string>

#pragma comment(lib, "Ws2_32.lib")

int main()
{
	WSADATA m_Data;

	WSAStartup(MAKEWORD(2, 2), &m_Data);

	HOSTENT* Host;

	char hostname[128] = { 0 };
	//char* IPv4 = new char[128];
	std::string IPv4;

	gethostname(hostname, 128);
	Host = gethostbyname(hostname);
	IPv4 = inet_ntoa(*(in_addr*)Host->h_addr_list[0]);
	std::cout << "Private IP: " << IPv4 << std::endl;
	std::cin.get();
	WSACleanup();

	return 0;
}