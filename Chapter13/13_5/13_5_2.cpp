// Class Template Specialization
#include <iostream>
#include <array>
#include "Storage.h"

using namespace std;

template<typename T>
class A
{
public:

	A(const T& input)
	{

	}


	void doSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void test()
	{}
};

// char type에 대해서만 특별한 행동을 하도록 specialization
template<>
class A<char>
{
public:

	A(const char & temp)
	{

	}
	void doSomething()
	{
		cout << "Char type specialization" << endl;
	}
};

int main()
{
	// C++ 17버전에서도
	// 클래스의 경우에는 함수에서와 같이 argument를 initialization화 할 수 있음
	A		a_int(1);
	A		a_double(3.14);
	A		a_char('a');

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	a_int.test();
	a_double.test();
	// char type은 specialization 할 때 test()를 구현하지 않았음
	//a_char.test();


}