#include<iostream>
#include<windows.h>
using namespace std;
//���ڴ�����
LRESULT WINAPI WNDproc(HWND hWnd,UINT msgID,WPARAM wParam,LPARAM lParam)
{
    switch(msgID)
    {
        case WM_DESTROY:
        PostQuitMessage(0);//����ʹGetMessage��������0
        break;
    }
    return DefWindowProc(hWnd,msgID,wParam,lParam);
}
//��ں���
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR ipCmdLine,int nCmdShow)
{
    //��Ϣ����ʾ����
    MessageBox(NULL,TEXT("test"),TEXT("HelloMsg"),0);
    //ע�ᴰ����
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
    RegisterClass(&wnd);//��ֵд��
    //���ڴ洴������
    HWND hWnd=CreateWindow(TEXT("Test"),TEXT("hello-window"),WS_OVERLAPPEDWINDOW,100,100,500,500,NULL,NULL,hInstance,NULL);
    //��ʾ����
    ShowWindow(hWnd,SW_SHOW);
    UpdateWindow(hWnd);
    //��Ϣѭ��
    MSG msg={0};
    while(GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);//�ɷ������ڴ�����
    }
    return 0;
}