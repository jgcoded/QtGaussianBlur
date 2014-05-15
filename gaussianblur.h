#ifndef GAUSSIANBLUR_H
#define GAUSSIANBLUR_H

#include <math.h>
#include <cstdlib> // for realloc
#include "qcolor.h"
#include "qimage.h"

class GaussianBlur
{

public:
    GaussianBlur(int blurRadius, float sigma);

    QImage BlurImage(const QImage& in);

    static float GaussFunc(float x, float y, float sigma);

    static float** CreateConvolutionMatrix(float radius, float sigma);

    int getBlurRadius() const;
    void setBlurRadius(int value);

    float getSigma() const;
    void setSigma(float value);

    ~GaussianBlur();

private:

    float **cMatrix;
    int ReflectIndex(int x, int length);

    void DestroyConvolutionMatrix(float **cMatrix, int radius);

    int blurRadius;
    float sigma;
};

#endif // GAUSSIANBLUR_H
