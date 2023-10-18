#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
using namespace std;
typedef struct stuff
{
    int no;
    string name;
    string depname;
    string title;
    int salary;
    stuff *next;
    stuff *pre;
} stuff;
class stuffs
{
private:
    stuff *head;
    stuff *tail;

public:
    int count = 0;
    stuffs();
    ~stuffs();
    //增加一个职工信息
    void create();
    //批量增加职工信息
    void creates(int n);
    //显示所有职工信息
    void print();
    //根据编号删除职工信息
    void delete_no(int x);
    //根据部门批量删除职工信息
    void delete_depname(string dep);
    //根据职称批量删除职工信息
    void delete_title(string tit);
    //根据编号查找职工信息
    void locate_no(int x);
    //根据姓名查找职工信息
    void locate_name(string nam);
    //根据部门查找职工信息
    void locate_depname(string dep);
    //根据职称查找职工信息
    void locate_title(string tit);
    //按部门显示各部门职工工资总额
    void salary_depname();
    //按职称显示各部门职工工资总额
    void salary_title();
    //按编号调整工资
    void adjust_no(int x, int s);
    //按部门调整工资
    void adjust_depname(string dep, int s);
    //按职称调整工资
    void adjust_title(string tit, int s);
    //返回头指针
    stuff *gethead() { return head; }
    void reverse();
    void DeleteMax();
};
stuffs::stuffs()
{
    head = new stuff;
    tail = new stuff;
    head->next = tail;
    tail->pre = head;
    tail->next = NULL;
}

void stuffs::create()
{
    stuff *p;
    p = new stuff;
    cout << "请输入所需添加的职工信息" << endl;
    cout << "编号：";
    cin >> p->no;
    cout << "姓名：";
    cin >> p->name;
    cout << "部门：";
    cin >> p->depname;
    cout << "职称：";
    cin >> p->title;
    cout << "工资：";
    cin >> p->salary;
    p->next = tail;
    p->pre = tail->pre;
    tail->pre->next = p;
    tail->pre = p;
    count++;
}
stuffs::~stuffs()
{
    stuff *p;
    while (head)
    {
        p = head;
        head = head->next;
        delete p;
    }
    head = tail = NULL;
}
void stuffs::creates(int n)
{
    stuff *p;
    cout << "请批量输入所需添加的职工信息" << endl;
    for (int i = 0; i < n; i++)
    {
        p = new stuff;
        cout << "编号：";
        cin >> p->no;
        cout << "姓名：";
        cin >> p->name;
        cout << "部门：";
        cin >> p->depname;
        cout << "职称：";
        cin >> p->title;
        cout << "工资：";
        cin >> p->salary;
        p->next = tail;
        p->pre = tail->pre;
        tail->pre->next = p;
        tail->pre = p;
        count++;
    }
}
void stuffs::print()
{
    stuff *p = head->next;
    while (p == tail)
    {
        cout << "无职工信息，请添加职工信息再试" << endl;
        return;
    }
    while (p != tail)
    {
        cout << "编号：" << p->no << " 姓名：" << p->name << " 部门：" << p->depname << " 职称：" << p->title << " 工资：" << p->salary << endl;
        p = p->next;
    }
    cout << endl;
}
void stuffs::locate_no(int x)
{
    stuff *p = head->next;
    while (p == tail)
    {
        cout << "无职工信息，请添加职工信息再试" << endl;
        return;
    }
    while (p != tail)
    {
        if (p->no == x)
        {
            cout << "编号：" << p->no << " 姓名：" << p->name << " 部门：" << p->depname << " 职称：" << p->title << " 工资：" << p->salary << endl;
            break;
        }
        else
            p = p->next;
    }
}
void stuffs::locate_name(string nam)
{
    stuff *p = head->next;
    while (p == tail)
    {
        cout << "无职工信息，请添加职工信息再试" << endl;
        return;
    }
    while (p != tail)
    {
        if (p->name == nam)
        {
            cout << "编号：" << p->no << " 姓名：" << p->name << " 部门：" << p->depname << " 职称：" << p->title << " 工资：" << p->salary << endl;
        }
        p = p->next;
    }
}
void stuffs::locate_depname(string dep)
{
    stuff *p = head->next;
    while (p == tail)
    {
        cout << "无职工信息，请添加职工信息再试" << endl;
        return;
    }
    while (p != tail)
    {
        if (p->depname == dep)
        {
            cout << "编号：" << p->no << " 姓名：" << p->name << " 部门：" << p->depname << " 职称：" << p->title << " 工资：" << p->salary << endl;
        }
        p = p->next;
    }
}
void stuffs::locate_title(string tit)
{
    stuff *p = head->next;
    while (p == tail)
    {
        cout << "无职工信息，请添加职工信息再试" << endl;
        return;
    }
    while (p != tail)
    {
        if (p->title == tit)
        {
            cout << "编号：" << p->no << " 姓名：" << p->name << " 部门：" << p->depname << " 职称：" << p->title << " 工资：" << p->salary << endl;
        }
        p = p->next;
    }
}
void stuffs::delete_no(int x)
{
    stuff *p = head->next;
    while (p == tail)
    {
        cout << "无职工信息，请添加职工信息再试" << endl;
        return;
    }
    while (p != tail)
    {
        if (p->no == x)
        {
            stuff *s = p;
            s->pre->next = s->next;
            s->next->pre = s->pre;
            delete s;
            count--;
            p = head;
        }
        p = p->next;
    }
}
void stuffs::delete_depname(string dep)
{
    stuff *p = head->next;
    while (p == tail)
    {
        cout << "无职工信息，请添加职工信息再试" << endl;
        return;
    }
    while (p != tail)
    {
        if (p->depname == dep)
        {
            stuff *s = p;
            s->pre->next = s->next;
            s->next->pre = s->pre;
            delete s;
            count--;
            p = head;
        }
        p = p->next;
    }
}
void stuffs::delete_title(string tit)
{
    stuff *p = head->next;
    while (p == tail)
    {
        cout << "无职工信息，请添加职工信息再试" << endl;
        return;
    }
    while (p != tail)
    {
        if (p->title == tit)
        {
            stuff *s = p;
            s->pre->next = s->next;
            s->next->pre = s->pre;
            delete s;
            count--;
            p = head;
        }
        p = p->next;
    }
}
void stuffs::salary_depname()
{
    stuff *p = head->next;
    while (p == tail)
    {
        cout << "无职工信息，请添加职工信息再试" << endl;
        return;
    }
    if (p != tail)
    {
        int num = 1;
        string nam[count];
        int salaries[count] = {0};
        nam[0] = p->depname;
        p=p->next;
        while (p != tail)
        {
            for (int j = 1; j < count; j++)
            {
                for (int i = 0; i < num; i++)
                {   
                    int countnum=0;   
                    if(p->depname!=nam[i])             
                    {
                        countnum++;
                    }
                    if(countnum==num)
                    {
                        num++;
                        nam[i+1]=p->depname;
                        continue;
                    }
                }
                p=p->next;
            }
        }
        for (int i = 0; i < num; i++)
        {
            p = head->next;
            while (p != tail)
            {
                if (p->depname == nam[i])
                {
                    salaries[i] += p->salary;
                }
                p = p->next;
            }
        }
        for (int i = 0; i < num ; i++)
        {
            cout << nam[i] << "的职工工资总额为：" << salaries[i] << endl;
        }
    }
}
void stuffs::salary_title()
{
    stuff *p = head->next;
    while (p == tail)
    {
        cout << "无职工信息，请添加职工信息再试" << endl;
        return;
    }
    if (p != tail)
    {
        int titnum = 1;
        string tits[count];
        int salariestit[count] = {0};
        tits[0] = p->title;
        p=p->next;
        while (p != tail)
        {
            for (int j = 1; j < count; j++)
            {
                for (int i = 0; i < titnum; i++)
                {   
                    int countnum=0;   
                    if(p->title!=tits[i])             
                    {
                        countnum++;
                    }
                    if(countnum==titnum)
                    {
                        titnum++;
                        tits[i+1]=p->title;
                        continue;
                    }
                }
                p=p->next;
            }
        }
        for (int i = 0; i < titnum; i++)
        {
            p = head->next;
            while (p != tail)
            {
                if (p->title == tits[i])
                {
                    salariestit[i] += p->salary;
                }
                p = p->next;
            }
        }
        for (int i = 0; i < titnum ; i++)
        {
            cout << tits[i] << "的职工工资总额为：" << salariestit[i] << endl;
        }
    }
}
void stuffs::adjust_no(int x, int s)
{
    stuff *p = head->next;
    while (p == tail)
    {
        cout << "无职工信息，请添加职工信息再试" << endl;
        return;
    }
    while (p != tail)
    {
        if (p->no == x)
        {
            p->salary = s;
        }
        p = p->next;
    }
}
void stuffs::adjust_depname(string dep, int s)
{
    stuff *p = head->next;
    while (p == tail)
    {
        cout << "无职工信息，请添加职工信息再试" << endl;
        return;
    }
    while (p != tail)
    {
        if (p->depname == dep)
        {
            p->salary = s;
        }
        p = p->next;
    }
}
void stuffs::adjust_title(string tit, int s)
{
    stuff *p = head->next;
    while (p == tail)
    {
        cout << "无职工信息，请添加职工信息再试" << endl;
        return;
    }
    while (p != tail)
    {
        if (p->title == tit)
        {
            p->salary=s;
        }
        p = p->next;
    }
}
void Center_Text(char ShellText[80]) //将函数参数(字符串)在屏幕上居中显示
{
    int length;
    int center;
    length = strlen(ShellText);   //取得欲显示字符串的大小
    center = (80 - length) / 2;   //整个屏幕的列数为80,取得字符串在该行的其始位置
    for (; center != 0; center--) //在字符串前输出空格
    {
        cout << " ";
    }
    cout << ShellText;
}
int main()
{

    stuff s;
    stuffs st;
    for (;;)
    {
    A:
        system("cls");
        Center_Text("欢迎来到人事信息管理系统\n");
        Center_Text("******菜单******\n");
        Center_Text("*1:增加职工信息*\n");
        Center_Text("*2:删除职工信息*\n");
        Center_Text("*3:查找职工信息*\n");
        Center_Text("*4:工 资 调 整*\n");
        Center_Text("*5:统 计 分 析*\n");
        Center_Text("*0:退   出*\n");
        Center_Text("****************\n");
        int n, n1, n2, n3, n4, n5, batch, x1, x2, salary1, salary2, salary3;
        string dep1, name1, dep2, dep3, title1, title2, title3;
        cout << "请选择菜单里对应功能的一个整数:\n";
        cin >> n;
        if (n < 0 || n > 5)
        {
            cerr << "输入错误，请重新输入：" << endl;
            goto A;
        }
        switch (n)
        {
        case 1:
            Center_Text("*1:增加一个职工信息*\n");
            Center_Text("*2:批量增加职工信息*\n");
            Center_Text("*0:返回主菜单*\n");
        B:
            cout << "请输入子菜单里对应功能的一个整数" << endl;
            cin >> n1;
            if (n1 < 0 || n1 > 2)
            {
                cerr << "输入错误，请重新输入：" << endl;
                system("pause");
                goto B;
            }
            switch (n1)
            {
            case 1:
                st.create();
                cout << "添加成功" << endl;
                system("pause");
                goto B;
            case 2:
                cout << "请输入批量增加职工的数量：";
                cin >> batch;
                st.creates(batch);
                cout << "添加成功" << endl;
                system("pause");
                goto B;
            case 0:
                goto A;
            default:
                goto B;
            }
            break;
        case 2:
            Center_Text("*1:根据编号删除职工信息*\n");
            Center_Text("*2:根据部门批量删除职工信息*\n");
            Center_Text("*3:根据职称批量删除职工信息*\n");
            Center_Text("*0:返回主菜单*\n");
        C:
            cout << "请输入子菜单里对应功能的一个整数" << endl;
            cin >> n2;
            if (n2 < 0 || n2 > 3)
            {
                cerr << "输入错误，请重新输入：" << endl;
                system("pause");
                goto C;
            }
            switch (n2)
            {
            case 1:
                cout << "请输入需要删除职工的编号：";
                cin >> x1;
                st.delete_no(x1);
                cout << "删除成功" << endl;
                system("pause");
                goto C;
            case 2:
                cout << "请输入需要删除职工的部门：";
                cin >> dep1;
                st.delete_depname(dep1);
                cout << "删除成功" << endl;
                system("pause");
                goto C;
            case 3:
                cout << "请输入需要删除职工的职称：";
                cin >> title1;
                st.delete_title(title1);
                cout << "删除成功" << endl;
                system("pause");
                goto C;
            case 0:
                goto A;
            default:
                goto C;
            }
            break;
        case 3:
            Center_Text("*1:根据编号查找职工信息*\n");
            Center_Text("*2:根据姓名查找职工信息*\n");
            Center_Text("*3:根据部门查找职工信息*\n");
            Center_Text("*4:根据职称查找职工信息*\n");
            Center_Text("*0:返回主菜单*\n");
        D:
            cout << "请输入子菜单里对应功能的一个整数" << endl;
            cin >> n3;
            if (n3 < 0 || n3 > 4)
            {
                cerr << "输入错误，请重新输入：" << endl;
                system("pause");
                goto D;
            }
            switch (n3)
            {

            case 1:
                cout << "请输入所需查找的职工编号：";
                cin >> x2;
                st.locate_no(x2);
                system("pause");
                goto D;
            case 2:
                cout << "请输入所需查找的职工姓名：";
                cin >> name1;
                st.locate_name(name1);
                system("pause");
                goto D;
            case 3:
                cout << "请输入所需查找的职工部门：";
                cin >> dep2;
                st.locate_depname(dep2);
                system("pause");
                goto D;
            case 4:
                cout << "请输入所需查找的职工职称：";
                cin >> title2;
                st.locate_title(title2);
                system("pause");
                goto D;
            case 0:
                goto A;
            default:
                goto D;
            }
            break;
        case 4:
            Center_Text("*1:按编号调整工资*\n");
            Center_Text("*2:按部门调整工资*\n");
            Center_Text("*3:按职称调整工资*\n");
            Center_Text("*0:返回主菜单*\n");
        E:
            cout << "请输入子菜单里对应功能的一个整数" << endl;
            cin >> n4;
            if (n4 < 0 || n4 > 3)
            {
                cerr << "输入错误，请重新输入：" << endl;
                system("pause");
                goto E;
            }
            switch (n4)
            {
            case 1:
                cout << "请输入需要调整的职工编号及其调整后的工资：";
                cin >> x2 >> salary1;
                st.adjust_no(x2, salary1);
                cout << "调整成功" << endl;
                system("pause");
                goto E;
            case 2:
                cout << "请输入需要调整的职工部门及其调整后的工资：";
                cin >> dep3 >> salary2;
                st.adjust_depname(dep3, salary2);
                cout << "调整成功" << endl;
                system("pause");
                goto E;
            case 3:
                cout << "请输入需要调整的职工职称及其调整后的工资：";
                cin >> title3 >> salary3;
                st.adjust_title(title3, salary3);
                cout << "调整成功" << endl;
                system("pause");
                goto E;
            case 0:
                goto A;
            default:
                goto E;
            }
            break;
        case 5:
            Center_Text("*1:显示所有职工信息*\n");
            Center_Text("*2:按部门显示各部门职工工资总额*\n");
            Center_Text("*3:按职称显示各职称职工工资总额*\n");
            Center_Text("*0:返回主菜单*\n");
        F:
            cout << "请输入子菜单里对应功能的一个整数" << endl;
            cin >> n5;
            if (n5 < 0 || n5 > 3)
            {
                cerr << "输入错误，请重新输入：" << endl;
                system("pause");
                goto F;
            }
            switch (n5)
            {
            case 1:
                cout << "所有职工信息如下：" << endl;
                st.print();
                system("pause");
                goto F;
            case 2:
                cout << "各部门职工的工资总额如下：" << endl;
                st.salary_depname();
                system("pause");
                goto F;
            case 3:
                cout << "各职称职工的工资总额如下：" << endl;
                st.salary_title();
                system("pause");
                goto F;
            case 0:
                goto A;
            default:
                goto F;
            }
        case 0:
            exit(0); //执行退出程序
        default:
            cerr << "输入错误，请重新输入：" << endl;
            system("pause");
            goto A;
        }
        system("cls"); //清屏
    }
    cout << endl
         << endl
         << endl;
    return 0;
}