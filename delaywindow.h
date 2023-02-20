#ifndef DELAYWINDOW_H
#define DELAYWINDOW_H


#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
namespace Ui {
    class Dialog;
}
class delayWindow: public QDialog
{
    Q_OBJECT;
public:
    delayWindow(QWidget *parent = 0);
    ~delayWindow();
public slots:
    int getDelay(void);

private:
    Ui::Dialog *ui;
};

#endif // DELAYWINDOW_H
