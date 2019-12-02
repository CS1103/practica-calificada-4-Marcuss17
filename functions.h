#ifndef PC4_FUNCTIONS_H
#define PC4_FUNCTIONS_H
#include "lodepng.h"
#include <vector>
#include <thread>

using std::vector; using std::thread;

void red_filter(vector< unsigned char>&, unsigned  int , unsigned int );
void blue_filter(vector< unsigned char>&, unsigned  int, unsigned int);
void green_filter(vector< unsigned char>&, unsigned  int , unsigned int);
void childRed(vector<unsigned char>&, unsigned int, unsigned int, unsigned int);
void childBlue(vector<unsigned char>&, unsigned int, unsigned int, unsigned int);
void childGreen(vector<unsigned char>&, unsigned int, unsigned int, unsigned int);

#endif //PC4_FUNCTIONS_H
