#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDoubleSpinBox>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Формула Мостеллера");
    ui->comboBox->addItem("Формула Дюбуа");
    ui->comboBox->addItem("Формула Дюбуа (модификация)");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{

}

void MainWindow::on_doubleSpinBox_2_valueChanged(double arg2)
{

}

void MainWindow::on_pushButton_clicked()
{
    int index = ui->comboBox->currentIndex();
    float height = ui->doubleSpinBox->value();
    float weight = ui->doubleSpinBox_2->value();
    float result = 0;

if (ui->checkBox->isChecked() == false)
 {
    if(index == 0)
    {
        result = ( sqrt(weight*height/3600));
        QMessageBox::information(this,"Итог ",QString("Ваша площадь в квадратных метрах равна: %1").arg(result));

    } else if(index== 1)
    {
        result = ((powf(weight,0.425))*(powf(height,0.725))/139.2);
        QMessageBox::information(this,"Итог ",QString("Ваша площадь в квадратных метрах равна: %1").arg(result));

    }else if (index ==2)
    {
        result = ((0.007184 *powf(weight,0.425))*(powf(height,0.725)));
        QMessageBox::information(this,"Итог ",QString("Ваша площадь в квадратных метрах равна: %1").arg(result));

    }
 } else
  {
   // ui->checkBox->setEnabled(false);
    result = (( sqrt(weight*height/3600))+((powf(weight,0.425))*(powf(height,0.725))/139.2)+((0.007184 *powf(weight,0.425))*(powf(height,0.725))))/3;
    QMessageBox::information(this,"Итог ",QString("СРЕДНЯЯ ПО ФОРМУЛАМ Ваша площадь в квадратных метрах равна: %1").arg(result));
  }
}
void MainWindow::on_doubleSpinBox_editingFinished()
{

}


void MainWindow::on_radioButton_clicked(bool checked)
{

}

void MainWindow::on_checkBox_clicked()
{
    bool b;
    if(ui->checkBox->isChecked()==true)
    {
   b =false;
    ui->comboBox->setEnabled(b);
    }
    else
    {
        b=true; ui->comboBox->setEnabled(b);
    }
}
