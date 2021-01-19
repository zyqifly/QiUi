#include	"QiEdit.h"
namespace QiUi
{
	QiEdit::QiEdit()
	{
		info_.type = QiWidgetType::Edit;
		info_.lpClassName = TEXT("edit");
		info_.lpWindowName = TEXT("input ...");
		info_.dwStyle = WS_VISIBLE | WS_CHILD | WS_BORDER | DT_VCENTER;
	}

	QiEdit::~QiEdit()
	{
	}
}