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

	};

	class OnTickListener
	{
	public:
		OnTickListener() {}
		virtual	~OnTickListener() {}

		virtual bool	OnTickEvent() { return true; }
	};

	class QiEventHandle : public OnClickListener, public OnTickListener
	{
	public:
		QiEventHandle() {}
		virtual ~QiEventHandle() {}

	private:

	};

	
}
#endif // !QI_EVENT_LISTENER_H
