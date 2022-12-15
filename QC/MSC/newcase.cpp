#include "newcase.h"
#include "ui_newcase.h"
#include <widget.h>

#include <QMessageBox>
#include <QTimer>
#include <QFileDialog>
#include <QTextBrowser>
#include <QDesktopServices>

newcase::newcase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newcase)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(gettime()));
    timer->setSingleShot(true);
    timer->start();
    dir=new QDir("D:/Regan/QC/MSC/caseinfo");//源程序目录下的caseinfo目录
}

newcase::~newcase()
{
    delete ui;
}

//更新文本框内容
void newcase::gettime()
{
    aFile=new QFile(dir->path().append('/').append(date.toString("yyyyMMdd").append(".txt")));
    aFile->open(QIODevice::ReadWrite|QIODevice::Text);//以读写方式打开文件
    ui->caseinfo->setPlainText(aFile->readAll());//设置文本框内容为文件内容
    QTextCursor cursor = ui->caseinfo->textCursor();//首先获取QTextEdit总当前的光标位置
    cursor.movePosition(QTextCursor::End,QTextCursor::MoveAnchor);//移动光标位置到末尾
    ui->caseinfo->setTextCursor(cursor);//更新QTextEdit控件中光标
    aFile->close();
    QString media(dir->path().append('/').append(date.toString("yyyyMMdd")));
    QString mediadir(dir->path().append('/').append(date.toString("yyyyMMdd").append('/')));
    QDir dir(media);
    QUrl url=url.fromLocalFile(mediadir);
    QString qurl=url.toLocalFile();
    if(dir.exists())
    {
        ui->mediacase->append(tr("<html><p><a href=\"%1\">多媒体文件</a></p></html>").arg(qurl));
    }
}

//取消按钮槽函数
void newcase::on_cancel_clicked()
{
    this->close();
}

//获取当前点击的日期
void newcase::getclickeddate(QDate clickeddate)
{
    date=clickeddate;
}

//确定按钮槽函数
void newcase::on_confirm_clicked()
{
    //文件路径为/home/Documents/MyNotePad/年年年年月月日日.txt
    aFile=new QFile(dir->path().append('/').append(date.toString("yyyyMMdd").append(".txt")));
    aFile->remove();//删除文件
    aFile->open(QIODevice::ReadWrite|QIODevice::Text);//以读写方式打开文件
    QString str=ui->caseinfo->toPlainText();//获取文本框内容
    QByteArray strBytes=str.toUtf8();
    aFile->write(strBytes,strBytes.length());//将文本框内容写入文件
    aFile->close();//关闭文件
    QString mediadir(dir->path().append('/').append(date.toString("yyyyMMdd").append('/')));
    QFile savefile(fileName);
    QFileInfo savefileinfo(savefile);
    QString savename=savefileinfo.fileName();
    QFile::copy(fileName,mediadir+savename);
    QMessageBox::about(this,"提示","保存成功！");
    this->close();
}

//选择多媒体文件槽函数
void newcase::on_addmedia_clicked()
{
     fileName = QFileDialog::getOpenFileName(
        this,
        tr("open a file."),
        "D:/Regan/Photo/",
        tr("images(*.png *jpeg *bmp);;video files(*.avi *.mp4 *.wmv);;All files(*.*)"));
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "提示!", "请重新选择!");
    }
    else {
        QDir *mediadir=new QDir(dir->path().append('/').append(date.toString("yyyyMMdd")).append('/'));
        if(!mediadir->exists())
        {
            mediadir->mkdir(mediadir->path());
            ui->mediacase->append(tr("<html><p><a href=\"file:///%1\">多媒体文件</a></p></html>").arg(mediadir->path().left(mediadir->path().lastIndexOf('/'))));
            QMessageBox::warning(this, "提示!", "添加成功!");
        }
    }
}

