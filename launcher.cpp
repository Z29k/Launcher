#include "launcher.h"
#include "ui_launcher.h"

Launcher::Launcher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Launcher)
{
    ui->setupUi(this);

    QString appsPath = QCoreApplication::applicationDirPath() + "/apps.json";
    applications.loadFromJson(appsPath);

    connect(this, SIGNAL(done()), QCoreApplication::instance(), SLOT(quit()));

    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setParent(0); // Create TopLevel-Widget
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_PaintOnScreen);
}

Launcher::~Launcher()
{
    delete ui;
}

/*
 * Search the db or whatever for app.
 * Show error message if no app found.
 */
void Launcher::on_searchEdit_returnPressed()
{
    QString name = ui->searchEdit->text();
    if (!applications.launch(name))
        ui->searchEdit->clear();
    else
        emit done();

}

void Launcher::paintEvent(QPaintEvent *)
{
    QColor backgroundColor = palette().dark().color();
    backgroundColor.setAlpha(100);
    QPainter customPainter(this);
    customPainter.fillRect(rect(), backgroundColor);
}

void Launcher::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == 16777216)
        emit done();
}
