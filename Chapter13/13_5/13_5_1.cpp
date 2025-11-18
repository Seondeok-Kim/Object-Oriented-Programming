// Class Template Specialization
#include <iostream>
#include <array>
#include "Storage.h"

using namespace std;

template<typename T>
class A
{
public:
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
	void doSomething()
	{
		cout << "Char type specialization" << endl;
	}
};

int main()
{
	A<int>		a_int;
	A<double>	a_double;
	A<char>		a_char;

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	a_int.test();
	a_double.test();
	// char type은 specialization 할 때 test()를 구현하지 않았음
	//a_char.test();


}