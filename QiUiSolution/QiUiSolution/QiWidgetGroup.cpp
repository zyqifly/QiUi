#include	"QiWidgetGroup.h"
namespace QiUi
{
	QiWidgetGroup::QiWidgetGroup() : container_(std::vector<QiWidgetBase *>())
	{
	}

	QiWidgetGroup::~QiWidgetGroup()
	{
	}

	void	QiWidgetGroup::Add(QiWidgetBase& widget)
	{
		container_.push_back(&widget);
	}

	void	QiWidgetGroup::SetupUi()
	{
	}
}