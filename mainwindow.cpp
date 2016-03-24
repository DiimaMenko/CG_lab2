#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->pushButtonAddPolygonPoint, SIGNAL(clicked(bool)), this, SLOT(addPoint()));
    connect(this->ui->pushButtonStartCalculation, SIGNAL(clicked(bool)), this, SLOT(calculate()));
    connect(this->ui->pushButtonDeletePolygonPoint, SIGNAL(clicked(bool)), this, SLOT(deletePoint()));

    this->numberOfPoints = 3;
    this->labelResult = new QLabel("abracadabra", this);
    this->labelResult->move(410, 50);
    this->labelResult->resize(210, 16);
    this->labelResult->show();

    this->ui->lineEditPointX->setText("3");
    this->ui->lineEditPointY->setText("6");
    this->ui->lineEditPolygonX1->setText("2");
    this->ui->lineEditPolygonY1->setText("6");
    this->ui->lineEditPolygonX2->setText("6");
    this->ui->lineEditPolygonY2->setText("10");
    this->ui->lineEditPolygonX3->setText("10");
    this->ui->lineEditPolygonY3->setText("6");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPoint(){
    if(this->numberOfPoints >= 13){
        return;
    }
    else{
        this->numberOfPoints++;
    }
    QString numberOfPoint("Точка ");
    numberOfPoint.push_back(QString::number(this->numberOfPoints));
    QLabel *temp = new QLabel(numberOfPoint, this);
    temp->move(120, 30 + this->numberOfPoints * 30);
    temp->resize(47, 16);
    temp->show();
    this->addedLabels.push_back(temp);
    QLabel *temp2 = new QLabel("X:", this);
    temp2->move(170, 30 + this->numberOfPoints * 30);
    temp2->resize(16, 16);
    temp2->show();
    this->addedLabels.push_back(temp2);
    QLabel *temp3 = new QLabel("Y:", this);
    temp3->move(280, 30 + this->numberOfPoints * 30);
    temp3->resize(16, 16);
    temp3->show();
    this->addedLabels.push_back(temp3);
    QLineEdit *temp4 = new QLineEdit(this);
    temp4->move(190, 30 + this->numberOfPoints * 30);
    temp4->resize(71, 21);
    temp4->show();
    this->addedLineEditesX.push_back(temp4);
    QLineEdit *temp5 = new QLineEdit(this);
    temp5->move(300, 30 + this->numberOfPoints * 30);
    temp5->resize(71, 21);
    temp5->show();
    this->addedLineEditesY.push_back(temp5);
    this->ui->pushButtonAddPolygonPoint->move(120, 60 + this->numberOfPoints * 30);
    this->ui->pushButtonDeletePolygonPoint->move(250, 60 + this->numberOfPoints * 30);
}

void MainWindow::deletePoint(){
    if(this->addedLineEditesX.size() > 0){
        this->addedLineEditesX[this->addedLineEditesX.size() - 1]->hide();
        this->addedLineEditesX.pop_back();
        this->numberOfPoints--;
        this->ui->pushButtonAddPolygonPoint->move(120, 60 + this->numberOfPoints * 30);
        this->ui->pushButtonDeletePolygonPoint->move(250, 60 + this->numberOfPoints * 30);
    }
    if(this->addedLineEditesY.size() > 0){
        this->addedLineEditesY[this->addedLineEditesY.size() - 1]->hide();
        this->addedLineEditesY.pop_back();
    }
    if(this->addedLabels.size() > 2){
        for(int i = 0; i < 3; i++){
            this->addedLabels[this->addedLabels.size() - 1]->hide();
            this->addedLabels.pop_back();
        }
    }
}

void MainWindow::calculate(){
    QVector<Point* > pol;
    Point *tempPoint1;
    Point *tempPoint2;
    Point *tempPoint3;
    Point *tempPoint4;
    double tempX = 0, tempY = 0;
    pol.resize(0);

    tempX = this->ui->lineEditPolygonX1->text().toFloat();
    tempY = this->ui->lineEditPolygonY1->text().toFloat();
    tempPoint1 = new Point(tempX, tempY);
    pol.push_back(tempPoint1);

    tempX = this->ui->lineEditPolygonX2->text().toFloat();
    tempY = this->ui->lineEditPolygonY2->text().toFloat();
    tempPoint2 = new Point(tempX, tempY);
    pol.push_back(tempPoint2);

    tempX = this->ui->lineEditPolygonX3->text().toFloat();
    tempY = this->ui->lineEditPolygonY3->text().toFloat();
    tempPoint3 = new Point(tempX, tempY);
    pol.push_back(tempPoint3);
    for(int i = 0; i < this->addedLineEditesX.size(); i++){
        tempX = this->addedLineEditesX[i]->text().toFloat();
        tempY = this->addedLineEditesY[i]->text().toFloat();
        Point *tempPoint5 = new Point(tempX, tempY);
        pol.push_back(tempPoint5);
    }

    this->figure->setPolygon(pol);

    tempX = this->ui->lineEditPointX->text().toFloat();
    tempY = this->ui->lineEditPointY->text().toFloat();
    tempPoint4 = new Point(tempX, tempY);

    if(this->figure->isPointInOrOut(tempPoint4)){
        this->labelResult->setText("Точка знаходиться всередині багатокутника");
        labelResult->show();
    }
    else
    {
        this->labelResult->setText("Точка знаходиться зовні багатокутника");
        labelResult->show();
    }
}

bool MainWindow::check(){
    return true;
}
