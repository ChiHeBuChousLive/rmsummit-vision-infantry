/**
 * @file classifier.h
 * @brief 数字分类器
 * @details 以28*28的cv::Mat图像为输入, 进行分类返回装甲板数字
 * @version 2023 Season
 * @date 2022-10-03
 * @license Copyright© 2023 RMSummit-RoboMaster Group
 */
#ifndef DK_CLASSIFIER_HPP
#define DK_CLASSIFIER_HPP

#include <darknet.h>

#include <opencv2/opencv.hpp>

class Classifier_dk {
   public:
    std::vector<std::string> labels;

   private:
    network *net;
    constexpr static int TOP = 2;
    int first = 0;
    int whole = 0;
    float *input;

   public:
    Classifier_dk(char *cfg_file, char *weight_file, const char *name_list);

    int predict(const cv::Mat &src);

   private:
    void imgConvert(const cv::Mat &img, float *dst);
};

#endif  // DK_CLASSIFIER_HPP
