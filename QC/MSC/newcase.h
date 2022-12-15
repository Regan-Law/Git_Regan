#ifndef NEWCASE_H
#define NEWCASE_H

#include <QWidget>
#include <QDate>
#include <QDir>

namespace Ui {
class newcase;
}

class newcase : public QWidget
{
    Q_OBJECT

public:
    explicit newcase(QWidget *parent = nullptr);
    ~newcase();

public slots:
    void on_cancel_clicked();
    void gettime();
    void getclickeddate(QDate clickeddate);
    void on_confirm_clicked();
private slots:
    void on_addmedia_clicked();

private:
    Ui::newcase *ui;
    //选中日期
    QDate date;
    //文件保存路径
    QDir *dir;
    //文件读取
    QFile *aFile;
    //多媒体文件名
    QString fileName;
};

#endif // NEWCASE_H
