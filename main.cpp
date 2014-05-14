#include "mainwindow.h"
#include <QApplication>
#include "gaussianblur.h"

void test()
{
    GaussianBlur blur;

    float **kernel = blur.CreateConvolutionMatrix(3, 0.84089642);

    for(int i = 0; i < 7; ++i)
    {
        for(int j = 0; j < 7; ++j)
        {
            printf("%f\t", kernel[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 7; ++i)
        free(kernel[i]);

    free(kernel);
}

int main(int argc, char *argv[])
{
    test();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
