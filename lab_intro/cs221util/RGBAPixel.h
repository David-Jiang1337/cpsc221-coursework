#ifndef RGBAPIXEL_H
#define RGBAPIXEL_H

namespace cs221util {
  class RGBAPixel {
    public:
      unsigned char r;  // red value of pixel in [0, 255]
      unsigned char g;  // green value of pixel in [0, 255]
      unsigned char b;  // blue value of pixel in [0, 255]
      double a;         // opacity of pixel in [0, 1]. higher is more opaque.
      
      /*
       * Creates an opaque white pixel
       */
      RGBAPixel();

      /* 
       * Creates a pixel with the colors specified and full opacity
       * @param r Red value of pixel.
       * @param g Green value of pixel.
       * @param b Blue value of pixel.
       */
      RGBAPixel(const unsigned char r, const unsigned char g, const unsigned char b);
      
      /* 
       * Creates a pixel with the colors specified and full opacity
       * @param r Red value of pixel.
       * @param g Green value of pixel.
       * @param b Blue value of pixel.
       */
      RGBAPixel(const unsigned char r, const unsigned char g, 
          const unsigned char b, const double a);
  }
}

#endif
