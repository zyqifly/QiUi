#include	"QiWidgetBase.h"
namespace QiUi
{

	QiWidgetInfo::QiWidgetInfo()
	{
	}

	QiWidgetInfo::~QiWidgetInfo()
	{
	}

	QiWidgetBase::QiWidgetBase() :info_(QiWidgetInfo())
	{
	}

	QiWidgetBase::~QiWidgetBase()
	{
	}

	bool	QiWidgetBase::OnTickEvent()
	{
		return true;
	}

	bool	QiWidgetBase::OnClickEvent()
	{
		return	true;
	}

	bool	QiWidgetBase::Create(HWND handle/*QiWidgetBase& parentWidget*/)
	{
		// this->parentWidget = handle;
		this->info_.hWndParent = handle;
		this->handle_ = CreateWindow(   //按钮创建  
			info_.lpClassName,
			info_.lpWindowName,
			info_.dwStyle,
			info_.x, info_.y, info_.nWidth, info_.nHeight,
			info_.hWndParent,
			info_.hMenu,
			info_.hInstance,
			info_.lpParam);

		if (handle_ == NULL)
		{
			return	false;
		}

		return	true;
	}

	bool	QiWidgetBase::SetPositon(int x, int y, int width, int height)
	{
		info_.x = x;
		info_.y = y;
		info_.nWidth = width;
		info_.nHeight = height;
		if (handle_ != NULL) // 已经创建，需要刷新
		{
		}

		return	true;
	}
}