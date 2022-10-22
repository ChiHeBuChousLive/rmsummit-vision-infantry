RMSummit2023

RMSummit-RoboMaster 团队 2023 赛季省赛步兵代码

<span style="color:red">所有更改都要在下方`更新说明`中记录</span>

## 环境依赖

- Ubuntu 16.04 及以上 
- OpenCV 3.4 & OpenCV Contrib 3.4
- CMake 3.5.1 及以上

数字识别相关说明详见：https://www.yuque.com/herormluzhan/rghypl/ep6if4#3kmhz

## 编译运行

```sh
git clone ${this project}
mv p_5c39354b HERORM2020
cd HERORM2020
mkdir build
cd build
cmake ..
make
./hero
```

## 项目结构说明

```
.
├── CMakeLists.txt
├── monitor.sh                         
├── param
│   └── param.xml
├── README.md
├── save 
│   
└── src
    ├── armor_detect
    │   ├── armor
    │   │   ├── armor.cpp
    │   │   └── armor.hpp
    │   ├── armordetector.cpp
    │   ├── aimbot.hpp
    │   └── classifier
    │       ├── classifier.cpp
    │       ├── classifier.hpp
    │       └── darknet
    ├── camera
    │   ├── camera.hpp
    │   ├── dhcamera
    │   │   ├── dhcamera.cpp
    │   │   ├── dhcamera.hpp
    │   │   ├── DxImageProc.hpp
    │   │   └── GxIAPI.hpp
    │   └── mvcamera
    │       ├── mvcamera.cpp
    │       └── mvcamera.hpp
    ├── communication           
    │   ├── cannode.cpp
    │   ├── cannode.hpp
    │   ├── serialport.cpp
    │   └── serialport.hpp
    ├── rune                                                能量机关
    │   ├── runesolver.cpp
    │   └── runesolver.hpp
    ├── target_solve
    │   ├── anglesolver.cpp
    │   ├── anglesolver.hpp
    │   ├── targetsolver.cpp
    │   └── targetsolver.hpp
    ├── utils
    │   ├── base.hpp
    │   ├── debugger
    │   │   ├── debugger.cpp
    │   │   └── debugger.hpp
    │   ├── queue							 
    │   │   └── queue.hpp         
    │   ├── timer                       		
    │   │   ├── timer.cpp 
    │   │   └── timer.hpp
    │   ├── types.hpp       
    │   └── util
    │       ├── util.cpp
    │       └── util_func.hpp
    ├── workspace.cpp
    └── workspace.hpp

```



## TODO

1. 步兵 RUNE 的 MODE 以及通信协议
2. 串口固定化
3. TODO:相机图像截取，libdarknet.so
4. 坐标系规范文档
5. OpenMP 优化 for 循环
6. 最后要做的事
    - 修改所有文件的规范
    - 命名规范 --- 类型放在前面
    - xml 名字除了宏定义，都改成小写；类里面的不用改
7. 加入输出到日志的功能


## 更新说明

<span style="color:red">只保留最近一个月的更新记录</span>

