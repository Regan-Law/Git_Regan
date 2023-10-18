#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
//�洢���·��ֵ
int ShortestPathvalue[31][31] = {0};
//�洢����·��
int ShortestPathmatrix[31][31] = {0};
//�ص���Ϣ
char _mapName[31][50] = {
    "����", "ʵ��¥D", "����¥", "�ۺ�¥3", "ʵ��¥C", "��ѧ¥A", "����1", "ʵ��¥B", "�Ͻ��", "��ѧ¥B", "��ë��", "A������", "ʵ��¥A", "��ѧ¥C", "������", "ͼ���", "����", "��ѧ�Ƽ�԰", "�ۺ�¥1", "����", "�ۺ�¥2", "����2", "��ʳ��", "D������", "�˶���", "����3", "B������", "����", "C������", "�ۺ�¥4", "��ʳ��"};
//������Ϣ,_distance[0][1]=50;������±�Ϊ0���±�Ϊ1�ص����Ϊ50
int _distance[31][31] = {0};
//�߱���
typedef struct EdgeNode
{
    //�����Ӧ���±�
    int adjvex;
    //Ȩֵ
    int weight;
    //ָ����һ���ڽӵ�
    struct EdgeNode *next;
} edgeNode;

//�������
typedef struct VertexNode
{
    //��������
    char data[50];
    //�߱�ͷָ��
    edgeNode *firstedge;
} VertexNode, AdjList[100];

//����
typedef struct
{
    AdjList adjList;
    //�������ͱ���
    int numVertexes, numEdges;
} GraphAdjList;

class AdjacencyList
{
public:
    void ShowALGraph(GraphAdjList *G);

    //��ʼ����ͼ
    void InitMap(GraphAdjList *G);

    //������ͼ
    void CreateALGraph(GraphAdjList *G);

    //��ѯ������Ϣ
    void SearchGraph(GraphAdjList *G, int x);

    //�����������֮�����·��
    void ShortestPath_Floyd(GraphAdjList *G, int P[31][31], int D[31][31]);

    //���·�����Ⱥ;���·��
    void ShowShortestResult(int originPos, int endPos);
};

//������ͼ
void AdjacencyList::CreateALGraph(GraphAdjList *G)
{
    edgeNode *e;
    //���붥����Ϣ�����������
    for (int i = 0; i < G->numVertexes; i++)
    {
        //���붥����Ϣ
        strcpy(G->adjList[i].data, _mapName[i]);
        //���߱���Ϊ�ձ�
        G->adjList[i].firstedge = NULL;
    }
    //�����߱�ͷ�巨��
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
    cout << "����Ϊ�ص��б�" << endl;
    for (int i = 0; i < G->numVertexes; i++)
    {
        cout << "�ص�" << i << ":" << G->adjList[i].data << endl;
    }
}

//��ʼ����ͼ��������
void AdjacencyList::InitMap(GraphAdjList *G)
{
    //���붥�����ͱ���
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
    cout << G->adjList[x].data << "���ڵص����Ϊ";
    edgeNode *p = new edgeNode;
    p = G->adjList[x].firstedge;
    while (p)
    {
        cout << p->adjvex << " ����Ϊ" << p->weight << " ��һ�����ڵص����Ϊ";
        p = p->next;
    }
    cout<<"��"<<endl;
}
void AdjacencyList::ShortestPath_Floyd(GraphAdjList *G, int P[31][31], int D[31][31])
{
    //��ʼ��D��P
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
    cout << "�ص�" << _mapName[originPos] << "���ص�" << _mapName[endPos] << "��̾���Ϊ" << ShortestPathvalue[originPos][endPos] << endl;
    temp = ShortestPathmatrix[originPos][endPos];
    cout << "����·��Ϊ" << _mapName[originPos] << "����>";
    while (temp != endPos)
    {
        cout << _mapName[temp] << "����>";
        temp = ShortestPathmatrix[temp][endPos];
    }
    cout << _mapName[endPos] << endl;
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

    for (;;)
    {
    A:
        system("cls");
        Center_Text("��ӭ�����Ͻ�ѧԺУ԰����ϵͳ\n");
        Center_Text("******�˵�******\n");
        Center_Text("*1:��ѯ������Ϣ*\n");
        Center_Text("*2:�� · �� ѯ*\n");
        Center_Text("*0:��   ��*\n");
        Center_Text("****************\n");
        int n;
        AdjacencyList adjacencyList;
        int originPos, endPos, serachPos;
        GraphAdjList *GA = new GraphAdjList;
        adjacencyList.InitMap(GA);
        adjacencyList.CreateALGraph(GA);
        cout << "��ѡ��˵����Ӧ���ܵ�һ������:\n";
        cin >> n;
        if (n < 0 || n > 2)
        {
            cerr << "�����������������" << endl;
            goto A;
        }
        switch (n)
        {
        case 1:
            system("cls");
            adjacencyList.ShowALGraph(GA);
            cout << "�����������ѯ�ĵص����";
            cin >> serachPos;
            adjacencyList.SearchGraph(GA, serachPos);
            system("pause");
            goto A;
        case 2:
            system("cls");
            adjacencyList.ShowALGraph(GA);
            cout << "�����������ѯ��·����ʼ����յ�����";
            cin >> originPos >> endPos;
            adjacencyList.ShortestPath_Floyd(GA, ShortestPathmatrix, ShortestPathvalue);
            adjacencyList.ShowShortestResult(originPos, endPos);
            system("pause");
            goto A;
        case 0:
            exit(0); //ִ���˳�����
        default:
            system("cls");
            cerr << "�����������������" << endl;
            system("pause");
            goto A;
        }
        system("cls"); //����
    }
    cout << endl
         << endl
         << endl;
    return 0;
    system("pause");
    return 0;
}