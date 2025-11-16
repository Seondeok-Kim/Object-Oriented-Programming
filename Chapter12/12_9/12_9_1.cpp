// Object Slicing (객체 잘림)과 reference_wrapper
// 부모 클래스보다 자식 클래스가 더 많은 정보를 가지고 있는 경우가 많음
// 보다 작은 부모 클래스의 객체에다가 보다 큰 자식 클래스의 객체를 강제로 개입시킨다면
// 부모 클래스가 담을 수 있는 정보가 적기 때문에, 자식 클래스의 정보가 잘리게 됨
// 이를 object slicing이라 함
// 만약 의도적으로 slicing을 사용한다면 주석 표시를 권장함

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

class Derived : public Base
{
public:
	// 부모 클래스의 m_i에 대한 정보도 갖고 있고, m_j 정보도 추가됨
	int m_j = 1; 

	virtual void print() override
	{
		cout << "I'm Derived" << endl;
	}
};

void doSomething(Base& b)
{
	b.print();
}

int main()
{
	Derived d;
	//Base& b = d;// I'm Derived 출력
	//Base b = d; // d에서 b로 복사가 일어나 I'm Base 출력
	//b.print(); 

	doSomething(d); // doSomething에 &가 붙어있으므로 I'm Derived 출력
	// doSomething에 &가 없다면 I'm Base 출력
	return 0;

}