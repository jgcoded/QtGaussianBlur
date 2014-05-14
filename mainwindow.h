#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imageloader.h"
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

private:
    Ui::MainWindow *ui;
    ImageLoader *imageLoader;

};

#endif // MAINWINDOW_H
