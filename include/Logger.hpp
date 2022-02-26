#pragma once
#include <iostream>
#include <spdlog/spdlog.h>
#include <unistd.h>
#include "fmt/core.h"
#include <fstream>


// #include "spdlog/sinks/basic_file_sink.h"
using namespace fmt;
#define ROW_SHOW 1

class Logger
{
private:
    /* data */
public:
    Logger(std::string path_);
    ~Logger();
private:
    std::string save_path_;
    std::fstream _file;
};


/**
 * @brief 是否定位到
 */
#if ROW_SHOW == 0
#define LOG_TRACE(...)       Logger::instance().getLogger().get()->trace(__VA_ARGS__)
#define LOG_DEBUG(...)       Logger::instance().getLogger().get()->debug(__VA_ARGS__)
#define LOG_INFO(...)        Logger::instance().getLogger().get()->info(__VA_ARGS__)
#define LOG_WARN(...)        Logger::instance().getLogger().get()->warn(__VA_ARGS__)
#define LOG_ERROR(...)       Logger::instance().getLogger().get()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)    Logger::instance().getLogger().get()->critical(__VA_ARGS__)
#else
// 有代码行号
#define LOG_TRACE(...)      SPDLOG_LOGGER_CALL(Logger::instance().getLogger().get(), spdlog::level::trace, __VA_ARGS__)
#define LOG_DEBUG(...)      SPDLOG_LOGGER_CALL(Logger::instance().getLogger().get(), spdlog::level::debug, __VA_ARGS__)
#define LOG_INFO(...)       SPDLOG_LOGGER_CALL(Logger::instance().getLogger().get(), spdlog::level::info, __VA_ARGS__)
#define LOG_WARN(...)       SPDLOG_LOGGER_CALL(Logger::instance().getLogger().get(), spdlog::level::warn, __VA_ARGS__)
#define LOG_ERROR(...)      SPDLOG_LOGGER_CALL(Logger::instance().getLogger().get(), spdlog::level::err, __VA_ARGS__)
#define LOG_CRITICAL(...)   SPDLOG_LOGGER_CALL(Logger::instance().getLogger().get(), spdlog::level::critical, __VA_ARGS__)
#endif
