#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
//存储最短路径值
int ShortestPathvalue[31][31] = {0};
//存储具体路径
int ShortestPathmatrix[31][31] = {0};
//地点信息
char _mapName[31][50] = {
    "南门", "实验楼D", "行政楼", "综合楼3", "实验楼C", "教学楼A", "篮球场1", "实验楼B", "紫金湖", "教学楼B", "羽毛球场", "A区宿舍", "实验楼A", "教学楼C", "体育馆", "图书馆", "西门", "大学科技园", "综合楼1", "排球场", "综合楼2", "篮球场2", "三食堂", "D区宿舍", "运动场", "篮球场3", "B区宿舍", "网球场", "C区宿舍", "综合楼4", "二食堂"};
//距离信息,_distance[0][1]=50;代表从下标为0到下表为1地点距离为50
int _distance[31][31] = {0};
//边表结点
typedef struct EdgeNode
{
    //顶点对应的下标
    int adjvex;
    //权值
    int weight;
    //指向下一个邻接点
    struct EdgeNode *next;
} edgeNode;

//顶点表结点
typedef struct VertexNode
{
    //顶点数据
    char data[50];
    //边表头指针
    edgeNode *firstedge;
} VertexNode, AdjList[100];

//集合
typedef struct
{
    AdjList adjList;
    //顶点数和边数
    int numVertexes, numEdges;
} GraphAdjList;

class AdjacencyList
{
public:
    void ShowALGraph(GraphAdjList *G);

    //初始化地图
    void InitMap(GraphAdjList *G);

    //创建地图
    void CreateALGraph(GraphAdjList *G);

    //查询顶点信息
    void SearchGraph(GraphAdjList *G, int x);

    //计算各个顶点之间最短路径
    void ShortestPath_Floyd(GraphAdjList *G, int P[31][31], int D[31][31]);

    //输出路径长度和具体路径
    void ShowShortestResult(int originPos, int endPos);
};

//创建地图
void AdjacencyList::CreateALGraph(GraphAdjList *G)
{
    edgeNode *e;
    //读入顶点信息，建立顶点表
    for (int i = 0; i < G->numVertexes; i++)
    {
        //读入顶点信息
        strcpy(G->adjList[i].data, _mapName[i]);
        //将边表置为空表
        G->adjList[i].firstedge = NULL;
    }
    //建立边表（头插法）
    for (int i = 0; i < G->numVertexes; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp;
            if (_distance[i][j] != 0 || _distance[j][i] != 0)
            {
                if (_distance[i][j] != 0)
                {
                    temp = _distance[i][j];
                    _distance[j][i] = _distance[i][j];
                }
                else
                {
                    temp = _distance[j][i];
                    _distance[i][j] = _distance[j][i];
                }
                e = new EdgeNode;
                e->adjvex = j;
                e->next = G->adjList[i].firstedge;
                e->weight = temp;
                G->adjList[i].firstedge = e;

                e = new EdgeNode;

                e->adjvex = i;
                e->next = G->adjList[j].firstedge;
                e->weight = temp;
                G->adjList[j].firstedge = e;
            }
        }
    }
}

void AdjacencyList::ShowALGraph(GraphAdjList *G)
{
    cout << "以下为地点列表" << endl;
    for (int i = 0; i < G->numVertexes; i++)
    {
        cout << "地点" << i << ":" << G->adjList[i].data << endl;
    }
}

//初始化地图基本数据
void AdjacencyList::InitMap(GraphAdjList *G)
{
    //输入顶点数和边数
    G->numVertexes = 30;
    G->numEdges = 41;
    _distance[0][1] = 25;
    _distance[0][2] = 50;
    _distance[0][8] = 70;

    _distance[1][4] = 20;
    _distance[1][2] = 60;

    _distance[2][3] = 30;
    _distance[2][5] = 20;

    _distance[3][6] = 25;
    _distance[3][11] = 80;

    _distance[4][7] = 20;

    _distance[5][9] = 20;

    _distance[6][10] = 20;

    _distance[7][12] = 20;

    _distance[8][15] = 30;

    _distance[9][13] = 20;

    _distance[10][14] = 25;

    _distance[11][18] = 30;

    _distance[12][16] = 50;
    _distance[12][17] = 40;

    _distance[13][15] = 40;
    _distance[13][14] = 30;
    _distance[13][24] = 180;

    _distance[14][19] = 40;

    _distance[15][17] = 40;

    _distance[16][17] = 30;
    _distance[16][23] = 60;

    _distance[17][24] = 70;

    _distance[18][20] = 20;

    _distance[19][21] = 15;

    _distance[20][22] = 20;

    _distance[21][25] = 15;

    _distance[22][26] = 40;

    _distance[23][24] = 50;
    _distance[23][28] = 70;

    _distance[24][25] = 40;
    _distance[24][28] = 60;

    _distance[25][27] = 30;

    _distance[26][29] = 60;

    _distance[27][29] = 30;

    _distance[28][30] = 50;

    _distance[29][30] = 30;
}

void AdjacencyList::SearchGraph(GraphAdjList *G, int x)
{
    cout << G->adjList[x].data << "相邻地点序号为";
    edgeNode *p = new edgeNode;
    p = G->adjList[x].firstedge;
    while (p)
    {
        cout << p->adjvex << " 距离为" << p->weight << " 下一个相邻地点序号为";
        p = p->next;
    }
    cout<<"空"<<endl;
}
void AdjacencyList::ShortestPath_Floyd(GraphAdjList *G, int P[31][31], int D[31][31])
{
    //初始化D与P
    for (int v = 0; v < G->numVertexes; ++v)
    {
        for (int w = 0; w < G->numVertexes; ++w)
        {
            if (_distance[v][w] == 0 && v != w)
            {
                _distance[v][w] = NULL;
            }
            D[v][w] = _distance[v][w];
            P[v][w] = w;
        }
    }
    for (int k = 0; k < G->numVertexes; ++k)
    {
        for (int v = 0; v < G->numVertexes; ++v)
        {
            for (int w = 0; w < G->numVertexes; ++w)
            {
                if (D[v][w] > D[v][k] + D[k][w])
                {
                    D[v][w] = D[v][k] + D[k][w];
                    P[v][w] = P[v][k];
                }
            }
        }
    }
}

void AdjacencyList::ShowShortestResult(int originPos, int endPos)
{
    int temp;
    cout << "地点" << _mapName[originPos] << "到地点" << _mapName[endPos] << "最短距离为" << ShortestPathvalue[originPos][endPos] << endl;
    temp = ShortestPathmatrix[originPos][endPos];
    cout << "具体路径为" << _mapName[originPos] << "——>";
    while (temp != endPos)
    {
        cout << _mapName[temp] << "——>";
        temp = ShortestPathmatrix[temp][endPos];
    }
    cout << _mapName[endPos] << endl;
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

    for (;;)
    {
    A:
        system("cls");
        Center_Text("欢迎来到紫金学院校园导航系统\n");
        Center_Text("******菜单******\n");
        Center_Text("*1:查询景点信息*\n");
        Center_Text("*2:问 路 查 询*\n");
        Center_Text("*0:退   出*\n");
        Center_Text("****************\n");
        int n;
        AdjacencyList adjacencyList;
        int originPos, endPos, serachPos;
        GraphAdjList *GA = new GraphAdjList;
        adjacencyList.InitMap(GA);
        adjacencyList.CreateALGraph(GA);
        cout << "请选择菜单里对应功能的一个整数:\n";
        cin >> n;
        if (n < 0 || n > 2)
        {
            cerr << "输入错误，请重新输入" << endl;
            goto A;
        }
        switch (n)
        {
        case 1:
            system("cls");
            adjacencyList.ShowALGraph(GA);
            cout << "请输入所需查询的地点序号";
            cin >> serachPos;
            adjacencyList.SearchGraph(GA, serachPos);
            system("pause");
            goto A;
        case 2:
            system("cls");
            adjacencyList.ShowALGraph(GA);
            cout << "请输入所需查询的路径起始点和终点的序号";
            cin >> originPos >> endPos;
            adjacencyList.ShortestPath_Floyd(GA, ShortestPathmatrix, ShortestPathvalue);
            adjacencyList.ShowShortestResult(originPos, endPos);
            system("pause");
            goto A;
        case 0:
            exit(0); //执行退出程序
        default:
            system("cls");
            cerr << "输入错误，请重新输入" << endl;
            system("pause");
            goto A;
        }
        system("cls"); //清屏
    }
    cout << endl
         << endl
         << endl;
    return 0;
    system("pause");
    return 0;
}