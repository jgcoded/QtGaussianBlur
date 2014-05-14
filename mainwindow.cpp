#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpalette.h>
#include <qfiledialog.h>
#include <qlogging.h>
#include "gaussianblur.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    imageLoader = new ImageLoader;
}

void MainWindow::on_actionLoad_Image_triggered()
{
    QString fileName =
           QFileDialog::getOpenFileName(this, tr("Select Image"), "",
                                        tr("Image Files (*.png *.jpg *.bmp"));

    imageLoader->Load(fileName);
    if(imageLoader->isLoaded())
    {
        ui->imageLabel->setPixmap(*imageLoader->GetPixelMap());
        ui->actionProcess_Image->setEnabled(true);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    delete imageLoader;
}

void MainWindow::on_actionProcess_Image_triggered()
{
    GaussianBlur blur;

    QImage img = blur.BlurImage(imageLoader->GetImage(), 3);

    ui->blurLabel->setPixmap(QPixmap::fromImage(img));
}
