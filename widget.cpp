#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_listValue.resize(50);     //инициализация массива
    generateValues();           //заполнение

    QString str;
    for(int i=0,s=m_listValue.size(); i<s; i++) {
        str.append(QString::number(m_listValue[i]) + " ");
    }
    ui->textEdit->append(str);   //вывод массива
}

Widget::~Widget()
{
    delete ui;
}

void Widget::generateValues()
{
    qsrand(0);

    for(auto &val : m_listValue) {
        val = qrand() % 500;
    }
}

void Widget::procArray()
{
    int insert;
    for(int next=1, s=m_listValue.size(); next<s; next++) {
        insert = m_listValue[next];

        int moveIt = next;

        while(moveIt>0 && m_listValue[moveIt-1] > insert) {
            m_listValue[moveIt] = m_listValue[moveIt-1];
            moveIt--;
        }

        m_listValue[moveIt] = insert;
    }
}

void Widget::on_pushButton_clicked()
{
    procArray();

    QString str;
    for(int i=0,s=m_listValue.size(); i<s; i++) {
        str.append(QString::number(m_listValue[i]) + " ");
    }

    ui->textEdit_2->append(str);   //вывод массива
}
