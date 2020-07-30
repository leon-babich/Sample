#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_listValue.resize(50);
    QString str;
    for(int i=0,s=m_listValue.size(); i<s; i++) {
        str.append(QString::number(m_listValue[i]) + " ");
    }
    ui->textEdit->append(str);
}

Widget::~Widget()
{
    delete ui;
}
