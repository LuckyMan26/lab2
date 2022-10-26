#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>
namespace Ui {
    class Dialog;
}
class Dialog: public QDialog
{
    Q_OBJECT;
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    int getSize(void);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
