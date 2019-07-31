#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parsetext.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plainTextEdit_textChanged()
{
    QString txt = ui->plainTextEdit->toPlainText();

    qint32 pos = 0;
    while(1){
        qint32 fnd = txt.indexOf("#@", pos);
        if (fnd==-1) return;
        pos = fnd + 1;
        int r = txt.indexOf("=", fnd);
        int space = txt.indexOf(" ", fnd);
        if ((r<space || space==-1) && r!=-1){
            ParseText parseText(txt.mid(fnd+2,r-fnd-1));
            double answer = parseText.parse();
            txt.insert(r+1, QString::number(answer));
            txt.remove(fnd, 2);
            ui->plainTextEdit->setPlainText(txt);
        }
    }
}

void MainWindow::on_buttonExit_clicked()
{
    QMainWindow::close();
}
