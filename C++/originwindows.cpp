#include<iostream>
#include<windows.h>
using namespace std;
//窗口处理函数
LRESULT WINAPI WNDproc(HWND hWnd,UINT msgID,WPARAM wParam,LPARAM lParam)
{
    switch(msgID)
    {
        case WM_DESTROY:
        PostQuitMessage(0);//可以使GetMessage函数返回0
        break;
    }
    return DefWindowProc(hWnd,msgID,wParam,lParam);
}
//入口函数
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR ipCmdLine,int nCmdShow)
{
    //消息框，提示窗口
    MessageBox(NULL,TEXT("test"),TEXT("HelloMsg"),0);
    //注册窗口类
    WNDCLASS wnd={0};
    wnd.cbClsExtra=0;
    wnd.cbWndExtra=0;
    wnd.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
    wnd.hCursor=NULL;
    wnd.hIcon=NULL;
    wnd.hInstance=hInstance;
    wnd.lpfnWndProc=WNDproc;
    wnd.lpszClassName=TEXT("Test");
    wnd.lpszMenuName=NULL;
    wnd.style=CS_HREDRAW|CS_VREDRAW;
    RegisterClass(&wnd);//赋值写入
    //在内存创建窗口
    HWND hWnd=CreateWindow(TEXT("Test"),TEXT("hello-window"),WS_OVERLAPPEDWINDOW,100,100,500,500,NULL,NULL,hInstance,NULL);
    //显示窗口
    ShowWindow(hWnd,SW_SHOW);
    UpdateWindow(hWnd);
    //消息循环
    MSG msg={0};
    while(GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);//派发给窗口处理函数
    }
    return 0;
}