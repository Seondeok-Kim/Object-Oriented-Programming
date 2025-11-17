// 자료형이 아닌 템플릿 매개변수 (Non-type Parameters)

#include "MyArray.h"
using namespace std;

int main()
{
	// T_SIZE는 compile time에 미리 결정된다
	// 그렇기 때문에 100이라는 숫자를 특정 변수에 넣어서 사용할  수 없다.
	MyArray<double, 100> my_array; // array<double, 100>

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i + 65;
	my_array.print();

	return 0;
}
