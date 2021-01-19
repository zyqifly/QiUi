#ifndef QI_WINDOW_H
#define QI_WINDOW_H
#include	<Windows.h>
#include    "QiWidgetBase.h"
#include    "QiWidgetGroup.h"
#include    "QiButton.h"
namespace QiUi
{
    LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
    class QiWindow : public QiWidgetBase, public QiWidgetGroup
    {
    public:
        QiWindow();
        ~QiWindow();

        virtual	bool	Create(QiWidgetBase& parentWidget)
        {
            wndclass_.cbClsExtra = 0;
            wndclass_.cbWndExtra = 0;
            wndclass_.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
            wndclass_.hCursor = LoadCursor(NULL, IDC_ARROW);
            wndclass_.hIcon = LoadIcon(NULL, IDI_APPLICATION);
            wndclass_.hInstance = NULL;
            wndclass_.lpfnWndProc = WndProc;
            wndclass_.lpszClassName = TEXT("MyApp");
            wndclass_.lpszMenuName = TEXT("My Application");
            wndclass_.style = CS_BYTEALIGNWINDOW;

            if (!RegisterClass(&wndclass_))
            {
                MessageBox(NULL, TEXT("ERROR"), TEXT("System tip"), MB_CANCELTRYCONTINUE);
                return true;
            }

            handle_ = CreateWindow(
                wndclass_.lpszClassName,
                wndclass_.lpszMenuName,
                WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                400,
                400,
                parentWidget.GetHandle(),
                NULL,
                wndclass_.hInstance, // ��������ʵ���ľ������ʵ�������˴��ڹ��̡�һ��ֱ�Ӹ���WinMain()��hInstance����ֵ���ɡ�
                NULL);
            SetupUi();
            for (auto widget : container_)
            {
                if (widget != nullptr)
                {
                    widget->Create(*this);
                }
            }

            return  true;
        }

        bool Create()
        {
            wndclass_.cbClsExtra = 0;
            wndclass_.cbWndExtra = 0;
            wndclass_.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
            wndclass_.hCursor = LoadCursor(NULL, IDC_ARROW);
            wndclass_.hIcon = LoadIcon(NULL, IDI_APPLICATION);
            wndclass_.hInstance = NULL;
            wndclass_.lpfnWndProc = WndProc;
            wndclass_.lpszClassName = TEXT("MyApp");
            wndclass_.lpszMenuName = TEXT("My Application");
            wndclass_.style = CS_BYTEALIGNWINDOW;

            if (!RegisterClass(&wndclass_))
            {
                MessageBox(NULL, TEXT("ERROR"), TEXT("System tip"), MB_CANCELTRYCONTINUE);
                return true;
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
            SetupUi();
            for (auto widget : container_)
            {
                if (widget != nullptr)
                {
                    widget->Create(*this);
                }
            }

            return  true;
        }

        virtual	void	SetupUi() override
        {
            button.SetPositon(100, 100, 80, 20);
            Add(button);
            
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

    protected:
        WNDCLASS  wndclass_;

        QiButton button;
    };

    QiWindow::QiWindow() : wndclass_(WNDCLASS())
    {
        info_.type = QiWidgetType::Window;
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

