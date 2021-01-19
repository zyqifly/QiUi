// QiUiSolution.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include    "QiObject.h"
#include	"QiPresenter.h"
#include	"QiWindow.h"
#include	"QiButton.h"
#include	"QiEdit.h"
using namespace QiUi;

class A : public QiObject
{
public:
	A() {}
	virtual ~A() {}

	void OnEvent()
	{
		for (auto elem : eventSignal)
		{
			if (elem != nullptr)
			{
				elem();
			}
		}
	}

SIGNAL:
	typedef	std::function<void(void)> EventSinal;
	std::vector<EventSinal> eventSignal;
};

class B
{
public:
	B() {}
	~B() {}

	void OnEventSlot()
	{
		std::cout << "I am B!" << std::endl;
	}
	int	setScalingMode(int mode)
	{
		return mode;
	}
private:

};

template<class S, class P>
bool CheckBase(S s, P p)
{
	return std::is_base_of<P, S>::value;
}
int main()
{
	/*A a;
	B b;
	a.Connect(a.eventSignal, &b, &B::OnEventSlot);
	a.OnEvent();

	QiPresenter p;
	bool ret = CheckBase(p, OnClickListener());
	if (ret)
	{
		((OnClickListener*)(&a))->OnClickEvent();
	}*/
	using	namespace QiUi;
	QiWindow window;
	QiButton button;
	QiEdit edit;
	button.SetPositon(5, 30, 100, 20);
	edit.SetPositon(5, 5, 100, 20);
	window.Create();
	button.Create(window);
	edit.Create(window);
	window.Show();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
