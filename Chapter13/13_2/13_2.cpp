// Class Templates
//함수와 같이, 클래스도 템플릿으로 사용할 수 있다

#include <iostream>
#include "MyArray.h"

int main()
{
	//MyArray에 클래스로 template화 되어있는 걸 가져다 쓸 것이기 때문에
	// template argument를 지정해 주어야 한다.
	MyArray<double> my_array(10); // double type에 대해 instantiation
	MyArray<char> my_array_1(10); // char type에 대해 instantiation
	
	for (int i = 0; i < my_array.getLength(); ++i)
	{
		my_array[i] = i * 0.5;
	}
	for (int i = 0; i < my_array_1.getLength(); ++i)
	{
		my_array_1[i] = i + 65 ;
	}


	my_array.print();
	my_array_1.print();

	return 0;

}

