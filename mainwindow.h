#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <point.h>
#include <polygon.h>
#include <QLabel>
#include <QLineEdit>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addPoint();
    void calculate();
    void deletePoint();

private:
    Ui::MainWindow *ui;
    Polygon *figure;
    int numberOfPoints;
    bool check();
    QVector<QLabel*> addedLabels;
    QVector<QLineEdit*> addedLineEditesX;
    QVector<QLineEdit*> addedLineEditesY;
    QLabel *labelResult;
};

#endif // MAINWINDOW_H
