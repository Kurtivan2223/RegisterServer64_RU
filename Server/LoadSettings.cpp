#include "LoadSettings.h"
#include "include/inipp.h"
#include "ServerDatabase.h"
#include <iostream>
#include <string>

BOOL LoadSettings::CheckIni = file.fail() ? false : true;

BOOL LoadSettings::CheckDirectory(const fs::path& p)
{
	return (fs::is_directory(p)) ? true : false;
}

void LoadSettings::Load()
{
	if (LoadSettings::CheckIni)
	{
		inipp::Ini<char> ini;
		ini.parse(file);
		ini.strip_trailing_comments();
		ini.default_section(ini.sections["Info"]);
		ini.interpolate();
		inipp::get_value(ini.sections["info"], "Version", SP.m_VERSION);
		inipp::get_value(ini.sections["info"], "IocpMax", SP.m_IOCPMAX);
		inipp::get_value(ini.sections["info"], "SQLMax", SP.m_SQLMAX);
		inipp::get_value(ini.sections["info"], "WorkerThreadMax", SP.m_WORKERTHREADMAX);
		inipp::get_value(ini.sections["info"], "ServerLogLevel", SP.m_LOGLEVEL);
		inipp::get_value(ini.sections["Connection"], "ServerPort", SP.m_SERVERPORT);
		inipp::get_value(ini.sections["Connection"], "ClientPort", SP.m_CLIENTPORT);
		inipp::get_value(ini.sections["DB_DNMembership"], "DBIP", DB.m_DBADDRESS);
		inipp::get_value(ini.sections["DB_DNMembership"], "DBPort", DB.m_DBPORT);
		inipp::get_value(ini.sections["DB_DNMembership"], "DBID", DB.m_DBID);
		inipp::get_value(ini.sections["DB_DNMembership"], "DBPassword", DB.m_DBPASSWORD);
		inipp::get_value(ini.sections["DB_DNMembership"], "DBName", DB.m_DBNAME);
		inipp::get_value(ini.sections["Resource"], "Path", SP.m_PATH);
	}
}