#include "spdlog/spdlog.h"
#include <iostream>
#include "spdlog/sinks/rotating_file_sink.h"
#include <chrono>
#include <memory>


namespace spdlog_sub{

    // 5 MB
    auto max_size = 1048576 * 5;
    auto max_files = 3;
    auto logger = spdlog::rotating_logger_mt("WOLF_LOG", "../logs/WOLF.txt", max_size, max_files);
    void infoAutonomyStr(const std::string& mes){
        try
        {   
            logger->info(mes);
        }
        catch(const std::exception& e)
        {
            logger->~logger();
            std::cerr << e.what() << '\n';
        } 
    }
    template<typename T>
    void infoAutonomyElse(T &mes){
        try
        {   
            std::string mes_change = std::to_string(mes);
            logger->info(mes_change);
        }
        catch(const std::exception& e)
        {
            logger->~logger();
            std::cerr << e.what() << '\n';
        } 
    }

    void rotating_example() {
        double k  = 123.444;
        std::string ka = "WOLF";
        spdlog_sub::infoAutonomyStr(ka);
        spdlog_sub::infoAutonomyElse(k);
    }
}
