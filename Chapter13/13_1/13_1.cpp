// 함수 Templates(함수 템플릿)
// 템플릿은 여러 자료형에 대해 비슷한 코드를 작성하는 것을 방지함

#include <iostream>
#include "Cents.h"
using namespace std;



// 자료형은 다르나 구현이 동일한 함수 여러 개 -> 비효율적!
/*
int getMax(int x, int y)
{
	return (x > y) ? x : y;
}

double getMax(double x, double y)
{
	return (x > y) ? x : y;
}

float getMax(float x, float y)
{
	return (x > y) ? x : y;
}

char getMax(char x, char y)
{
	return (x > y) ? x : y;
}
*/

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}


int main()
{
	cout << getMax(1, 2) << endl;
	cout << getMax(3.14, 1.592) << endl;
	cout << getMax(1.0f, 3.4f) << endl;
	cout << getMax('a', 'c') << endl;

	// template함수에서 > 연산자는 비교 연산자로 사용하고 있고
	// Cent.h 내에서는 < 를 다른 용도로 사용하므로 friend를 사용해서 오버라이드 해야함
	cout << getMax(Cents(5), Cents(9)) << endl;

	return 0;
}
