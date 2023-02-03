#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Koza_Core
{
	static class Log
	{

	private:
		Log() = default;

	public:
		static Log& Get()
		{
			static Log _logger;
			return _logger;
		}

		void Init();

		std::shared_ptr<spdlog::logger> _engineLogger;
		std::shared_ptr<spdlog::logger> _clientLogger;


		Log(const Log&) = delete;
	};
}

#define ENGINE_LOG_INFO(...) Koza_Core::Log::Get()._engineLogger->info(__VA_ARGS__)
#define ENGINE_LOG_WARN(...) Koza_Core::Log::Get()._engineLogger->warn(__VA_ARGS__)
#define ENGINE_LOG_ERROR(...) Koza_Core::Log::Get()._engineLogger->error(__VA_ARGS__)
#define ENGINE_LOG_CRITICAL(...) Koza_Core::Log::Get()._engineLogger->critical(__VA_ARGS__)

#define CLIENT_LOG_INFO(...) Koza_Core::Log::Get()._clientLogger->info(__VA_ARGS__)
#define CLIENT_LOG_WARN(...) Koza_Core::Log::Get()._clientLogger->warn(__VA_ARGS__)
#define CLIENT_LOG_ERROR(...) Koza_Core::Log::Get()._clientLogger->error(__VA_ARGS__)
#define CLIENT_LOG_CRITICAL(...) Koza_Core::Log::Get()._clientLogger->critical(__VA_ARGS__)