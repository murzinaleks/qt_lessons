#include "keypressevent.h"
#include <QPushButton>

KeyPressEvent::KeyPressEvent()
{

}

bool KeyPressEvent::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::MouseButton::RightButton)
        {
            emit static_cast<QPushButton*>(obj)->clicked();
            return true;
        }
        else if (mouseEvent->button() == Qt::MouseButton::LeftButton)
        {
            return true;
        }
    }
    return false;
}
