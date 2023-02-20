#include "qgridlayout.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "ui_delaywindow.h"
#include "delaywindow.h"
delayWindow::delayWindow(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->horizontalSlider->setTickInterval(1);
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(5);
    QPushButton* btn=new QPushButton(this);
    btn->setText("Submit");
    QLabel *label1 = new QLabel("0ms", this);

    QLabel *label2 = new QLabel("200ms", this);

    QLabel *label3 = new QLabel("400ms", this);

    QLabel *label4 = new QLabel("600ms", this);
    QLabel *label5 = new QLabel("800ms", this);

    QLabel *label6 = new QLabel("1000ms", this);



    QGridLayout *layout = new QGridLayout;
    layout->addWidget(ui->horizontalSlider, 0, 0, 1, 11);
    layout->addWidget(label1, 1, 0, 1, 1);
    layout->addWidget(label2, 1, 2, 1, 1);
    layout->addWidget(label3, 1, 4, 1, 1);
    layout->addWidget(label4, 1, 6, 1, 1);
    layout->addWidget(label5, 1, 8, 1, 1);
    layout->addWidget(label6, 1, 10, 1, 1);


    layout->addWidget(btn,2,3,5,5);
    connect(btn,SIGNAL(clicked()),this,SLOT(getDelay()));
    setLayout(layout);


}
delayWindow::~delayWindow(){

    delete ui;
}
int delayWindow::getDelay(void){
    this->close();
   return (200*ui->horizontalSlider->value());

}

