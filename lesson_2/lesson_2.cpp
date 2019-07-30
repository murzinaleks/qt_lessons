#include "lesson_2.h"
#include "ui_lesson_2.h"
#include <QMessageBox>
#include <QFileSystemModel>

lesson_2::lesson_2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lesson_2)
{
    ui->setupUi(this);
    //ui->listWidget->addItem("Audi");

    ui->tableWidget->setRowCount(4);
    ui->tableWidget->setColumnCount(6);
    //ui->tableWidget->setHorizontalHeadrLabels(QStringLists() << "a" << "b" << "c" << "d");
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "a" << "b" << "c" << "d");
    for(int i=0; i < ui->tableWidget->rowCount(); ++i)
    {
        for(int j=0; j < ui->tableWidget->columnCount(); ++j)
        {
             QTableWidgetItem* item = new QTableWidgetItem(tr("Ячейка № %1, %2").arg(i).arg(j));
            ui->tableWidget->setItem(i,j,item);
        }
    }

    ui->treeWidget->setHeaderLabel("objects");
    QTreeWidgetItem* item1 = new QTreeWidgetItem();
    item1->setText(0, "object 1");
    QTreeWidgetItem* child = new QTreeWidgetItem();
    child->setText(0, "object 1.1");
    item1->addChild(child);
    QTreeWidgetItem* child2 = new QTreeWidgetItem();
    child2->setText(0, "object 1.2");
    item1->addChild(child2);

    ui->treeWidget->addTopLevelItem(item1);

}

lesson_2::~lesson_2()
{
    delete ui;
}

void lesson_2::on_pushButton_clicked()
{
    QMessageBox::information(this, "Info", ui->tableWidget->currentItem()->text());
}

void lesson_2::on_button_exit_clicked()
{
    QMainWindow::close();
}
