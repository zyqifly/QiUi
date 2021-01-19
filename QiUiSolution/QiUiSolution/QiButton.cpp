#include	"QiButton.h"
namespace QiUi
{
	QiButton::QiButton()
	{
		info_.type = QiWidgetType::Button;
		info_.lpClassName = TEXT("button");
		info_.lpWindowName = TEXT("Click Me");
		info_.dwStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER;
	}

	QiButton::~QiButton()
	{
	}
}
