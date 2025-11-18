#pragma once

#include <iostream>
using namespace std;

template <class T>
class Storage8
{
private:
	T m_array[8];
public:
	void set(int index, const T& value)
	{
		m_array[index] = value;
	}

	const T& get(int index)
	{
		return m_array[index];
	}
};

// bool type에 대해 specialization
// memory address는 byte 단위임
// 8개의 bool type을 동시에 처리한다면 
// 1bype data type만 처리가 가능
template <>
class Storage8<bool>
{
private:
	// 1byte 할당 
	unsigned char m_data;
public:
	Storage8() : m_data(0)
	{
	}

	void set(int index, bool value)
	{
		unsigned char mask = 1 << index;

		if (value)
			m_data |= mask;
		else
			m_data &= ~mask;
	}

	bool get(int index)
	{
		unsigned char mask = 1 << index;
		return (m_data & mask) != 0;
	}
};