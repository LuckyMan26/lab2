#ifndef QBASE_H
#define QBASE_H

#include <QObject>

class QBase : public QObject
{
    Q_OBJECT
public:
    explicit QBase(QObject *parent = nullptr);

signals:

};

#endif // QBASE_H
