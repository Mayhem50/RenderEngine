#pragma once

#include "Singleton.h"
#include "LogFile.h"
#include "LogConsole.h"

namespace Good
{
	class LogManager : public Singleton<LogManager>
	{
	public:
		ILoggerPtr LoggerToFile(const char* fileName = "./log.txt")
		{
			return ILoggerPtr(new LogFile(fileName));
		}

		ILoggerPtr LoggerToConsole()
		{
			return ILoggerPtr(new LogConsole());
		}
	};
}

