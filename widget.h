#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    void generateValues();
    void procArray();

private:
    Ui::Widget *ui;
    QVector<int> m_listValue;
};

#endif // WIDGET_H
