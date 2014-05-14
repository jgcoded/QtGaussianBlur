#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpalette.h>
#include <qfiledialog.h>
#include <qlogging.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->imageLabel->setBackgroundRole(QPalette::Base);

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
