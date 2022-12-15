#ifndef WIDGET_H
#define WIDGET_H

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QWidget>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget *ui;
    //多媒体文件保存路径
    QDir *aDir;
    //文件保存路径
    QDir *dir;
    //查找计数
    int countnum=0;
    //文件读取
    QFile *aFile;
    //查找到的文件
    QStringList foundFiles;
    //选中日期
    QDate date;
    //请求句柄
    QNetworkAccessManager *manager;
    //系统时间
    QDateTime systime;
    //系统时间字符
    QString qsystime;
    //判断时钟闪烁
    bool flash=true;
    //闹钟时间
    QDateTime alarm;
    //发送请求
    void getWeatherInfo(QNetworkAccessManager *manager);
    void parsejson(QByteArray&bytes);
    void timerEvent(QTimerEvent *);
public slots:
    void on_ckShowLunar_stateChanged(int arg1);
    void showtoday();
    void getclickeddate(QDate clickeddate);
    void replyFinished(QNetworkReply *reply);
    void showcase(QDate date);
    void on_deletecase_clicked();
    void sendjump(QDate date);
private slots:
    void on_editcase_clicked();
    void on_search_clicked();
    void on_next_clicked();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void changedate(QDate date);
};
#endif // WIDGET_H
