// Function Template Specialization (함수 템플릿 특수화)
// 여러 가지 기능에 대해 템플릿 기능을 구현하다 보면 
// 특별한 자료형에 대해서는 다른 기능을 구현하고 싶을 때가 있다


#include <iostream>
#include "Storage.h"

using namespace std;

/*
template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

// specialization은 특수한 type에 대해서 적용하는 것이므로
// 굳이 타입을 지정하지 않아도 됨
template<>
char getMax(char x, char y)
{
	cout << "Warning : comparing chars" << endl;
	return (x > y) ? x : y;
}
*/

int main()
{
	/*
	cout << getMax<int>(1, 2) << endl;
	cout << getMax('a', 'b') << endl; // specialization 된 template 실행됨
	*/

	// Member function을 specialization하는 경우
	Storage<int> nValue(5);
	Storage<double> dValue(6.7); // specialization 된 Storage class template 실행됨

	nValue.print();
	dValue.print();

	return 0;
}