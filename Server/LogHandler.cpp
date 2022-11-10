#include "LogHandler.h"
#include <iostream>

void LogHandler::init_logging()
{
	logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");

	logging::add_file_log
	(
		keywords::file_name = "RegisterServer.log",
		keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%] - %Message%"
	);

	logging::core::get()->set_filter
	(
		logging::trivial::severity >= logging::trivial::info
	);

	logging::add_common_attributes();
}