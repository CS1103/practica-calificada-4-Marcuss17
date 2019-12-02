#include <iostream>
#include <vector>
#include <string_view>
#include "lodepng.h"
#include "functions.h"
using namespace std;

std::vector<unsigned char> decode(string_view filename,
    unsigned int& width, unsigned int& height) {

    std::vector<unsigned char> result;
    unsigned error = lodepng::decode(result, width, height, filename.data());
    if (error) {
        std::cerr << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
    return result;
}

void encode(string_view filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
    unsigned error = lodepng::encode(filename.data(), image, width, height);
    if (error) {
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}

int main()
{
    unsigned int w;
    unsigned int h;
    auto image = decode("../in.png", w, h);
    red_filter(image,h,w);
    encode("../red_filter.png", image, w, h);
    image = decode("../in.png", w, h);
    blue_filter(image,h,w);
    encode("../blue_filter.png", image, w, h);
    image = decode("../in.png", w, h);
    green_filter(image,h,w);
    encode("../green_filter.png", image, w, h);
    image = decode("../img.png",w,h);
    red_filter(image,h,w);
    encode("../red_filterImg.png",image,w,h);
    image = decode("../img.png",w,h);
    green_filter(image,h,w);
    encode("../green_filterImg.png",image,w,h);
    image = decode("../img.png",w,h);
    blue_filter(image,h,w);
    encode("../blue_filterImg.png",image,w,h);
    return 0;
}
