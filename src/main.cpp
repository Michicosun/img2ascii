#include <opencv2/core/hal/interface.h>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <memory>
#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

using namespace cv;

class Converter {
private:
    const static inline std::string density_arr = " .,:;i1tfLCG08@";
    const static inline uint64_t max_brightness = 255;
    const static inline size_t delta_bright = max_brightness / density_arr.size();
    
    bool colored;
    std::size_t sum_size;
    double scale_rows, scale_cols;
    std::vector<uint64_t> r_sum;
    std::vector<uint64_t> g_sum;
    std::vector<uint64_t> b_sum; 

    char grayscaleToChar(int grayscale) const {
        int ind = min(density_arr.size() - 1, grayscale / delta_bright);
        return density_arr.at(ind);   
    }

    void printSymbol(size_t i) const {
        uint64_t r = std::min(max_brightness, static_cast<uint64_t>(r_sum[i] * scale_cols * scale_rows));
        uint64_t g = std::min(max_brightness, static_cast<uint64_t>(g_sum[i] * scale_cols * scale_rows));
        uint64_t b = std::min(max_brightness, static_cast<uint64_t>(b_sum[i] * scale_cols * scale_rows));
        uint64_t all_sum = (r + g + b) / 3;

        if (colored) std::cout << 
                                "\e[38;2;" + 
                                std::to_string(r) + ";" + 
                                std::to_string(g) + ";" + 
                                std::to_string(b) + "m";
        
        std::cout << grayscaleToChar(all_sum);
        if (colored) std::cout << "\e[0m";
    }

public:

    Converter(std::size_t orig_len, double scale_rows, double scale_cols, bool colored = false) :
                            colored{colored}, 
                            sum_size{static_cast<size_t>(ceil(orig_len * scale_cols))},
                            scale_rows{scale_rows},
                            scale_cols{scale_cols},
                            r_sum(sum_size),
                            g_sum(sum_size), 
                            b_sum(sum_size) {}

    void addPixel(uint ind, uint r, uint g, uint b) {
        size_t sum_ind = round(ind * scale_cols);
        r_sum.at(min(r_sum.size() - 1, sum_ind)) += r;
        g_sum.at(min(g_sum.size() - 1, sum_ind)) += g;
        b_sum.at(min(b_sum.size() - 1, sum_ind)) += b;
    }

    void printRow() const {
        for (size_t i = 0; i < sum_size; ++i) {
            printSymbol(i);
        }
        std::cout << "\n";
    }

    void clearRow() {
        for (size_t i = 0; i < sum_size; ++i) {
            r_sum[i] = g_sum[i] = b_sum[i] = 0;
        }
    }

};

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "usage: ./img2ascii <Image_Path>\n";
        return -1;
    }

    bool colored = false;
    const static double diff_w_h = 0.4;
    std::string path = "";
    double scale_cols = 1;

    for (int i = 1; i < argc; ++i) {
        std::string param(argv[i]);
        if (param[0] == '-') {
            if (param[1] == 'r') {
                if (param.size() > 2) {
                    scale_cols = std::stod(param.substr(2, param.size()));
                } else if (i + 1 < argc) {    
                    scale_cols = std::stod(argv[i + 1]);
                    ++i;
                } else {
                    std::cout << "-r parameter should have one argument: scale\n";
                    return 1;
                }
            } 
            else if (param[1] == 'c' && param.size() == 2) colored = true;
            else {
                std::cout << "unknown parameter\n";
                return 1;
            }
        } else path = argv[i];
    }

    double scale_rows = scale_cols * diff_w_h;

    std::cout << "path: " << path << "\n";

    Mat image;
    image = imread(path, 1);
    if (!image.data) {
        printf("No image data \n");
        return -1;
    }

    std::cout << 
        "Image params: " 
        "{" << image.rows << " " << image.cols << "}, scale = {" << scale_rows << " " << scale_cols << "}\n";

    Converter conv(image.cols, scale_rows, scale_cols, colored);
    size_t cnt_rows_to_print = (image.rows + image.rows * scale_rows - 1) / (image.rows * scale_rows);    

    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            uint b = image.at<cv::Vec3b>(i, j)[0];
            uint g = image.at<cv::Vec3b>(i, j)[1];
            uint r = image.at<cv::Vec3b>(i, j)[2];
            conv.addPixel(j, r, g, b);
        }
        if (i % cnt_rows_to_print == 0 || i == image.rows) {
            conv.printRow();
            conv.clearRow();
        }
    }

    return 0;
}