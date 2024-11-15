/**
 * @file debugger.h
 * @brief 调试类
 * @details 输出调试信息，生成滚动条
 * @version 2023 Season
 * @date 2022-12-13
 * @license Copyright© 2023 RMSummit-RoboMaster Group
 */

#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

#include "CameraApi.h"
#include "aimbot.h"
#include "armor.h"
#include "base.h"
#include "camera.h"
#include "mvcamera.h"
#include "runedetector.h"
#include "types.h"

class Debugger {
   public:
    /**
     * @brief 在终端打印 WARNING 信息
     *
     * @param description WARNING 描述
     * @param file_name 文件名，可以通过 __FILE__ 宏定义获得
     * @param func_name 函数名，可以通过 __FUNCTION__ 宏定义获得
     * @param line 报错的行号，可以通过 __LINE__ 宏定义获得
     */
    static void warning(const std::string& description,
                        const std::string& file_name,
                        const std::string& func_name, int line);

    /**
     * @brief 在终端打印 ERROR 信息, 并以返回值 1 终止程序
     *
     * @param description ERROR 描述
     * @param file_name 文件名，可以通过 __FILE__ 宏定义获得
     * @param func_name 函数名，可以通过 __FUNCTION__ 宏定义获得
     * @param line 报错的行号，可以通过 __LINE__ 宏定义获得
     */
    static void error(const std::string& description,
                      const std::string& file_name,
                      const std::string& func_name, int line);

    /**
     * @brief 创建一个调试相机的trackbar
     */
    static void Cameratrackbar(MVCamera* camera, const std::string& window_name_target);

    /**
     * @brief 创建一个 AimBot 类需要的所有 trackbar
     *
     * @param detector AimBot 类型变量
     * @param window_name_target
     * 有目标的窗口名称，将在该窗口上创建灯条筛选的滚动条
     */
    static void Armortrackbar(AimBot& detector, MVCamera* camera,
                              const std::string& window_name_target,
                              const std::string& window_name_proc);

    /**
     * @brief 创建一个 Runesolver 类需要的所有 trackbar
     *
     * @param solver Runesolver 类型变量
     * @param window_name_target
     * 有目标的窗口名称，将在该窗口上创建灯条筛选的滚动条
     */
    static void Runetrackbar(RuneDetector& solver, MVCamera* camera,
                             const std::string& window_name_proc,
                             const std::string& window_name_target);

   /**
    * @brief 各种需要调试的参数
    */
    static void Utiltrackbar(int &value, std::string& window_name_target);


    /**
     * @brief 将 T 类型的变量值打印在指定图像上的函数模板
     *
     * @param value 需要打印的变量
     * @param name 变量的名字
     * @param image 需要打印图像的引用
     */
    template <class T>
    static void drawValue(cv::Mat& image, cv::Point point, std::string name,
                          const T& value);

   /**
     * @brief 将 Target 类型变量的成员打印在图像上
     * 
     * @param target 需要打印的 Target 类型变量
     * @param image 需要打印图像的引用
     * @overload
     */
   static void drawTypeValue(Target& target, cv::Mat& image);

    /**
     * @brief 在图像中框出装甲板，并画出灯条
     *
     * @param armor 装甲板类
     * @param image 需要画出图像的引用
     */
    static void drawArmor(const Armor& armor, cv::Mat& image);

    /**
     * @brief 在图像上绘画旋转矩形
     * @param image 源图像
     * @param rect 旋转矩形
     * @param scalar 颜色, 默认为红色
     * @param thickness 线条粗细, 默认为2
     */
    static void drawRotatedRect(cv::Mat& image, const cv::RotatedRect& rect,
                                const cv::Scalar& scalar = cv::Scalar(0, 0,
                                                                      255),
                                int thickness = 2);
};

#endif  // DEBUGGER_H