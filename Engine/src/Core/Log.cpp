#include "Log.h"

using namespace Koza_Core;

void Log::Init()
{
	_engineLogger = spdlog::stdout_color_mt("ENGINE");
	_clientLogger = spdlog::stdout_color_mt("CLIENT");

	_engineLogger->set_pattern("|%H:%M:%S| [%n] [%^%l%$]: %v");
	_clientLogger->set_pattern("|%H:%M:%S| [%n] [%^%l%$]: %v");

	_engineLogger->info("Initiated\n");
	_clientLogger->info("Initiated\n");
}