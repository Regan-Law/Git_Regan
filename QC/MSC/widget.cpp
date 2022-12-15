#include "widget.h"
#include "ui_widget.h"
#include "newcase.h"
#include "lunarcalendarwidget.h"

#include <QDate>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QTimer>
#include <QMessageBox>
#include <QJsonArray>
#include <QDir>
#include <QDebug>
#include <QDesktopServices>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->startTimer(500);
    QTimer *timer=new QTimer(this);
    timer->setSingleShot(true);
    timer->start();
    QDateTime todaytime=QDateTime::currentDateTime();
    ui->timeselect->setDateTime(todaytime);
    //新建QNetworkAccessManager对象
    manager=new QNetworkAccessManager(this);
    //关联信号和槽
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
    getWeatherInfo(manager);
    dir=new QDir("D:/Regan/QC/MSC/caseinfo");//源程序目录下的caseinfo目录
    if(!dir->exists())//路径不存在
    {
        dir->mkdir(dir->path());//新建路径
    }
    QDate today=QDate::currentDate();
    date=today;//默认今天为选中日期
    showcase(date);//默认显示今天的备忘录
    //连接信号和槽函数
    connect(timer,SIGNAL(timeout()),this,SLOT(showtoday()));
    connect(ui->widget,SIGNAL(clicked(QDate)),this,SLOT(getclickeddate(QDate)));
    connect(ui->widget,SIGNAL(clicked(QDate)),this,SLOT(showcase(QDate)));
    connect(this,SIGNAL(changedate(QDate)),ui->widget,SLOT(dayChanged(QDate)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ckShowLunar_stateChanged(int arg1)
{
    ui->widget->setShowLunar(arg1 != 0);
}

//获取今日日期
void Widget::showtoday()
{
    QDate today=QDate::currentDate();
    QString stoday=today.toString("yyyy-MM-dd");
    ui->today->setText(stoday);
}

//发送获取天气信息请求
void Widget::getWeatherInfo(QNetworkAccessManager *manager)
{
    QUrl jsonUrl("http://t.weather.itboy.net/api/weather/city/101190101");
    //发送get网络请求
    manager->get(QNetworkRequest(jsonUrl));
}

//通过接口获取天气信息
void Widget::replyFinished(QNetworkReply *reply)
{
    /* 获取响应的信息，状态码为200表示正常 */
    //reply是一个应答。在这里，需要应答是没有错误，和状态码正常：200，说明请求很顺利。
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(reply->error() != QNetworkReply::NoError || status_code != 200)
    {
        QMessageBox::warning(this, u8"错误", u8"天气：请求数据错误，检查网络连接！", QMessageBox::Ok);
        return;
    }
    //使用QByteArray字节数组来读取数据
    QByteArray bytes = reply->readAll();
    parsejson(bytes);
}

//处理接口反馈的json信息
void Widget::parsejson(QByteArray&bytes)
{
    QJsonParseError err;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(bytes, &err); // 检测json格式
    if (err.error != QJsonParseError::NoError) // Json格式错误
    {
        return;
    }     // 今日数据
    if (!jsonDoc.isNull())
    {
        QJsonObject object = jsonDoc.object();
        if (object.contains("data"))
        {
            QJsonValue value = object.value("data");  // 获取指定 key 对应的 value
            if (value.isObject())
            {
                QJsonObject object_data = value.toObject();
                if (object_data.contains("forecast"))
                {
                    QJsonValue today = object_data.value("forecast");
                    if (today.isArray())
                    {
                        QJsonObject today_weather = today.toArray().at(0).toObject();
                        QString weather_type = today_weather.value("type").toString();
                        QString low = today_weather.value("low").toString();
                        QString high = today_weather.value("high").toString();
                        QString wendu = low.mid(low.length() - 4, 4) + "~" + high.mid(high.length() - 4, 4);
                        QString strength = today_weather.value("fl").toString();
                        strength.remove(0, 8);
                        strength.remove(strength.length() - 2, 2);
                        QString fengli = today_weather.value("fx").toString() + strength;
                        ui->weatherinformation->setText(weather_type+wendu+fengli);
                    }
                }
            }
        }
    }
}

//获取选中日期的日期
void Widget::getclickeddate(QDate clickeddate)
{
    date=clickeddate;
}

//显示选中日期的备忘录
void Widget::showcase(QDate date)
{
    //文件路径为源程序目录下的caseinfo/年年年年月月日日.txt
    QString fileName=dir->path().append('/').append(date.toString("yyyyMMdd").append(".txt"));
    aFile=new QFile(fileName);
    ui->caseinfo->document()->clear();
    if(!aFile->exists())//路径不存在
    {
        ui->caseinfo->clear();//清空文本框
    }
    else//路径存在
    {
        aFile->open(QIODevice::ReadOnly|QIODevice::Text);//以只读方式打开文件
        ui->caseinfo->setPlainText(aFile->readAll());//设置文本框内容为文件内容
    }
    aFile->close();//关闭文件
    QString media(dir->path().append('/').append(date.toString("yyyyMMdd")));
    QString mediadir(dir->path().append('/').append(date.toString("yyyyMMdd").append('/')));
    QDir dir(media);
    QUrl url=url.fromLocalFile(mediadir);
    QString qurl=url.toLocalFile();
    if(dir.exists())//判断是否存在该日期的文件夹
    {
        ui->caseinfo->append(tr("<html><p><a href=\"%1\">多媒体文件</a></p></html>").arg(qurl));
    }
}

//删除选中日期的备忘录
void Widget::on_deletecase_clicked()
{
    //文件路径为源程序目录下的caseinfo/年年年年月月日日.txt
    QString fileName=dir->path().append('/').append(date.toString("yyyyMMdd").append(".txt"));
    QString dirName=dir->path().append('/').append(date.toString("yyyyMMdd"));
    aFile=new QFile(fileName);
    aDir=new QDir(dirName);
    if(!aFile->exists())//路径不存在
    {
        QMessageBox::about(this,"提示","备忘录已清空！");
    }
    else//路径存在
    {
        aFile->remove();//删除文件

        aDir->removeRecursively();//删除多媒体文件夹
        ui->caseinfo->clear();//清空文本框
        QMessageBox::about(this,"提示","删除成功！");
    }
    aFile->close();//关闭文件
}

//发送信号的槽函数
void Widget::sendjump(QDate date)
{
    emit changedate(date);
}

//编辑按钮的槽函数
void Widget::on_editcase_clicked()
{
    newcase *n=new newcase();
    n->getclickeddate(date);
    n->show();
    showcase(date);
}

//搜索按钮的槽函数
void Widget::on_search_clicked()
{
    countnum=0;
    foundFiles.clear();
    QString textinfo=ui->searchinfo->toPlainText();//获取搜索框的内容
    dir->setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    dir->setSorting(QDir::Reversed);//排序
    QStringList list=dir->entryList();//列出所有符合的文件
    list<<"*.txt";//遍历筛选特定文件（*.txt）
    dir->setNameFilters(list);//过滤文件
    if(list.count()<=1)
    {
        QMessageBox::about(this,"提示","不存在任何文本备忘录！");
    }
    else if(textinfo.isEmpty()==true)
    {
        QMessageBox::about(this,"提示","请输入搜索内容！");
    }
    else
    {
        for(int i=0;i<list.count();i++)
        {
            QFile file(dir->absoluteFilePath(list[i])); //取绝对文件路径
            if(file.open(QIODevice::ReadOnly)) //只读方式打开文件
            {
                QString line;    //存放一行文本
                QTextStream in(&file); //文本流
                while(!in.atEnd())
                { //还没读到文件尾循环
                    line = in.readLine(); //文本流对象读一行文本
                    if(line.contains(textinfo,Qt::CaseInsensitive))
                    { //这一行中包含有要找的文本(不区分大小写
                        foundFiles<<list[i].section(".",0,0); //加入到找到的文件列表中(加入的是日期）
                        break;  //找到文本，终止对此文件的查找
                    }
                }
            }
        }
        if(foundFiles.count()>0)//如果找到文件
        {
            QMessageBox::about(this,"提示","查找成功！");
            QDate d=QDate::fromString(foundFiles[0],"yyyyMMdd");
            sendjump(d);//发送信号
            countnum++;
        }
        else
        {
            QMessageBox::about(this,"提示","未查找到指定内容！");
        }
    }
}

//下一个按钮槽函数
void Widget::on_next_clicked()
{
    if(foundFiles.count()>0&&countnum<foundFiles.count())//存在查找到的文件且遍历没有来到最后一个
    {
        QDate d=QDate::fromString(foundFiles[countnum],"yyyyMMdd");
        sendjump(d);
        countnum++;//计数自增
    }
    else if(foundFiles.count()==countnum)//遍历至最后一个文件
    {
        QDate d=QDate::fromString(foundFiles[countnum-1],"yyyyMMdd");
        sendjump(d);
        QMessageBox::about(this,"提示","已查找至最后一个！");
    }
    else
    {
        QMessageBox::about(this,"提示","请先点击查找！");
    }
}

//定时器函数
void Widget::timerEvent(QTimerEvent *)
{
    systime = QDateTime::currentDateTime();//获取系统时间
    qsystime=systime.toString("hh:mm:ss");//将时间类对象转换为字符串
    ui->currenttime->setDigitCount(8);//设置为显示8位
    //设置时钟的闪烁切换，每秒都在执行
    if(flash==true)
    {
        qsystime[2]=' ';
        qsystime[5]=' ';
        flash=false;
    }else
    {
        qsystime[2]=':';
        qsystime[5]=':';
        flash=true;
    }
    ui->currenttime->display(qsystime);
    if(alarm.toString("yyyyMMdd,hhmm")==systime.toString("yyyyMMdd,hhmm"))
    {
        QMessageBox::about(this,"提示","定时提醒！");
        QDateTime initdate=QDateTime(QDate(2000,1,1),QTime(0,0,0));
        alarm=initdate;
    }
}

//设置定时提醒
void Widget::on_pushButton_clicked()
{
    QDateTime initdate=QDateTime(QDate(2000,1,1),QTime(0,0,0));
    alarm=ui->timeselect->dateTime();
    if(!alarm.isNull())
    {
        QMessageBox::about(this,"提示","设置成功！");
    }
    else
    {
        QMessageBox::about(this,"提示","设置失败，请重新设置！");
    }
}

//取消提醒
void Widget::on_pushButton_2_clicked()
{
    QDateTime initdate=QDateTime(QDate(2000,1,1),QTime(0,0,0));
    alarm=initdate;
}

