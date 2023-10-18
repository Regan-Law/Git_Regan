#include <iostream>
#include <string.h>
using namespace std;
typedef struct stuff
{
    int no;
    string name;
    string depname;
    string title;
    int salary;
    stuff *next;
} stuff;
class stuffs
{
private:
    stuff *head;

public:
    int count=0;
    stuffs();
    ~stuffs(); //����һ��ְ����Ϣ
   
    void create(); //��������ְ����Ϣ
   
    void creates(int n); //��ʾ����ְ����Ϣ
   
    void print(); //���ݱ��ɾ��ְ����Ϣ
   
    void delete_no(int x);//���ݲ�������ɾ��ְ����Ϣ
    
    void delete_depname(string dep); //����ְ������ɾ��ְ����Ϣ
   
    void delete_title(string tit); //���ݱ�Ų���ְ����Ϣ
   
    void locate_no(int x); //������������ְ����Ϣ
   
    void locate_name(string nam); //���ݲ��Ų���ְ����Ϣ
   
    void locate_depname(string dep);//����ְ�Ʋ���ְ����Ϣ
    
    void locate_title(string tit);//��������ʾ������ְ�������ܶ�
    
    void salary_depname();//��ְ����ʾ������ְ�������ܶ�
    
    void salary_title();//����ŵ�������
    
    void adjust_no(int x, int s);//�����ŵ�������
    
    void adjust_depname(string dep, int s); //��ְ�Ƶ�������
   
    void adjust_title(string tit, int s); //����ͷָ��
   
    stuff *gethead() { return head; }
    void reverse();
    void DeleteMax();
};
stuffs::stuffs()
{
    head = new stuff;
    head->next = NULL;
}

void stuffs::create()
{
    stuff *p;
    p = new stuff;
    cout << "������������ӵ�ְ����Ϣ" << endl;
    cout << "��ţ�";
    cin >> p->no;
    cout << "������";
    cin >> p->name;
    cout << "���ţ�";
    cin >> p->depname;
    cout << "ְ�ƣ�";
    cin >> p->title;
    cout << "���ʣ�";
    cin >> p->salary;
    p->next = head->next;
    head->next = p;
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
    head = NULL;
}
void stuffs::creates(int n)
{
    stuff *p;
    cout << "����������������ӵ�ְ����Ϣ" << endl;
    for (int i = 0; i < n; i++)
    {
        p = new stuff;
        cout << "��ţ�";
        cin >> p->no;
        cout << "������";
        cin >> p->name;
        cout << "���ţ�";
        cin >> p->depname;
        cout << "ְ�ƣ�";
        cin >> p->title;
        cout << "���ʣ�";
        cin >> p->salary;
        p->next = head->next;
        head->next = p;
        p = p->next;
        count++;
    }
}
void stuffs::print()
{
    stuff *p = head->next;
    while (!p)
    {
        cout << "��ְ����Ϣ�������ְ����Ϣ����" << endl;
        return;
    }
    while (p)
    {
        cout << "��ţ�" << p->no << " ������" << p->name << " ���ţ�" << p->depname << " ְ�ƣ�" << p->title << " ���ʣ�" << p->salary << endl;
        p = p->next;
    }
    cout << endl;
}
void stuffs::locate_no(int x)
{
    stuff *p = head->next;
    while (!p)
    {
        cout << "��ְ����Ϣ�������ְ����Ϣ����" << endl;
        return;
    }
    while (p)
    {
        if (p->no == x)
        {
            cout << "��ţ�" << p->no << " ������" << p->name << " ���ţ�" << p->depname << " ְ�ƣ�" << p->title << " ���ʣ�" << p->salary << endl;
            break;
        }
        else
            p = p->next;
    }
}
void stuffs::locate_name(string nam)
{
    stuff *p = head->next;
    while (!p)
    {
        cout << "��ְ����Ϣ�������ְ����Ϣ����" << endl;
        return;
    }
    int namnum = 0;
    while (p)
    {

        while (p)
        {
            for (int i = 0; i < count; i++)
            {
                if (p->name == nam)
                {
                    namnum++;
                }
                p = p->next;
            }
        }
    }
    p = head->next;
    while (p)
    {
        for (; namnum > 0;)
        {
            if (p->name == nam)
            {
                cout << "��ţ�" << p->no << " ������" << p->name << " ���ţ�" << p->depname << " ְ�ƣ�" << p->title << " ���ʣ�" << p->salary << endl;
                namnum--;
            }
        }
        p = p->next;
    }
}
void stuffs::locate_depname(string dep)
{
    stuff *p = head->next;
    while (!p)
    {
        cout << "��ְ����Ϣ�������ְ����Ϣ����" << endl;
        return;
    }
    int namnum = 0;
    while (p)
    {

        while (p)
        {
            for (int i = 0; i < count; i++)
            {
                if (p->depname == dep)
                {
                    namnum++;
                }
                p = p->next;
            }
        }
    }
    p = head->next;
    while (p)
    {
        for (; namnum > 0;)
        {
            if (p->depname == dep)
            {
                cout << "��ţ�" << p->no << " ������" << p->name << " ���ţ�" << p->depname << " ְ�ƣ�" << p->title << " ���ʣ�" << p->salary << endl;
                namnum--;
            }
        }
        p = p->next;
    }
}
void stuffs::locate_title(string tit)
{
    stuff *p = head->next;
    while (!p)
    {
        cout << "��ְ����Ϣ�������ְ����Ϣ����" << endl;
        return;
    }
    int namnum = 0;
    while (p)
    {

        while (p)
        {
            for (int i = 0; i < count; i++)
            {
                if (p->title == tit)
                {
                    namnum++;
                }
                p = p->next;
            }
        }
    }
    p = head->next;
    while (p)
    {
        for (; namnum > 0;)
        {
            if (p->title == tit)
            {
                cout << "��ţ�" << p->no << " ������" << p->name << " ���ţ�" << p->depname << " ְ�ƣ�" << p->title << " ���ʣ�" << p->salary << endl;
                namnum--;
            }
        }
        p = p->next;
    }
}
void stuffs::delete_no(int x)
{
    stuff *p = head->next;
    while (!p)
    {
        cout << "��ְ����Ϣ�������ְ����Ϣ����" << endl;
        return;
    }
    while (p)
    {
        while (!p->next)
        {
            stuff *s = head->next;
            head->next = s->next;
            delete s;
            count--;
            return;
        }
        while (p->next)
        {
            if (x == count)
            {
                stuff *s = head->next;
                head->next = s->next;
                delete s;
                count--;
            }
            else if (p->no == x + 1 && x != count)
            {
                stuff *s = p->next;
                p->next = s->next;
                delete s;
                count--;
            }
            p = p->next;
        }
    }
}
void stuffs::delete_depname(string dep)
{
    stuff *p = head->next;
    while (!p)
    {
        cout << "��ְ����Ϣ�������ְ����Ϣ����" << endl;
        return;
    }
    int j = 0;
    int delnum = 0;
    int del[delnum];
    while (p)
    {
        if (p->depname == dep)
        {
            delnum++;
            del[j++] = p->no;
        }
        p = p->next;
    }
    p = head->next;
    while (p)
    {
        while (!p->next)
        {
            stuff *s = head->next;
            head->next = s->next;
            delete s;
            count--;
            return;
        }
        while (p->next)
        {
            for (int i = 0; i < delnum; i++)
            {
                if (del[i] == count)
                {
                    stuff *s = head->next;
                    head->next = s->next;
                    delete s;
                    count--;
                }
                else if (p->no == del[i] + 1)
                {
                    stuff *s = p->next;
                    p->next = s->next;
                    delete s;
                    count--;
                }
                else
                    p = p->next;
            }
        }
    }
}
void stuffs::delete_title(string tit)
{
    stuff *p = head->next;
    while (!p)
    {
        cout << "��ְ����Ϣ�������ְ����Ϣ����" << endl;
        return;
    }
    int j = 0;
    int delnum = 0;
    int del[delnum];
    while (p)
    {
        if (p->title == tit)
        {
            delnum++;
            del[j++] = p->no;
        }
        p = p->next;
    }
    p = head->next;
    while (p)
    {
        while (!p->next)
        {
            stuff *s = head->next;
            head->next = s->next;
            delete s;
            count--;
            return;
        }
        while (p->next)
        {
            for (int i = 0; i < delnum; i++)
            {
                if (del[i] == count)
                {
                    stuff *s = head->next;
                    head->next = s->next;
                    delete s;
                    count--;
                }
                else if (p->no == del[i] + 1)
                {
                    stuff *s = p->next;
                    p->next = s->next;
                    delete s;
                    count--;
                }
            }
            p = p->next;
        }
    }
}
void stuffs::salary_depname()
{
    stuff *p = head->next;
    while (!p)
    {
        cout << "��ְ����Ϣ�������ְ����Ϣ����" << endl;
        return;
    }
    while (p)
    {
        int depnum = 1;
        string deps[count];
        int salaries[count] = {0};
        deps[0] = p->depname;
        int j = 0;
        while (p)
        {
            if (p->depname != deps[j])
            {
                depnum++;
                deps[j++] = p->depname;
            }
            p = p->next;
        }
        for (int i = 0; i < depnum; i++)
        {
            p = head->next;
            while (p)
            {
                if (p->depname == deps[i])
                {
                    salaries[i] += p->salary;
                }
                p = p->next;
            }
        }
        for (int i = 0; i < depnum-1; i++)
        {
            cout << deps[i] << "��ְ�������ܶ�Ϊ��" << salaries[i] << endl;
        }
    }
}
void stuffs::salary_title()
{
    stuff *p = head->next;
    while (!p)
    {
        cout << "��ְ����Ϣ�������ְ����Ϣ����" << endl;
        return;
    }
    while (p)
    {
        int titnum = 1;
        string tits[count];
        int salaries[count] = {0};
        tits[0] = p->title;
        int j = 0;
        while (p)
        {
            if (p->title != tits[j])
            {
                titnum++;
                tits[j++] = p->title;
            }
            p = p->next;
        }
        for (int i = 0; i < titnum; i++)
        {
            p = head->next;
            while (p)
            {
                if (p->title == tits[i])
                {
                    salaries[i] += p->salary;
                }
                p = p->next;
            }
        }
        for (int i = 0; i < titnum-1; i++)
        {
            cout << tits[i] << "��ְ�������ܶ�Ϊ��" << salaries[i] << endl;
        }
    }
}
void stuffs::adjust_no(int x, int s)
{
    stuff *p = head->next;
    while (!p)
    {
        cout << "��ְ����Ϣ�������ְ����Ϣ����" << endl;
        return;
    }
    while (p)
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
    while (!p)
    {
        cout << "��ְ����Ϣ�������ְ����Ϣ����" << endl;
        return;
    }
    while (p)
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
    while (!p)
    {
        cout << "��ְ����Ϣ�������ְ����Ϣ����" << endl;
        return;
    }
    while (p)
    {
        if (p->title == tit)
        {
            p->salary = s;
        }
        p = p->next;
    }
}
void Center_Text(char ShellText[80]) //����������(�ַ���)����Ļ�Ͼ�����ʾ
{
    int length;
    int center;
    length = strlen(ShellText);   //ȡ������ʾ�ַ����Ĵ�С
    center = (80 - length) / 2;   //������Ļ������Ϊ80,ȡ���ַ����ڸ��е���ʼλ��
    for (; center != 0; center--) //���ַ���ǰ����ո�
    {
        cout << " ";
    }
    cout << ShellText;
}
int main()
{
   cout <<"��ӭ����������Ϣ����ϵͳ\n"<<endl;
    cout <<"2015301301����¶¶\n"<<endl;
    stuff s;
    stuffs st;
    for (;;)
    {
    A:
       
        cout << "******�˵�******\n"<<endl;
          cout <<"*1:����ְ����Ϣ*\n"<<endl;
         cout <<"*2:ɾ��ְ����Ϣ*\n"<<endl;
         cout <<"*3:����ְ����Ϣ*\n"<<endl;
          cout <<"*4:�� �� �� ��*\n"<<endl;
         cout <<"*5:ͳ �� �� ��*\n"<<endl;
        cout <<"*0:��   ��*\n"<<endl;
         cout <<"****************\n"<<endl;
        int n, n1, n2, n3, n4, n5, batch, x1, x2, salary1, salary2, salary3;
        string dep1, name1, dep2, dep3, title1, title2, title3;
        cout << "��ѡ��˵����Ӧ���ܵ�һ������:\n";
        cin >> n;
        if (n < 0 || n > 5)
        {
            cerr << "����������������룺" << endl;
            goto A;
        }
        switch (n)
        {
        case 1:
             cout <<"*1:����һ��ְ����Ϣ*\n"<< endl;
             cout <<"*2:��������ְ����Ϣ*\n"<< endl;
            cout <<"*0:�������˵�*\n";
        B:
            cout << "�������Ӳ˵����Ӧ���ܵ�һ������" << endl;
            cin >> n1;
            if (n1 < 0 || n1 > 2)
            {
                cerr << "����������������룺" << endl;
                goto B;
            }
            switch (n1)
            {
            case 1:
                st.create();
                cout << "��ӳɹ�" << endl;
              
                goto B;
            case 2:
                cout << "��������������ְ����������";
                cin >> batch;
                st.creates(batch);
                cout << "��ӳɹ�" << endl;
                goto B;
            case 0:
                goto A;
            default:
                goto B;
            }
            break;
        case 2:
           cout << "*1:���ݱ��ɾ��ְ����Ϣ*\n"<<endl;
           cout << "*2:���ݲ�������ɾ��ְ����Ϣ*\n"<<endl;
          cout << "*3:����ְ������ɾ��ְ����Ϣ*\n"<<endl;
           cout << "*0:�������˵�*\n"<<endl;
        C:
            cout << "�������Ӳ˵����Ӧ���ܵ�һ������" << endl;
            cin >> n2;
            if (n2 < 0 || n2 > 3)
            {
                cerr << "����������������룺" << endl;           
                goto C;
            }
            switch (n2)
            {
            case 1:
                cout << "��������Ҫɾ��ְ���ı�ţ�";
                cin >> x1;
                st.delete_no(x1);
                cout << "ɾ���ɹ�" << endl;
                goto C;
            case 2:
                cout << "��������Ҫɾ��ְ���Ĳ��ţ�";
                cin >> dep1;
                st.delete_depname(dep1);
                cout << "ɾ���ɹ�" << endl;
                goto C;
            case 3:
                cout << "��������Ҫɾ��ְ����ְ�ƣ�";
                cin >> title1;
                st.delete_title(title1);
                cout << "ɾ���ɹ�" << endl;
                goto C;
            case 0:
                goto A;
            default:
                goto C;
            }
            break;
        case 3:
          cout << "*1:���ݱ�Ų���ְ����Ϣ*\n"<<endl;
            cout <<"*2:������������ְ����Ϣ*\n"<<endl;
          cout << "*3:���ݲ��Ų���ְ����Ϣ*\n"<<endl;
           cout << "*4:����ְ�Ʋ���ְ����Ϣ*\n"<<endl;
         cout << "*0:�������˵�*\n";
        D:
            cout << "�������Ӳ˵����Ӧ���ܵ�һ������" << endl;
            cin >> n3;
            if (n3 < 0 || n3 > 4)
            {
                cerr << "����������������룺" << endl;
                goto D;
            }
            switch (n3)
            {

            case 1:
                cout << "������������ҵ�ְ����ţ�";
                cin >> x2;
                st.locate_no(x2);
                goto D;
            case 2:
                cout << "������������ҵ�ְ��������";
                cin >> name1;
                st.locate_name(name1);
                goto D;
            case 3:
                cout << "������������ҵ�ְ�����ţ�";
                cin >> dep2;
                st.locate_depname(dep2);
                goto D;
            case 4:
                cout << "������������ҵ�ְ��ְ�ƣ�";
                cin >> title2;
                st.locate_title(title2);
                goto D;
            case 0:
                goto A;
            default:
                goto D;
            }
            break;
        case 4:
        cout << "*1:����ŵ�������*\n"<<endl;
           cout << "*2:�����ŵ�������*\n"<<endl;
            cout << "*3:��ְ�Ƶ�������*\n"<<endl;
            cout << "*0:�������˵�*\n"<<endl;
        E:
            cout << "�������Ӳ˵����Ӧ���ܵ�һ������" << endl;
            cin >> n4;
            if (n4 < 0 || n4 > 3)
            {
                cerr << "����������������룺" << endl;
                goto E;
            }
            switch (n4)
            {
            case 1:
                cout << "��������Ҫ������ְ����ż��������Ĺ��ʣ�";
                cin >> x2 >> salary1;
                st.adjust_no(x2, salary1);
                cout << "�����ɹ�" << endl;
                goto E;
            case 2:
                cout << "��������Ҫ������ְ�����ż��������Ĺ��ʣ�";
                cin >> dep3 >> salary2;
                st.adjust_depname(dep3, salary2);
                cout << "�����ɹ�" << endl;
                goto E;
            case 3:
                cout << "��������Ҫ������ְ��ְ�Ƽ��������Ĺ��ʣ�";
                cin >> title3 >> salary3;
                st.adjust_title(title3, salary3);
                cout << "�����ɹ�" << endl;
                goto E;
            case 0:
                goto A;
            default:
                goto E;
            }
            break;
        case 5:
           cout << "*1:��ʾ����ְ����Ϣ*\n"<<endl;
          cout << "*2:��������ʾ������ְ�������ܶ�*\n"<<endl;
         cout << "*3:��ְ����ʾ��ְ��ְ�������ܶ�*\n"<<endl;
           cout << "*0:�������˵�*\n"<<endl;
        F:
            cout << "�������Ӳ˵����Ӧ���ܵ�һ������" << endl;
            cin >> n5;
            if (n5 < 0 || n5 > 3)
            {
                cerr << "����������������룺" << endl;
                goto F;
            }
            switch (n5)
            {
            case 1:
                cout << "����ְ����Ϣ���£�" << endl;
                st.print();
                goto F;
            case 2:
                cout << "������ְ���Ĺ����ܶ����£�" << endl;
                st.salary_depname();
                goto F;
            case 3:
                cout << "��ְ��ְ���Ĺ����ܶ����£�" << endl;
                st.salary_title();
                goto F;
            case 0:
                goto A;
            default:
                goto F;
            }
        case 0:
            exit(0); //ִ���˳�����
        default:
            cerr<< "����������������룺" << endl;
            goto A;
        }
        //����
    }
    cout << endl
         << endl
         << endl;
    return 0;
}
