#ifndef QI_WIDGET_GROUP_H
#define	QI_WIDGET_GROUP_H
#include	"QiWidgetBase.h"
#include	<vector>
namespace QiUi
{
	class QiWidgetGroup
	{
	public:
		QiWidgetGroup();
		virtual ~QiWidgetGroup();
		void	Add(QiWidgetBase &widget);
		virtual	void	SetupUi();
	protected:
		std::vector<QiWidgetBase *> container_;
	};
}
#endif // !QI_WIDGET_GROUP_H

