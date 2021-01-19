#ifndef QI_WIDGET_BASE_H
#define QI_WIDGET_BASE_H
#include	<Windows.h>
#include	"QiEventListener.h"
namespace QiUi
{
	enum class QiWidgetType
	{
		WidgetBase,
		Button,
		Edit,
		Label,
		GroupBox,
		Window
	};

	class QiWidgetInfo
	{
	public:
		QiWidgetInfo();
		~QiWidgetInfo();
		LPCTSTR lpClassName = TEXT("Base");			// 窗口类名称
		LPCTSTR lpWindowName = TEXT("Base");		// 窗口标题
		DWORD dwStyle = WS_CHILD | WS_VISIBLE;      // 窗口风格，或称窗口格式
		int x = 0;									// 初始 x 坐标
		int y = 0;									// 初始 y 坐标
		int nWidth = 80;								// 初始 x 方向尺寸
		int nHeight = 20;							// 初始 y 方向尺寸
		HWND hWndParent = NULL;						// 父窗口句柄
		HMENU hMenu = NULL;							// 窗口菜单句柄
		HINSTANCE hInstance = NULL;					// 程序实例句柄
		LPVOID lpParam = nullptr;					// 创建参数
		QiWidgetType type = QiWidgetType::WidgetBase;				// 控件类型
	private:

	};

	class QiWidgetBase : public QiEventHandle
	{
	public:
		QiWidgetBase();
		~QiWidgetBase();
		virtual bool	OnTickEvent() override;
		virtual bool	OnClickEvent() override;
		virtual	bool	Create(QiWidgetBase& parentWidget);
		virtual	bool	SetPositon(int x, int y, int width, int height);

		HWND	GetHandle();
	protected:
		QiWidgetInfo info_;
		QiWidgetBase* parentWidget = nullptr;
		HWND handle_ = NULL;
	};
}

#endif // !QI_WIDGET_BASE_H

