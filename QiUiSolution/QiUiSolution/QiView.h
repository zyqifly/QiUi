#ifndef QI_VIEW_H
#define QI_VIEW_H
#include	<iostream>

namespace QiUi
{
	class QiPresenter;
	class QiView
	{
	public:
		QiView() {}
		virtual ~QiView() {}
		virtual	bool	OnTickEvent()
		{
			std::cout << "QiView::OnTick()" << std::endl;

			return true; 
		}
		virtual	bool	OnClickEvent()
		{
			std::cout << "QiView::OnClick()" << std::endl;

			return true;;
		}

		virtual	bool	OnSetUpView()
		{
			return	true;
		}
	private:
		QiPresenter *presenter_  = nullptr;

	};
}
#endif // !QI_VIEW_H

