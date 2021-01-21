#ifndef QI_OBJECT_H
#define QI_OBJECT_H
#define SIGNAL public
#include	<vector>
#include	<functional>
#include	"QiBinder.h"
namespace QiUi
{
	class QiObject
	{
	public:
		QiObject() {}
		~QiObject() {}

		template<typename Reciever, typename Functor, typename Slot>
		bool	Connect(std::vector<Functor> &signalContainer, Reciever *reciever, Slot slot)
		{
			if (reciever == nullptr)
			{
				return false;
			}

			Functor signal = Bind(slot, reciever);
			signalContainer.push_back(signal);

			return	 true;
		}

		template<typename Reciever, typename Functor, typename Slot>
		bool	DisConnect(std::vector<Functor>& signalContainer, Reciever* reciever, Slot slot)
		{
			if (reciever == nullptr)
			{
				return false;
			}

			Functor signal = Bind(slot, reciever);
			
			for (auto i = signalContainer.begin(); i != signalContainer.end(); i++)
			{
				Functor elem = *i;
				if (elem.target<Functor>() == signal.target<Functor>())
				{
					signalContainer.erase(i);
					return	true;
				}
			}

			return	 true;
		}
	};
}

#endif // !QI_OBJECT_H
