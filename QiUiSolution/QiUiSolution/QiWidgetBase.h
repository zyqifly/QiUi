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
		LPCTSTR lpClassName = TEXT("Base");			// ����������
		LPCTSTR lpWindowName = TEXT("Base");		// ���ڱ���
		DWORD dwStyle = WS_CHILD | WS_VISIBLE;      // ���ڷ�񣬻�ƴ��ڸ�ʽ
		int x = 0;									// ��ʼ x ����
		int y = 0;									// ��ʼ y ����
		int nWidth = 80;								// ��ʼ x ����ߴ�
		int nHeight = 20;							// ��ʼ y ����ߴ�
		HWND hWndParent = NULL;						// �����ھ��
		HMENU hMenu = NULL;							// ���ڲ˵����
		HINSTANCE hInstance = NULL;					// ����ʵ�����
		LPVOID lpParam = nullptr;					// ��������
		QiWidgetType type = QiWidgetType::WidgetBase;				// �ؼ�����
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

