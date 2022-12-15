import os
import wx
import wx.grid as wgrid
from xlrd import open_workbook
from xlwt import Workbook
from matplotlib import pyplot as plt

class student(wx.App):
    num = None

    def __init__(self, a):
        super(student, self).__init__()
        student.num = a

    def resizebmp(self, image, width, height):  # 图片的转换,限定图片大小 实现缩放
        bmp = image.Scale(width, height).ConvertToBitmap()  # 按照比例缩放
        return bmp

    # 主界面
    def frame(self):
        self.studentFrame = wx.Frame(None, title=u"学生信息管理系统", size=(700, 500), pos=(300, 200))
        self.studentFrame.SetMaxSize((700, 500))
        self.studentFrame.SetMinSize((700, 500))
        self.studentPanel = wx.Panel(self.studentFrame, -1, size=(750, 500))
        img = wx.Image("./pic/teacher.jpg", wx.BITMAP_TYPE_ANY).ConvertToBitmap()  # 转换成位图
        # 设置图片在panel中的位置
        self.staticbmp = wx.StaticBitmap(self.studentPanel, -1, img, pos=(0, 0))
        # 调用函数设置图片的大小
        myimg = wx.Image("./pic/teacher.jpg", wx.BITMAP_TYPE_ANY)
        self.staticbmp.SetBitmap(self.resizebmp(myimg, 700, 450))
        self.icon = wx.Icon(name="./pic/icon.ico", type=wx.BITMAP_TYPE_ICO)
        self.studentFrame.SetIcon(self.icon)

        self.menubar = wx.MenuBar()

        self.menu3 = wx.Menu()
        self.item5 = wx.MenuItem(self.menu3, wx.ID_ANY, u"课程成绩查询", wx.EmptyString, wx.ITEM_NORMAL)
        #self.item13 = wx.MenuItem(self.menu3, wx.ID_ANY, u"未通过课程表格呈现", wx.EmptyString, wx.ITEM_NORMAL)
        self.menu3.Append(self.item5)
        #self.menu3.Append(self.item13)
        self.menubar.Append(self.menu3, u"查询成绩")


        self.menu5 = wx.Menu()
        self.item11 = wx.MenuItem(self.menu5, wx.ID_ANY, u"修改密码", wx.EmptyString, wx.ITEM_NORMAL)
        self.menu5.Append(self.item11)
        self.menubar.Append(self.menu5, u"修改信息")
        self.studentFrame.SetMenuBar(self.menubar)

        self.studentFrame.Bind(wx.EVT_MENU, self.numSelect, id=self.item5.GetId())

        self.studentFrame.Bind(wx.EVT_MENU, self.alterPass, id=self.item11.GetId())

        #self.studentFrame.Bind(wx.EVT_MENU, self.displayFault, id=self.item13.GetId())
        self.studentFrame.Show()

    # 根据学号查询成绩
    def selectname(self, a):
        from login import connect
        db = connect()
        cr = db.cursor()
        sql = "select name from grade where num = %s;" % (a)
        cr.execute(sql)
        res = cr.fetchone()
        if res == None:
            return -1
        return res[0]

    #查找学生本人的成绩
    def numselect(self):
        from login import connect
        try:
            a = str(student.num)
            if a:
                sql = "select course1,course2,course3,sum from grade where num = %s;" % (a)
                db = connect()
                cr = db.cursor()
                cr.execute(sql)
                row = cr.fetchone()
                self.nameText.SetValue(a)
                self.course1Text.SetValue(str(row[0]))
                self.course2Text.SetValue(str(row[1]))
                self.course3Text.SetValue(str(row[2]))
                self.sumText.SetValue(str(row[3]))
                good, mid, pa, nopa = 0, 0, 0, 0
                for i in range(0, 3):
                    if row[i] > 60:
                        good += 1
                    elif row[i] >= 50 and row[i] < 60:
                        mid += 1
                    elif row[i] >= 10 and row[i] < 50:
                        pa += 1
                    else:
                        nopa += 1
                self.show.SetValue("姓名为" + self.selectname(a) + "的同学成绩分布如下")
                plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
                labels = [u'及格', u'60-50的课程', u'50-10的课程', u'成绩个位数']
                x = [good, mid, pa, nopa]
                colors = ['r', 'g', 'y', 'b']  # 自定义颜色列表
                if good == 0:
                    labels.remove(u'及格')
                    x.remove(good)
                if mid == 0:
                    labels.remove(u'60-50的课程')
                    x.remove(mid)
                if pa == 0:
                    labels.remove(u'50-10的课程')
                    x.remove(pa)
                if nopa == 0:
                    labels.remove(u'成绩个位数')
                    x.remove(nopa)
                pat = "./pic/save.png"
                plt.pie(x, labels=labels, autopct='%1.2f%%', textprops={'fontsize': 20, 'color': 'k'}, colors=colors)
                plt.axis('equal')  # 设为标准圆
                plt.savefig(pat)
                plt.close()
                img = wx.Image(pat, wx.BITMAP_TYPE_ANY).ConvertToBitmap()  # 转换成位图
                # 设置图片在panel中的位置
                staticbmp = wx.StaticBitmap(self.panel, -1, img, pos=(0, 20))
                # 调用函数设置图片的大小
                myimg = wx.Image(pat, wx.BITMAP_TYPE_ANY)
                staticbmp.SetBitmap(self.resizebmp(myimg, 267, 200))
        except Exception as e:
            wx.MessageBox('学号有误', '错误', wx.OK | wx.ICON_ERROR)

    # 界面
    def numSelect(self, event):
        self.nameSelectFrame = wx.Frame(None, title="课程表格查询", size=(618, 240), pos=(200, 120))
        self.nameSelectFrame.SetMaxSize((618, 240))
        self.nameSelectFrame.SetMinSize((618, 240))
        self.nameSelectPanel = wx.Panel(self.nameSelectFrame, -1, size=(350, 300))
        self.nameSelectPanel.SetBackgroundColour("white")
        self.icon = wx.Icon(name="./pic/icon.ico", type=wx.BITMAP_TYPE_ICO)
        self.nameSelectFrame.SetIcon(self.icon)
        self.nameLabel = wx.StaticText(self.nameSelectPanel, -1, "学    号", pos=(5, 30))
        self.nameText = wx.TextCtrl(self.nameSelectPanel, -1, pos=(60, 30), size=(90, 20),style=wx.TE_READONLY)
        self.course1Label = wx.StaticText(self.nameSelectPanel, -1, "语文成绩", pos=(165, 15))
        self.course1Text = wx.TextCtrl(self.nameSelectPanel, -1, pos=(260, 15), size=(50, 20), style=wx.TE_READONLY)
        self.course2Label = wx.StaticText(self.nameSelectPanel, -1, "数学成绩", pos=(165, 50))
        self.course2Text = wx.TextCtrl(self.nameSelectPanel, -1, pos=(260, 50), size=(50, 20), style=wx.TE_READONLY)
        self.course3Label = wx.StaticText(self.nameSelectPanel, -1, "英语成绩", pos=(165, 85))
        self.course3Text = wx.TextCtrl(self.nameSelectPanel, -1, pos=(260, 85), size=(50, 20), style=wx.TE_READONLY)
        self.sumLabel = wx.StaticText(self.nameSelectPanel, -1, "总成绩", pos=(165, 120))
        self.sumText = wx.TextCtrl(self.nameSelectPanel, -1, pos=(260, 120), size=(50, 20), style=wx.TE_READONLY)
        self.panel = wx.Panel(self.nameSelectFrame, -1, size=(267, 200), pos=(350, 0))
        self.panel.SetBackgroundColour("white")
        self.show = wx.TextCtrl(self.panel, -1, pos=(0, 0), size=(260, 20), style=wx.TE_READONLY)
        self.numselect()
        pat = "./pic/login.png"
        img = wx.Image(pat, wx.BITMAP_TYPE_ANY).ConvertToBitmap()  # 转换成位图
        # 设置图片在panel中的位置
        staticbmp = wx.StaticBitmap(self.nameSelectPanel, -1, img, pos=(0, 110))
        # 调用函数设置图片的大小
        myimg = wx.Image(pat, wx.BITMAP_TYPE_ANY)
        staticbmp.SetBitmap(self.resizebmp(myimg, 88, 88))
        self.nameSelectFrame.Show()

    # 修改密码
    def alterpass(self, event):
        from login import connect
        db = connect()
        cr = db.cursor()
        sql = "select password from student where username = '%s';" % (student.num)
        cr.execute(sql)
        res = cr.fetchone()
        a = res[0]
        if a != self.oldText.GetValue():
            wx.MessageBox('旧密码错误', 'error', wx.OK | wx.ICON_ERROR)
            self.oldText.SetValue("")
            self.newText.SetValue("")
            self.conNewText.SetValue("")
        else:
            if self.conNewText.GetValue() == self.newText.GetValue():
                sql = "update student set password = %s where username = '%s';" % (self.newText.GetValue(), student.num)
                cr.execute(sql)
                db.commit()
                wx.MessageBox("密码修改成功", '提示', wx.OK | wx.ICON_INFORMATION)
                self.oldText.SetValue("")
                self.newText.SetValue("")
                self.conNewText.SetValue("")
            else:
                wx.MessageBox('两次新密码输入不一致', 'error', wx.OK | wx.ICON_ERROR)
                self.oldText.SetValue("")
                self.newText.SetValue("")
                self.conNewText.SetValue("")

    # 界面
    def alterPass(self, event):
        self.alterpassFrame = wx.Frame(None, title="修改密码", size=(350, 250), pos=(500, 120))
        self.alterpassFrame.SetMaxSize((350, 250))
        self.alterpassFrame.SetMinSize((350, 250))
        self.alterpassPanel = wx.Panel(self.alterpassFrame, -1, size=(549, 260))
        self.alterpassPanel.SetBackgroundColour("white")
        self.icon = wx.Icon(name="./pic/icon.ico", type=wx.BITMAP_TYPE_ICO)
        self.alterpassFrame.SetIcon(self.icon)
        img = wx.Image("./pic/mi1.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()  # 转换成位图
        # 设置图片在panel中的位置
        self.staticbmp = wx.StaticBitmap(self.alterpassPanel, -1, img, pos=(0, 140))
        # 调用函数设置图片的大小
        myimg = wx.Image("./pic/mi1.png", wx.BITMAP_TYPE_ANY)
        self.staticbmp.SetBitmap(self.resizebmp(myimg, 76, 72))

        img = wx.Image("./pic/mi2.png", wx.BITMAP_TYPE_ANY).ConvertToBitmap()  # 转换成位图
        # 设置图片在panel中的位置
        self.staticbmp = wx.StaticBitmap(self.alterpassPanel, -1, img, pos=(257, 140))
        # 调用函数设置图片的大小
        myimg = wx.Image("./pic/mi2.png", wx.BITMAP_TYPE_ANY)
        self.staticbmp.SetBitmap(self.resizebmp(myimg, 76, 72))
        self.oldLabel = wx.StaticText(self.alterpassPanel, -1, "旧密码", pos=(45, 30))
        self.oldText = wx.TextCtrl(self.alterpassPanel, -1, pos=(130, 30), size=(150, 20), style=wx.TE_PASSWORD)
        self.newLabel = wx.StaticText(self.alterpassPanel, -1, "新密码", pos=(45, 70))
        self.newText = wx.TextCtrl(self.alterpassPanel, -1, pos=(130, 70), size=(150, 20), style=wx.TE_PASSWORD)
        self.conNewLabel = wx.StaticText(self.alterpassPanel, -1, "确认新密码", pos=(45, 110))
        self.conNewText = wx.TextCtrl(self.alterpassPanel, -1, pos=(130, 110), size=(150, 20), style=wx.TE_PASSWORD)
        self.button = wx.Button(self.alterpassPanel, -1, "确  定", size=(100, 25), pos=(125, 160))
        self.alterpassFrame.Bind(wx.EVT_BUTTON, self.alterpass, self.button)
        self.alterpassFrame.Show()

        self.numDeleteFrame = wx.Frame(None, title="删除学生成绩", size=(380, 200), pos=(500, 120))
        self.numDeleteFrame.SetMaxSize((380, 200))
        self.numDeleteFrame.SetMinSize((380, 200))
        self.numDeletePanel = wx.Panel(self.numDeleteFrame, -1, size=(549, 260))
        self.numDeletePanel.SetBackgroundColour("white")
        self.icon = wx.Icon(name="./pic/icon.ico", type=wx.BITMAP_TYPE_ICO)
        self.numDeleteFrame.SetIcon(self.icon)
        lblList = ['学       号', '姓      名']
        self.rbox = wx.RadioBox(self.numDeletePanel, label='选择删除方式', pos=(25, 20), choices=lblList, majorDimension=1,
                                style=wx.RA_SPECIFY_COLS)
        self.numText = wx.TextCtrl(self.numDeletePanel, -1, pos=(155, 30), size=(150, 20))
        self.deleteButton = wx.Button(self.numDeletePanel, -1, "删   除", size=(50, 25), pos=(170, 70))
        #self.numDeleteFrame.Bind(wx.EVT_BUTTON, self.numdelete, self.deleteButton)
        self.numDeleteFrame.Bind(wx.EVT_BUTTON, self.numSelect, self.deleteButton)
        img = wx.Image("./pic/delete.jpg", wx.BITMAP_TYPE_ANY).ConvertToBitmap()  # 转换成位图
        # 设置图片在panel中的位置
        self.staticbmp = wx.StaticBitmap(self.numDeletePanel, -1, img, pos=(270, 70))
        # 调用函数设置图片的大小
        myimg = wx.Image("./pic/delete.jpg", wx.BITMAP_TYPE_ANY)
        self.staticbmp.SetBitmap(self.resizebmp(myimg, 100, 100))
        self.numDeleteFrame.Show()