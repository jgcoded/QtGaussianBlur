#ifndef GAUSSIANBLUR_H
#define GAUSSIANBLUR_H

#include "qimage.h"

class GaussianBlur
{

public:
    GaussianBlur();

    QImage* BlurImage(QImage* in, float radius);

    static float GaussFunc(float x, float y, float sigma);

    float** CreateConvolutionMatrix(float radius, float sigma);
};

#endif // GAUSSIANBLUR_H
