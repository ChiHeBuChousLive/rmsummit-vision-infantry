//
// Created by xinyang on 22-4-19.
//
// 为了一时方便，使用循环和Eigen自行编写的CNN前向传播类。
// 没有显著的性能损失。
// 但类定义了网络结构，同时实现的操作较少，可扩展性较差

#ifndef SJ_CLASSIFIER_HPP
#define SJ_CLASSIFIER_HPP

#include <Eigen/Dense>
#include <opencv2/core.hpp>
#include <opencv2/core/eigen.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace Eigen;

class Classifier_sj {
   private:
    bool state;  // 标志分类器是否正确初始化

    // 所有网络参数
    std::vector<std::vector<MatrixXd>> conv1_w, conv2_w, conv3_w;
    std::vector<double> conv1_b, conv2_b, conv3_b;
    MatrixXd fc1_w, fc2_w;
    VectorXd fc1_b, fc2_b;
    // 读取网络参数的函数
    std::vector<std::vector<Eigen::MatrixXd>> load_conv_w(
        const std::string &file);
    std::vector<double> load_conv_b(const std::string &file);
    MatrixXd load_fc_w(const string &file);
    VectorXd load_fc_b(const string &file);
    // 目前支持的所有操作
    MatrixXd softmax(const MatrixXd &input);
    MatrixXd relu(const MatrixXd &input);
    MatrixXd leaky_relu(const MatrixXd &input, float alpha);
    vector<vector<MatrixXd>> apply_bias(const vector<vector<MatrixXd>> &input,
                                        const vector<double> &bias);
    vector<vector<MatrixXd>> relu(const vector<vector<MatrixXd>> &input);
    vector<vector<MatrixXd>> leaky_relu(const vector<vector<MatrixXd>> &input,
                                        float alpha);
    vector<vector<MatrixXd>> max_pool(const vector<vector<MatrixXd>> &input,
                                      int size);
    vector<vector<MatrixXd>> mean_pool(const vector<vector<MatrixXd>> &input,
                                       int size);
    vector<vector<MatrixXd>> pand(const vector<vector<MatrixXd>> &input,
                                  int val);
    MatrixXd conv(const MatrixXd &filter, const MatrixXd &input);
    vector<vector<MatrixXd>> conv2(const vector<vector<MatrixXd>> &filter,
                                   const vector<vector<MatrixXd>> &input);
    MatrixXd flatten(const vector<vector<MatrixXd>> &input);

   public:
    explicit Classifier_sj(const string &folder);
    ~Classifier_sj() = default;

    MatrixXd calculate(const vector<vector<MatrixXd>> &input);
    explicit operator bool() const;
    int operator()(const cv::Mat &image);
};

#endif /* SJ_CLASSIFIER_HPP */
