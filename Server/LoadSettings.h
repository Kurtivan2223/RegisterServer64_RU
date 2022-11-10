#pragma once
#undef UNICODE
#define _CRT_SECURE_NO_WARNINGS

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#ifdef _MSC_VER <= 1916
namespace fs = std::experimental::filesystem;
#else
namespace fs = std::filesystem;
#endif

struct ServerProtocol
{
	int m_VERSION;
	int m_IOCPMAX;
	int m_SQLMAX;
	int m_WORKERTHREADMAX;
	int m_LOGLEVEL;
	int m_SERVERPORT;
	int m_CLIENTPORT;
	std::string m_PATH;
};

class LoadSettings
{
public:
	void Load();
	static BOOL CheckIni;
	static BOOL CheckDirectory(const fs::path& p);
};

std::ifstream file("Config\\Register.ini");

ServerProtocol SP;
LoadSettings LS;