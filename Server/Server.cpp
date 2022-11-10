#include "stdafx.h"
#include <iostream>

int main(int argc, char** argv[])
{
	LG.init_logging();

	if (SD.getPublicIP() == 0)
	{
		BOOST_LOG_TRIVIAL(fatal) << "Unable to Get IP";
		exit(-1);
	}

	if (LoadSettings::CheckIni)
	{
		LS.Load();
#if (_DEBUG)
		BOOST_LOG_TRIVIAL(debug) << "Bool Check Return for Ini Check: " << LoadSettings::CheckIni;
		BOOST_LOG_TRIVIAL(debug) << "Bool Check Return for Directory Check: " << LoadSettings::CheckDirectory(SP.m_PATH);

		BOOST_LOG_TRIVIAL(debug) << "ResourcePath [" << SP.m_PATH << "]";
		BOOST_LOG_TRIVIAL(debug) << "RegisterServe [IP:" << DB.m_PUBLICIP << "][Port:" << SP.m_SERVERPORT;
		BOOST_LOG_TRIVIAL(debug) << "ClientConnection [Port:" << SP.m_CLIENTPORT << "]";
		BOOST_LOG_TRIVIAL(debug) << "DBCON IP:" << DB.m_PUBLICIP << ", Port:" << SP.m_CLIENTPORT;

		if (!LoadSettings::CheckDirectory(SP.m_PATH))
			BOOST_LOG_TRIVIAL(fatal) << "Game Resources Can't be found!";

#else //for release version
		BOOST_LOG_TRIVIAL(info) << "ResourcePath [" << SP.m_PATH << "]";
		BOOST_LOG_TRIVIAL(info) << "RegisterServe [IP:" << DB.m_PUBLICIP << "][Port:" << SP.m_SERVERPORT;
		BOOST_LOG_TRIVIAL(info) << "ClientConnection [Port:" << SP.m_CLIENTPORT << "]";
		BOOST_LOG_TRIVIAL(info) << "DBCON IP:" << DB.m_PUBLICIP << ", Port:" << SP.m_CLIENTPORT;
		
		if (!LoadSettings::CheckDirectory(SP.m_PATH))
			BOOST_LOG_TRIVIAL(fatal) << "Game Resources Can't be found!";

#endif
	}
	else
	{
#if (_DEBUG)
		BOOST_LOG_TRIVIAL(debug) << "Bool Check Return for Ini Check: " << LoadSettings::CheckIni;
		BOOST_LOG_TRIVIAL(debug) << "Bool Check Return for Directory Check: " << LoadSettings::CheckDirectory(SP.m_PATH);
		BOOST_LOG_TRIVIAL(fatal) << "Configuration File can't be found!";
#else
		BOOST_LOG_TRIVIAL(fatal) << "Configuration File can't be found!";
#endif
	}

	system("pause");
}