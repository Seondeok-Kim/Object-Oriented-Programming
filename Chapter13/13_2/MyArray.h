#pragma once
#include <assert.h>
#include <iostream>
using namespace std;

template<typename T>
class MyArray
{
private:
	int m_length;
	T *m_data;

public:
	MyArray()
	{
		m_length = 0;
		m_data = nullptr;
	}

	MyArray(int length)
	{
		m_data = new T [length];
		m_length = length;
	}
	~MyArray() 
	{
		reset();
	}

	void reset()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	T & operator[] (int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength()
	{
		return m_length;
	}

	// 우클릭 -> Quick -> Move Definition Location -> MyArray.cpp로
	// MyArray.cpp에 함수가 정의되어 있으므로, main.cpp에서 해당 함수를 예를 들어 double형을 써서 사용하려 한다면
	// compile time에 MyArray.cpp 파일 내에서는 어떤 자료형을 사용하는 지 알 수 없음.
	// 그렇기 때문에 main.cpp에서 특정 자료형을 선언해서 사용한다면 linking error가 발생한다.
	// main.cpp에 "MyArray.cpp" 추가해 해결해도 되지만 프로젝트 규모가 커질 경우 권장하지 않음
	// MyArray.cpp로 가서 특정 type으로 compile해야 한다고 지정해주는 코드를 추가해주어야 함
	// 이를 explicit instantitation이라 함
	void print(); // 클래스 안에 함수만 정의되어 있으므로 정리가 됨
};


