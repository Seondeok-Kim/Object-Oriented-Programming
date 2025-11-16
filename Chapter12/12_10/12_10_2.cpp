// Dynamic Casting (동적 형변환)
// 다형성을 사용하다 보면 
// 자식 클래스의 포인터를 부모 클래스의 포인터로 바꿔줬다가
// 다시 자식 클래스의 포인터로 바꿔줘야 하는 경우가 있다. 
// 이 경우, 동적 형변환을 사용한다. 

#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_name = "Dr.Two";

	virtual void print() override
	{
		cout << "I'm derived" << endl;
	}
};

int main()
{
	Derived1 d1;
	d1.m_j = 2048;
	Base* base = &d1; // base의 포인터에 d1의 주소를 넣음

	// base를 Base에서 Derived2로 동적 형변환
	// Dynamic cast는 캐스팅에 실패하면 null point 를 넣어버림 -> 아무것도 안뜸
	auto* base_to_d1 = dynamic_cast<Derived2*>(base);
	if (base_to_d1 != nullptr)
		cout << base_to_d1->m_name << endl; // 아무것도 안뜸
	else
		cout << "Failed" << endl;
	return 0;
}