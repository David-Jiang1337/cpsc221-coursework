#include "RGBAPixel.h"

namespace cs221util {
  
  RGBAPixel::RGBAPixel() {
    this->r = 255;
    this->g = 255;
    this->b = 255;
    this->a = 1;
  }

  RGBAPixel::RGBAPixel(const unsigned char r, const unsigned char g, const unsigned char b) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = 1;
  }

  RGBAPixel::RGBAPixel(const unsigned char r, const unsigned char g, const unsigned char b, const double a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
  }

}
