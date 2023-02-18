#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int a[12] = {2, 5, 16, -10, -3, 4, 7, 8, 11};
    int b[3][4]; // 二维数组
    int k = 0;   // 控制数组a中数值位置
    for (int i = 0; i < 3; i++)
    { // 控制行
        for (int j = 0; j < 4; j++)
        {                   // 控制列
            b[i][j] = a[k]; // 每行4个元素，赋完为止
            k++;
        }
    }
    // 输出查看
    for (int i = 0; i < 3; i++)
    { // 控制行
        for (int j = 0; j < 4; j++)
        { // 控制列
            printf("%3d  ", b[i][j]);
        }
        printf("\n"); // 换行
    }
    cout << b[1][2] << endl;
}