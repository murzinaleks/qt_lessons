#ifndef KEYPRESSEVENT_H
#define KEYPRESSEVENT_H

#include <QObject>
#include <QEvent>
#include <QMouseEvent>

class KeyPressEvent : public QObject
{
public:
    KeyPressEvent();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // KEYPRESSEVENT_H
