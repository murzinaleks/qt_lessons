#include "lesson_4.h"
#include "ui_lesson_4.h"
#include "keypressevent.h"
#include <QPixmap>

Lesson_4::Lesson_4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lesson_4)
{
    ui->setupUi(this);

    pictureList.append(":/res/pp.jpg");
    pictureList.append(":/res/rsa.JPG");
    pictureList.append(":/res/rsa-2.JPG");

    label = QSharedPointer<QLabel>(new QLabel(this));
    label->setGeometry(10,10,589,330);
    curPicture = 0;
    setPicture();

    nextPicButton = new QPushButton(this);
    prevPicButton = new QPushButton(this);

    nextPicButton->move(470, 340);
    nextPicButton->resize(120, 30);
    nextPicButton->setText("Next");


    prevPicButton->move(10, 340);
    prevPicButton->resize(120, 30);
    prevPicButton->setText("Previous");

    connect(nextPicButton, SIGNAL(clicked()), this, SLOT(nextPicture()));
    connect(prevPicButton, SIGNAL(clicked()), this, SLOT(prevPicture()));

    connect(this, SIGNAL(switchNextPicture()), this, SLOT(nextPicture()));
    connect(this, SIGNAL(switchPrevPicture()), this, SLOT(prevPicture()));

    repalceMouseButton = QSharedPointer<KeyPressEvent>::create();
    nextPicButton->installEventFilter(repalceMouseButton.get());
    prevPicButton->installEventFilter(repalceMouseButton.get());


}

Lesson_4::~Lesson_4()
{
    if (nextPicButton) delete nextPicButton;
    if (prevPicButton) delete prevPicButton;
    delete ui;
}

void Lesson_4::setPicture()
{
    QPixmap pix(pictureList[curPicture]);
    pix = pix.scaled(530,330, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
    label->setPixmap(pix);
}

void Lesson_4::nextPicture()
{
    curPicture++;
    if (curPicture>2) curPicture = 2;
    setPicture();
}

void Lesson_4::prevPicture()
{
    if (curPicture>0) curPicture--;
    setPicture();
}

void Lesson_4::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Right)
    {
        emit switchNextPicture();
    }
    else if (event->key() == Qt::Key_Left)
    {
        emit switchPrevPicture();
    }
}

void Lesson_4::mousePressEvent(QMouseEvent *event)
{
    posCursor = event->x();
}

void Lesson_4::mouseReleaseEvent(QMouseEvent *event)
{
    int x = event->x();
    if (x - posCursor > 0)
    {
        emit switchNextPicture();
    }
    else if (x - posCursor < 0)
    {
        emit switchPrevPicture();
    }
}

