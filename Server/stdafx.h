#pragma once
#undef UNICODE
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "ServerDatabase.h"
#include "LoadSettings.h"
#include "LogHandler.h"
#include "include/inipp.h"
#include <iostream>
#include <string>