#ifndef GAUSSIANBLUR_H
#define GAUSSIANBLUR_H

#include "qimage.h"

class GaussianBlur
{

public:
    GaussianBlur();

    QImage BlurImage(const QImage& in, float radius);

    static float GaussFunc(float x, float y, float sigma);

    float** CreateConvolutionMatrix(float radius, float sigma);

private:

    int ReflectIndex(int x, int length);

    void DestroyConvolutionMatrix(float **cMatrix, int radius);
};

#endif // GAUSSIANBLUR_H
