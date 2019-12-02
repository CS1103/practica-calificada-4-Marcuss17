#include "functions.h"

void red_filter(vector< unsigned char>& image, unsigned  int h, unsigned int w){
    unsigned int h1 = (h/4);
    unsigned int h2 = (h/2);
    unsigned int h3 = ((3*h)/4);
    thread t1(childRed,std::ref(image),0,h1,w);
    thread t2(childRed,std::ref(image),h1,h2,w);
    thread t3(childRed,std::ref(image),h2,h3,w);
    thread t4(childRed,std::ref(image),h3,h,w);
    t1.join(); t2.join(); t3.join(); t4.join();
}

void childRed(vector<unsigned char>& image, unsigned int h, unsigned int nh, unsigned int w){
    for (size_t i = h; i < nh; i++) {
        vector<int> aux;
        for (size_t j = 0; j < w * 4; j += 4) {
            image[i*w*4+j+1] = 0;
            image[i*w*4+j+2] = 0;
        }
    }
}

void blue_filter(vector< unsigned char>& image, unsigned  int h, unsigned int w){
    unsigned int h1 = (h/4);
    unsigned int h2 = (h/2);
    unsigned int h3 = ((3*h)/4);
    thread t1(childBlue,std::ref(image),0,h1,w);
    thread t2(childBlue,std::ref(image),h1,h2,w);
    thread t3(childBlue,std::ref(image),h2,h3,w);
    thread t4(childBlue,std::ref(image),h3,h,w);
    t1.join(); t2.join(); t3.join(); t4.join();
}

void childBlue(vector<unsigned char>& image, unsigned int h, unsigned int nh, unsigned int w){
    for (size_t i = h; i < nh; i++) {
        vector<int> aux;
        for (size_t j = 0; j < w * 4; j += 4) {
            image[i*w*4+j+0] = 0;
            image[i*w*4+j+1] = 0;
        }
    }
}

void green_filter(vector< unsigned char>& image, unsigned  int h, unsigned int w){
    unsigned int h1 = (h/4);
    unsigned int h2 = (h/2);
    unsigned int h3 = ((3*h)/4);
    thread t1(childGreen,std::ref(image),0,h1,w);
    thread t2(childGreen,std::ref(image),h1,h2,w);
    thread t3(childGreen,std::ref(image),h2,h3,w);
    thread t4(childGreen,std::ref(image),h3,h,w);
    t1.join(); t2.join(); t3.join(); t4.join();
}

void childGreen(vector<unsigned char>& image, unsigned int h, unsigned int nh, unsigned int w){
    for (size_t i = h; i < nh; i++) {
        vector<int> aux;
        for (size_t j = 0; j < w * 4; j += 4) {
            image[i*w*4+j+0] = 0;
            image[i*w*4+j+2] = 0;
        }
    }
}
