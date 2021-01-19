#ifndef QI_WINDOW_H
#define QI_WINDOW_H
#include	<Windows.h>
namespace QiUi
{
    LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
    class QiWindow
    {
    public:
        QiWindow();
        ~QiWindow();

        void Create()
        {
            wndclass_.cbClsExtra = 0;
            wndclass_.cbWndExtra = 0;
            wndclass_.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
            wndclass_.hCursor = LoadCursor(NULL, IDC_ARROW);
            wndclass_.hIcon = LoadIcon(NULL, IDI_APPLICATION);
            wndclass_.hInstance = NULL;
            wndclass_.lpfnWndProc = WndProc;
            wndclass_.lpszClassName = TEXT("MyAapp");
            wndclass_.lpszMenuName = TEXT("My Application");
            wndclass_.style = CS_BYTEALIGNWINDOW;

            if (!RegisterClass(&wndclass_))
            {
                MessageBox(NULL, TEXT("ERROR"), TEXT("System tip"), MB_CANCELTRYCONTINUE);
                return;
            }

            handle_ = CreateWindow(
                wndclass_.lpszClassName,
                wndclass_.lpszMenuName,
                WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                400,
                400,
                NULL,
                NULL,
                wndclass_.hInstance, // ��������ʵ���ľ������ʵ�������˴��ڹ��̡�һ��ֱ�Ӹ���WinMain()��hInstance����ֵ���ɡ�
                NULL);

            
        }

        void    Show()
        {
            MSG msg;
            ShowWindow(handle_, 9);
            UpdateWindow(handle_);

            while (GetMessage(&msg, NULL, 0, 0))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

        HWND GetHandle() { return handle_; }

    protected:
        WNDCLASS  wndclass_;
        HWND handle_ = NULL; // ���ھ��
    };

    QiWindow::QiWindow() : wndclass_(WNDCLASS())
    {
    }

    QiWindow::~QiWindow()
    {
    }

    LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
         switch (message) //���ݲ�ͬ����Ϣ���ͽ��в�ͬ�Ĵ��� 
         {
         case WM_COMMAND: // ���Բ˵�����ݼ��򹤾�����ť����Ϣ
         {
             break;
         }
         case WM_PAINT: //���ǿͻ����ػ���Ϣ  
         {
             PAINTSTRUCT ps;
             HDC hdc = BeginPaint(hwnd, &ps);//���ô��ڻ��ƺ���
             // �ڴ˴����ʹ�� hdc ���κλ�ͼ����...
             EndPaint(hwnd, &ps); //�������ô��ڻ��ƺ���
         }
         break;
         case WM_DESTROY://���Ǵ��ڴݻ���Ϣ
             PostQuitMessage(0);//GetMessage�����⵽��ϢWM_QUIT���˳���,��ô�����Ƿ���WM_QUIT��Ϣ
             break;
         default:
             return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
    }
}
#endif // !QI_WINDOW_H

