#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include <QObject>

class TabWidget : public QTabWidget
{
public:
    TabWidget();
    void addEntry(const QString &name, const QString &address);
};

#endif // TABWIDGET_H
