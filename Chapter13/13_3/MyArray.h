#pragma once
#include <assert.h>
#include <iostream>
using namespace std;

// 자료형이 아닌 template parameter
// T_SIZE는 compile time에 미리 결정된다
// 따라서 T_SIZE를 const를 사용하지 않는 한 변수를 사용해서 지정할 수 없다. 
template<typename T, unsigned int T_SIZE>
class MyArray
{
private:
	//int m_length;
	T *m_data; // T m_data[T_SIZE]

public:
	MyArray()
	{
		//m_length = 0;
		m_data = new T [T_SIZE];
	}

	~MyArray() 
	{
		delete[] m_data;
	}

	T & operator[] (int index)
	{
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}

	// Non-type parameter를 사용할 경우,
	// 이전에 explicit initiation을 한다면
	// unsigned int를 모두 하나하나 지정해 줘야 하기 때문에
	// 외부 cpp 파일에 따로 구현하지 않고 헤더 파일 클래스 안에 함수를 구현함
	void print()
	{
		for (int i = 0; i < T_SIZE; ++i)
		{
			cout << m_data[i] << " ";
		}
		cout << endl;
	}
};


