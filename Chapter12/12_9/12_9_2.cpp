// Object Slicing (객체 잘림)과 reference_wrapper
// 부모 클래스보다 자식 클래스가 더 많은 정보를 가지고 있는 경우가 많음
// 보다 작은 부모 클래스의 객체에다가 보다 큰 자식 클래스의 객체를 강제로 개입시킨다면
// 부모 클래스가 담을 수 있는 정보가 적기 때문에, 자식 클래스의 정보가 잘리게 됨
// 이를 object slicing이라 함
// 만약 의도적으로 slicing을 사용한다면 주석 표시를 권장함

#include <iostream>
#include <string>
#include <vector>
#include <functional>
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
	Base b;
	Derived d;

	/*
	std::vector<Base> my_vec;
	
	my_vec.push_back(b);
	// Derived의 객체를 넣었지만, push back 하는 과정에서 slicing 발생 
	my_vec.push_back(d); // Base가 되버림

	for (auto & ele : my_vec)
		ele.print();
	*/

	/*
	std::vector<Base*> my_vec;
	my_vec.push_back(&b);// Base 출력
	my_vec.push_back(&d); // Derive로 출력

	for (auto& ele : my_vec)
		ele->print();
	*/

	// my_vec은 Base의 reference를 저장하는 vector가 됨
	//std::vector<Base&> my_vec; 처럼 동작하게 함
	std::vector<std::reference_wrapper<Base>> my_vec;
	my_vec.push_back(b); // Base 출력
	my_vec.push_back(d); // Derive로 출력

	for (auto& ele : my_vec)
		ele.get().print();

	return 0;

}