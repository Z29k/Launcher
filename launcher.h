#ifndef LAUNCHER_H
#define LAUNCHER_H

#include "applications.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QPainter>
#include <QDebug>

namespace Ui {
class Launcher;
}

class Launcher : public QMainWindow
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);

public:
    explicit Launcher(QWidget *parent = 0);
    ~Launcher();

private slots:
    void on_searchEdit_returnPressed();

private:
    Applications applications;
    Ui::Launcher *ui;

signals:
    void done();
};

#endif // LAUNCHER_H
