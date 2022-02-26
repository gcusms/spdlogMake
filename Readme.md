## spdlog Using


> 安装 spdlog 具体的参考官网github
> sudo apt-get install 
[github](https://github.com/gabime/spdlog) 

* <b>CMake 线程加载</b>
~~~ c++
find_package(Threads)
~~~

* <b>pdlog include 文件加载</b>
~~~ c++
if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()
~~~

* <b>链接起来即可，不要少了 CMAKE_THREAD_LIBS_INIT</b>
~~~ c++
target_link_libraries(${target name} PRIVATE spdlog::spdlog ${CMAKE_THREAD_LIBS_INIT})
~~~