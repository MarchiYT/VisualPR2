#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->squareButton, &QPushButton::clicked, this, &MainWindow::onSquareSelected);
    connect(ui->rectangleButton, &QPushButton::clicked, this, &MainWindow::onRectangleSelected);
    connect(ui->parallelogramButton, &QPushButton::clicked, this, &MainWindow::onParallelogramSelected);
    connect(ui->rhombusButton, &QPushButton::clicked, this, &MainWindow::onRhombusSelected);
    connect(ui->triangleButton, &QPushButton::clicked, this, &MainWindow::onTriangleSelected);
    connect(ui->trapezoidButton, &QPushButton::clicked, this, &MainWindow::onTrapezoidSelected);
    connect(ui->circleButton, &QPushButton::clicked, this, &MainWindow::onCircleSelected);
    connect(ui->sectorButton, &QPushButton::clicked, this, &MainWindow::onSectorSelected);

    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::calculateArea);

    connect(ui->actionClear, &QAction::triggered, this, &MainWindow::clearFields);

    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);

    connect(ui->actionAuthors, &QAction::triggered, this, &MainWindow::showAuthors);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSquareSelected() {
    ui->figureImageLabel->setPixmap(QPixmap(":/images/square.png"));
    ui->formulaLabel->setText("S = a²");
    ui->inputLineEdit1->setVisible(true);
    ui->inputLineEdit1->setPlaceholderText("Сторона a");
    ui->inputLineEdit2->setVisible(false);
    ui->inputLineEdit3->setVisible(false);
}

void MainWindow::onRectangleSelected() {
    ui->figureImageLabel->setPixmap(QPixmap(":/images/rectangle.png"));
    ui->formulaLabel->setText("S = a × b");
    ui->inputLineEdit1->setVisible(true);
    ui->inputLineEdit1->setPlaceholderText("Сторона a");
    ui->inputLineEdit2->setVisible(true);
    ui->inputLineEdit2->setPlaceholderText("Сторона b");
    ui->inputLineEdit3->setVisible(false);
}

void MainWindow::onParallelogramSelected() {
    ui->figureImageLabel->setPixmap(QPixmap(":/images/parallelogram.png"));
    ui->formulaLabel->setText("S = a × h");
    ui->inputLineEdit1->setVisible(true);
    ui->inputLineEdit1->setPlaceholderText("Сторона a");
    ui->inputLineEdit2->setVisible(true);
    ui->inputLineEdit2->setPlaceholderText("Высота h");
    ui->inputLineEdit3->setVisible(false);
}

void MainWindow::onRhombusSelected() {
    ui->figureImageLabel->setPixmap(QPixmap(":/images/rhombus.png"));
    ui->formulaLabel->setText("S = ½ × d1 × d2");
    ui->inputLineEdit1->setVisible(true);
    ui->inputLineEdit1->setPlaceholderText("Диагональ d1");
    ui->inputLineEdit2->setVisible(true);
    ui->inputLineEdit2->setPlaceholderText("Диагональ d2");
    ui->inputLineEdit3->setVisible(false);
}

void MainWindow::onTriangleSelected() {
    ui->figureImageLabel->setPixmap(QPixmap(":/images/triangle.png"));
    ui->formulaLabel->setText("S = ½ × a × h");
    ui->inputLineEdit1->setVisible(true);
    ui->inputLineEdit1->setPlaceholderText("Сторона a");
    ui->inputLineEdit2->setVisible(true);
    ui->inputLineEdit2->setPlaceholderText("Высота h");
    ui->inputLineEdit3->setVisible(false);
}

void MainWindow::onTrapezoidSelected() {
    ui->figureImageLabel->setPixmap(QPixmap(":/images/trapezoid.png"));
    ui->formulaLabel->setText("S = ½ × (a + b) × h");
    ui->inputLineEdit1->setVisible(true);
    ui->inputLineEdit1->setPlaceholderText("Основание a");
    ui->inputLineEdit2->setVisible(true);
    ui->inputLineEdit2->setPlaceholderText("Основание b");
    ui->inputLineEdit3->setVisible(true);
    ui->inputLineEdit3->setPlaceholderText("Высота h");
}

void MainWindow::onCircleSelected() {
    ui->figureImageLabel->setPixmap(QPixmap(":/images/circle.png"));
    ui->formulaLabel->setText("S = π × r²");
    ui->inputLineEdit1->setVisible(true);
    ui->inputLineEdit1->setPlaceholderText("Радиус r");
    ui->inputLineEdit2->setVisible(false);
    ui->inputLineEdit3->setVisible(false);
}

void MainWindow::onSectorSelected() {
    ui->figureImageLabel->setPixmap(QPixmap(":/images/sector.png"));
    ui->formulaLabel->setText("S = ½ × r² × θ");
    ui->inputLineEdit1->setVisible(true);
    ui->inputLineEdit1->setPlaceholderText("Радиус r");
    ui->inputLineEdit2->setVisible(true);
    ui->inputLineEdit2->setPlaceholderText("Угол θ (в радианах)");
    ui->inputLineEdit3->setVisible(false);
}

void MainWindow::calculateArea() {
    double result = 0;

    if (ui->formulaLabel->text() == "S = a²") {
        double side = ui->inputLineEdit1->text().toDouble();
        result = AreaCalculator::square(side);
    } else if (ui->formulaLabel->text() == "S = a × b") {
        double a = ui->inputLineEdit1->text().toDouble();
        double b = ui->inputLineEdit2->text().toDouble();
        result = AreaCalculator::rectangle(a, b);
    } else if (ui->formulaLabel->text() == "S = a × h") {
        double a = ui->inputLineEdit1->text().toDouble();
        double h = ui->inputLineEdit2->text().toDouble();
        result = AreaCalculator::parallelogram(a, h);
    } else if (ui->formulaLabel->text() == "S = ½ × d1 × d2") {
        double d1 = ui->inputLineEdit1->text().toDouble();
        double d2 = ui->inputLineEdit2->text().toDouble();
        result = AreaCalculator::rhombus(d1, d2);
    } else if (ui->formulaLabel->text() == "S = ½ × a × h") {
        double a = ui->inputLineEdit1->text().toDouble();
        double h = ui->inputLineEdit2->text().toDouble();
        result = AreaCalculator::triangle(a, h);
    } else if (ui->formulaLabel->text() == "S = ½ × (a + b) × h") {
        double a = ui->inputLineEdit1->text().toDouble();
        double b = ui->inputLineEdit2->text().toDouble();
        double h = ui->inputLineEdit3->text().toDouble();
        result = AreaCalculator::trapezoid(a, b, h);
    } else if (ui->formulaLabel->text() == "S = π × r²") {
        double r = ui->inputLineEdit1->text().toDouble();
        result = AreaCalculator::circle(r);
    } else if (ui->formulaLabel->text() == "S = ½ × r² × θ") {
        double r = ui->inputLineEdit1->text().toDouble();
        double theta = ui->inputLineEdit2->text().toDouble();
        result = AreaCalculator::sector(r, theta);
    }

    ui->resultLabel->setText(QString::number(result));
}

void MainWindow::clearFields() {
    ui->inputLineEdit1->clear();
    ui->inputLineEdit2->clear();
    ui->inputLineEdit3->clear();
    ui->resultLabel->clear();
}

void MainWindow::showAuthors() {
    QMessageBox::information(this, "Авторы", "Программа разработана уважаемыми и почитаемыми великими людьми - Marchi и potrox.");
}
