#include <cmath>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace cv;

class Converter
{
private:
    const static inline std::string density_arr = " .,:;i1tfLCG08@";
    const static inline size_t max_brightness = 255;
    const static inline size_t delta_bright = max_brightness / density_arr.size();

    std::size_t sum_size;
    double scale_rows, scale_cols;
    std::vector<uint64_t> sum;

public:
    Converter(std::size_t orig_len, double scale_rows, double scale_cols) : sum_size{static_cast<size_t>(ceil(orig_len * scale_cols))},
                                                                            scale_rows{scale_rows},
                                                                            scale_cols{scale_cols},
                                                                            sum(sum_size) {}

    void addPixel(uint ind, uint gray)
    {
        size_t sum_ind = round(ind * scale_cols);
        sum.at(min(sum.size() - 1, sum_ind)) += gray;
    }

    char grayscaleToChar(int grayscale) const
    {
        int ind = min(density_arr.size() - 1, grayscale / delta_bright);
        return density_arr.at(ind);
    }

    void printRow() const
    {
        for (uint64_t x : sum)
            std::cout << grayscaleToChar(x * scale_cols * scale_rows);
        std::cout << "\n";
    }

    void clearRow()
    {
        sum.assign(sum_size, 0);
    }
};

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "usage: ./img2ascii <Image_Path>\n";
        return -1;
    }

    const static double diff_w_h = 0.4;
    std::string path = "";
    double scale_cols = 1;

    for (int i = 1; i < argc; ++i)
    {
        std::string param(argv[i]);
        if (param[0] == '-')
        {
            if (param[1] == 'r')
            {
                if (param.size() > 2)
                {
                    scale_cols = std::stod(param.substr(2, param.size()));
                }
                else if (i + 1 < argc)
                {
                    scale_cols = std::stod(argv[i + 1]);
                    ++i;
                }
                else
                {
                    std::cout << "-r parameter should have one argument: scale\n";
                    return 1;
                }
            }
            else
            {
                std::cout << "unknown parameter\n";
                return 1;
            }
        }
        else
            path = argv[i];
    }

    double scale_rows = scale_cols * diff_w_h;

    std::cout << "path: " << path << "\n";

    Mat image;
    image = imread(path, 1);
    if (!image.data)
    {
        printf("No image data \n");
        return -1;
    }

    std::cout << "Image params:"
                 "{"
              << image.rows << " " << image.cols << "}, scale = " << scale_rows << " " << scale_cols << "}\n";
    double scale = 1;
    bool increase_size = true;
    // Nice animation.
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (increase_size)
        {
            scale += 0.01;
        }
        else
        {
            scale -= 0.01;
        }
        if (scale > 1)
        {
            increase_size = false;
        }
        if (scale < 0.01)
        {
            increase_size = true;
        }
        Converter conv(image.cols, scale * 0.4, scale);
        size_t cnt_rows_to_print = (image.rows + image.rows * scale * 0.4) / (image.rows * scale * 0.4);

        for (int i = 0; i < image.rows; ++i)
        {
            for (int j = 0; j < image.cols; ++j)
            {
                uint b = image.at<cv::Vec3b>(i, j)[0];
                uint g = image.at<cv::Vec3b>(i, j)[1];
                uint r = image.at<cv::Vec3b>(i, j)[2];
                uint gray = (r + g + b) / 3;
                conv.addPixel(j, gray);
            }
            if (i % cnt_rows_to_print == 0 || i == image.rows)
            {
                conv.printRow();
                conv.clearRow();
            }
        }
    }

    return 0;
}