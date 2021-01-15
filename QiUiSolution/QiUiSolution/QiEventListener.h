#ifndef QI_EVENT_LISTENER_H
#define QI_EVENT_LISTENER_H
namespace QiUi
{
	class OnClickListener
	{
	public:
		OnClickListener() {}
		virtual	~OnClickListener() {}

		virtual bool	OnClickEvent() = 0;
		virtual	bool	OnDoubleClickEvent() = 0;

	};

	class OnTickListener
	{
	public:
		OnTickListener() {}
		virtual	~OnTickListener() {}

		virtual bool	OnTickEvent() = 0;
	};
}

#endif // !QI_EVENT_LISTENER_H
