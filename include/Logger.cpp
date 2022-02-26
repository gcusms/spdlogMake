#include "Logger.hpp"

  
Logger::Logger(std::string path_):save_path_(path_)
{
    
    _file.open(save_path_,std::ios::in);
    if (!_file){
        std::string pa = "mkdir ";
        pa.append(save_path_);
        std::cout << pa << std::endl;

        std::system(pa.c_str());
        
    }
    auto sharedFileSink = std::make_shared<spdlog::sinks::simple_file_sink_mt>(save_path_ + "/log.txt");
    auto firstLogger = std::make_shared<spdlog::logger>("log1", sharedFileSink);
    spdlog::set_async_mode(1);
    for(int i = 0; i < 10; i ++)
    {
        firstLogger->info("[loggerOne]: 线程函数运行 {}.", i);  // 记录日志
        firstLogger->warn("[loggerOne]: 线程函数运行 {}.", i);  
    }
    
    // error mes
    firstLogger->set_error_handler([](const std::string& msg)
    {
        std::cerr << "my err handler: " << msg << std::endl;
    });


    // spdlog::drop_all();  // 程序结束释放所有建立好的 logger
}

Logger::~Logger()
{
    
}

