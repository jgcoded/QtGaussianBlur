#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
#include "imageloader.h"
#include "gaussianblur.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionLoad_Image_triggered();

    void on_actionProcess_Image_triggered();

    void on_actionSet_Blur_Radius_triggered();

    void on_actionSet_Sigma_triggered();

private:
    Ui::MainWindow *ui;
    ImageLoader *imageLoader;
    GaussianBlur *blur;
    QLabel *imageLabel;
    QLabel *blurLabel;

};

#endif // MAINWINDOW_H
