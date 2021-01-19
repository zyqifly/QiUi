#ifndef QI_PRESENTER_H
#define QI_PRESENTER_H
#include	"QiView.h"
#include	"QiEventListener.h"
namespace QiUi
{
	class QiPresenter : public OnClickListener , public	OnTickListener
	{
	public:
		QiPresenter() 
		{
			view_ = new QiView();
		}
		virtual	~QiPresenter() {}

		virtual	bool	OnTickEvent()
		{ 
			return view_->OnTickEvent(); 
		}
		virtual bool	OnClickEvent() override
		{
			if (view_ == nullptr)
			{
				return	false;
			}

			return	view_->OnClickEvent();
		}

		virtual	bool	OnSetUpView()
		{
			return	view_->OnSetUpView();
		}

	private:
		QiView	*view_ = nullptr;

	};
}
#endif // !QI_PRESENTER_H

