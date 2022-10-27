#include "dialog.h"
#include "qpushbutton.h"
#include "qslider.h"
#include "ui_dialog.h"
#include <QLabel>
#include <QGridLayout>
Dialog::Dialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->horizontalSlider->setTickInterval(15);
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(15);
    QPushButton* btn=new QPushButton(this);
    btn->setText("Submit");
    QLabel *label1 = new QLabel("0", this);

    QLabel *label2 = new QLabel("1", this);
    QLabel *label3 = new QLabel("2", this);
    QLabel *label4 = new QLabel("3", this);
    QLabel *label5 = new QLabel("4", this);
    QLabel *label6 = new QLabel("5", this);
    QLabel *label7 = new QLabel("6", this);
    QLabel *label8 = new QLabel("7", this);
    QLabel *label9 = new QLabel("8", this);
    QLabel *label10 = new QLabel("9", this);
    QLabel *label11 = new QLabel("10", this);
    QLabel *label12 = new QLabel("11", this);
    QLabel *label13 = new QLabel("12", this);
    QLabel *label14 = new QLabel("13", this);
    QLabel *label15 = new QLabel("14", this);
    QLabel *label16 = new QLabel("15", this);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(ui->horizontalSlider, 0, 0, 1, 16);
    layout->addWidget(label1, 1, 0, 1, 1);
    layout->addWidget(label2, 1, 1, 1, 1);
    layout->addWidget(label3, 1, 2, 1, 1);
    layout->addWidget(label4, 1, 3, 1, 1);
    layout->addWidget(label5, 1, 4, 1, 1);
    layout->addWidget(label6, 1, 5, 1, 1);
    layout->addWidget(label7, 1, 6, 1, 1);
    layout->addWidget(label8, 1, 7, 1, 1);
    layout->addWidget(label9, 1, 8, 1, 1);
    layout->addWidget(label10, 1, 9, 1, 1);
    layout->addWidget(label11, 1, 10, 1, 1);
    layout->addWidget(label12, 1, 11, 1, 1);
    layout->addWidget(label13, 1, 12, 1, 1);
    layout->addWidget(label14, 1, 13, 1, 1);
    layout->addWidget(label15, 1, 14, 1, 1);
    layout->addWidget(label16, 1, 15, 1, 1);
    layout->addWidget(btn,2,5,5,5);
    connect(btn,SIGNAL(clicked()),this,SLOT(getSize()));
    setLayout(layout);


}
Dialog::~Dialog()
{
    delete ui;
}
int Dialog::getSize(void){

   this->close();

   return ui->horizontalSlider->value();

}
