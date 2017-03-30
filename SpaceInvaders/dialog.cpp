#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->update();
    //this->setStyleSheet("background-color: #82CAFF;");
}

Dialog::~Dialog()
{
    delete ui;
}

//void Dialog::paintEvent(QPaintEvent *event)
//{
//    QPainter painter(this);
//    // add after the creation of the painter object
//    QPen pen;
//    pen.setWidth(3);
//    pen.setColor(Qt::black);
//    QBrush brush(Qt::red);

//    painter.setPen (pen);
//    painter.setBrush(brush);
//    painter.drawEllipse(250, 250, 100, 100);

//    brush.setColor("#C36241");
//    painter.setBrush(brush);
//    pen.setWidth(1);

//    QPolygon roof;
//    roof.putPoints(0, 3, 250, 260, 290, 220, 330, 260);
//    painter.drawPolygon(roof);

//    brush.setColor("#835C3B");
//    painter.setBrush(brush);

//    QPolygon house;
//    house.putPoints(0, 4, 260, 260, 260, 299, 320, 299, 320, 260);
//    painter.drawPolygon(house);
//}

void Dialog::paintEvent(QPaintEvent *event)
{
      // code for this exercise goes here

}

