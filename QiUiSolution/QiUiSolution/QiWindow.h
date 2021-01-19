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
                wndclass_.hInstance, // 包含该类实例的句柄，该实例包含了窗口过程。一般直接赋上WinMain()的hInstance参数值即可。
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
                wndclass_.hInstance, // 包含该类实例的句柄，该实例包含了窗口过程。一般直接赋上WinMain()的hInstance参数值即可。
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
         switch (message) //根据不同的消息类型进行不同的处理 
         {
         case WM_COMMAND: // 来自菜单、快捷键或工具栏按钮的消息
         {
             break;
         }
         case WM_PAINT: //若是客户区重绘消息  
         {
             PAINTSTRUCT ps;
             HDC hdc = BeginPaint(hwnd, &ps);//调用窗口绘制函数
             // 在此处添加使用 hdc 的任何绘图代码...
             EndPaint(hwnd, &ps); //结束调用窗口绘制函数
         }
         break;
         case WM_DESTROY://若是窗口摧毁消息
             PostQuitMessage(0);//GetMessage它会检测到消息WM_QUIT就退出来,那么它就是发送WM_QUIT消息
             break;
         default:
             return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
    }
}
#endif // !QI_WINDOW_H

