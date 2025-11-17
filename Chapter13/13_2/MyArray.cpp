#include "MyArray.h"
using namespace std;

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < m_length; ++i)
		cout << m_data[i] << " ";
	cout << endl;
}

// explicit instantiation
// 외부 어떤 파일에서 char type의 print 함수를 instantiaion할거라 지정
// compile time에 linking error 방지
template void MyArray<char>::print();
template void MyArray<double>::print();

// explicit instantiation
// class로 explicit instantiaion 해도 됨
//template class MyArray<char>;
//template class MyArray<double>;
