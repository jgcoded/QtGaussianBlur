#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpalette.h>
#include <qfiledialog.h>
#include <qlogging.h>
#include "gaussianblur.h"
#include <qmessagebox.h>
#include "qinputdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    imageLoader = new ImageLoader;

    imageLabel = new QLabel;
    blurLabel = new QLabel;

    blur = new GaussianBlur(3, 0.84089642f);

    imageLabel->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    blurLabel->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    ui->scrollAreaImage->setBackgroundRole(QPalette::Dark);
    ui->scrollAreaBlur->setBackgroundRole(QPalette::Dark);

}

void MainWindow::on_actionLoad_Image_triggered()
{
    QString fileName =
           QFileDialog::getOpenFileName(this, tr("Select Image"), "",
                                        tr("Image Files (*.png *.jpg *.bmp"));

    imageLoader->Load(fileName);
    if(imageLoader->isLoaded())
    {
        imageLabel->setPixmap(*imageLoader->GetPixelMap());
        blurLabel->clear();
        ui->scrollAreaImage->setWidget(imageLabel);
        ui->actionProcess_Image->setEnabled(true);
    } else {
        ui->actionProcess_Image->setEnabled(false);
    }

}

MainWindow::~MainWindow()
{
    delete blurLabel;
    delete imageLabel;
    delete imageLoader;
    delete ui;
}

void MainWindow::on_actionProcess_Image_triggered()
{
    QImage img = blur->BlurImage(imageLoader->GetImage());

    blurLabel->setPixmap(QPixmap::fromImage(img));

    ui->scrollAreaBlur->setWidget(blurLabel);
}

void MainWindow::on_actionSet_Blur_Radius_triggered()
{
    bool ok;
    int value;
    value = QInputDialog::getInt(this, tr("Blur Radius"),
                                 tr("Set the blur radius. Current value: %1")
                                 .arg(blur->getBlurRadius()),
                                 blur->getBlurRadius(), 1, 100, 1, &ok);
    if (ok)
        blur->setBlurRadius(value);
}

void MainWindow::on_actionSet_Sigma_triggered()
{
    bool ok;
    float value;
    value = QInputDialog::getDouble(this, tr("Sigma value"),
                                    tr("Set the value of sigma. Current value: %1")
                                    .arg(blur->getSigma()),
                                    blur->getSigma(), 1, 100, 5, &ok);
    if(ok)
        blur->setSigma(value);
}
