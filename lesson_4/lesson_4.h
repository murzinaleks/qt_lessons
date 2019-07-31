#ifndef LESSON_4_H
#define LESSON_4_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>
#include "keypressevent.h"

namespace Ui {
class Lesson_4;
}

class Lesson_4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lesson_4(QWidget *parent = nullptr);
    ~Lesson_4();

private:
    Ui::Lesson_4 *ui;
    QPushButton *nextPicButton, *prevPicButton;
    QSharedPointer<QLabel> label;
    void setPicture();
    QList<QString> pictureList;
    int curPicture;
    int posCursor;
    QSharedPointer<KeyPressEvent> repalceMouseButton;


protected:
    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    //virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void nextPicture();
    void prevPicture();

signals:
    void switchNextPicture();
    void switchPrevPicture();

};

#endif // LESSON_4_H
