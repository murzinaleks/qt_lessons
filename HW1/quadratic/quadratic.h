#ifndef QUADRATIC_H
#define QUADRATIC_H

#include <QMainWindow>

namespace Ui {
class quadratic;
}

class quadratic : public QMainWindow
{
    Q_OBJECT

public:
    explicit quadratic(QWidget *parent = nullptr);
    ~quadratic();

private:
    Ui::quadratic *ui;
};

#endif // QUADRATIC_H
