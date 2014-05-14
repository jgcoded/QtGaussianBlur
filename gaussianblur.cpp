#include "gaussianblur.h"
#include <math.h>

GaussianBlur::GaussianBlur()
{
}

QImage *GaussianBlur::BlurImage(QImage *in, float radius)
{
    return NULL;
}

float GaussianBlur::GaussFunc(float x, float y, float sigma)
{
    return (1/(sigma * sqrtf(2*M_PI))) *
            exp(-(x * x + y * y)/(2*sigma*sigma));
}

float **GaussianBlur::CreateConvolutionMatrix(float radius, float sigma)
{
    int i, j, x, y;
    float sum;
    int matrixSize;
    int halfMatrixSize;
    float **cMatrix;

    matrixSize = radius * 2 + 1; // need an odd value in order to have a center
    halfMatrixSize = matrixSize / 2;
    // allocate memory
    cMatrix = (float**)malloc(sizeof(float*) * matrixSize);

    for (i = 0; i < matrixSize; ++i)
        cMatrix[i] = (float*)malloc(sizeof(float) * matrixSize);

    sum = 0.0f;
    i = j = 0;
    // fill in the matrix
    for (x = -halfMatrixSize; x < halfMatrixSize + 1; ++x)
    {
        for(y = -halfMatrixSize; y < halfMatrixSize + 1; ++y)
        {
            cMatrix[i][j] = GaussFunc(x, y, sigma);
            sum += cMatrix[i][j];
            ++j;
        }
        ++i;
        j = 0;
    }

    // normalize kernel values

    for(i = 0; i < matrixSize; ++i)
        for(j = 0; j < matrixSize; ++j)
            cMatrix[i][j] /= sum;

    return cMatrix;
}
