#include "gaussianblur.h"
#include "qcolor.h"
#include <math.h>

GaussianBlur::GaussianBlur()
{
}

QImage GaussianBlur::BlurImage(const QImage& in, float radius)
{

    if(in.isNull())
        return QImage();

    QImage image(in.size(), in.format());

    float **cMatrix = CreateConvolutionMatrix(radius, 0.84089642);
    int matrixSize = radius * 2 + 1;
    int halfMatrixSize = matrixSize / 2;

    float sumRed = 0;
    float sumBlue = 0;
    float sumGreen = 0;
    float x1, y1;
    for (int x = 0; x < in.width(); ++x)
    {
        for (int y = 0; y < in.height(); ++y)
        {

            for (int kx = -halfMatrixSize; kx <= halfMatrixSize; ++kx)
            {
                for (int ky = -halfMatrixSize; ky <= halfMatrixSize; ++ky)
                {
                    x1 = ReflectIndex(x - kx, in.width());
                    y1 = ReflectIndex(y - ky, in.height());

                    QColor color(in.pixel(x1, y1));

                    sumRed = sumRed + (float)color.red() * cMatrix[kx + halfMatrixSize][ky + halfMatrixSize];
                    sumBlue = sumBlue + (float)color.blue() * cMatrix[kx + halfMatrixSize][ky + halfMatrixSize];
                    sumGreen = sumGreen + (float)color.green() * cMatrix[kx + halfMatrixSize][ky + halfMatrixSize];
                }
            }
            QColor finalPixelColor(sumRed, sumGreen, sumBlue);

            image.setPixel(x, y, finalPixelColor.rgba());

            sumRed = 0;
            sumBlue = 0;
            sumGreen = 0;

        }
    }

    DestroyConvolutionMatrix(cMatrix, radius);
    return image;
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
    for (x = -halfMatrixSize; x <= halfMatrixSize; ++x)
    {
        for(y = -halfMatrixSize; y <= halfMatrixSize; ++y)
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

int GaussianBlur::ReflectIndex(int x, int length)
{
    if (x < 0)
        return -x - 1;
    else if(x >= length)
        return 2*length - x - 1;

    return x;
}

void GaussianBlur::DestroyConvolutionMatrix(float **cMatrix, int radius)
{
    for (int i = 0; i < radius * 2 + 1; ++i)
        free(cMatrix[i]);

    free(cMatrix);
}
