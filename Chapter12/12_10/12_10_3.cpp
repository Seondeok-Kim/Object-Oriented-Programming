// Dynamic Casting (동적 형변환)
// 다형성을 사용하다 보면 
// 자식 클래스의 포인터를 부모 클래스의 포인터로 바꿔줬다가
// 다시 자식 클래스의 포인터로 바꿔줘야 하는 경우가 있다. 
// 이 경우, 동적 형변환을 사용한다. 
// 실제 코드 구현 시 동적 형변환 사용하기 보다는 functional이나 lambda function을 사용하는 것 권장

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

	/*
	// base를 Base에서 Derived1로 동적 형변환
	auto* base_to_d1 = static_cast<Derived1*>(base); // I'm derived 출력
	if (base_to_d1 != nullptr)
		base_to_d1->print();
	else
		cout << "Failed" << endl;
	*/

	// base를 Base에서 Derived2로 동적 형변환
	// dynamic cast를 사용할 경우 derived1 -> base -> derived2 불가능
	// 메모리에 저장되어 있는 건 d1이므로 base로 변환했다 다시 d1으로 변환하는 건 문제가 없기 때문

	// static cast는 할 수 있는 한 최대한 형변환 하려 함
	// static cast를 사용할 경우 derived1 -> base -> derived2 가능
	// static cast는 런타임에서 에러 체크를 하지 않기 때문
	// dynamic cast는 런타임에서 에러 체크 함
	auto* base_to_d1 = static_cast<Derived2*>(base); // I'm derived 출력
	if (base_to_d1 != nullptr)
		base_to_d1->print();
	else
		cout << "Failed" << endl;
	return 0;

}

