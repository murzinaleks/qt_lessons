#ifndef LESSON_2_H
#define LESSON_2_H

#include <QMainWindow>

namespace Ui {
class lesson_2;
}

class lesson_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit lesson_2(QWidget *parent = nullptr);
    ~lesson_2();

private slots:
    void on_pushButton_clicked();

    void on_button_exit_clicked();

private:
    Ui::lesson_2 *ui;
};

#endif // LESSON_2_H
