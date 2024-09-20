#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "areacalculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSquareSelected();
    void onRectangleSelected();
    void onParallelogramSelected();
    void onRhombusSelected();
    void onTriangleSelected();
    void onTrapezoidSelected();
    void onCircleSelected();
    void onSectorSelected();
    void calculateArea();
    void clearFields();
    void showAuthors();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
