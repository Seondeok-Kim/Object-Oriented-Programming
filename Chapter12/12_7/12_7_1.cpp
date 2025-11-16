//12.7 순수 가상 함수, 추상 기본 클래스, 인터페이스 클래스
//순수 가상함수는 body가 없다 -> 자식 클래스에서 반드시 override해야함
//순수 가상 함수가 포함이 된 클래스 = 추상 클래스
//순수 가상 함수로만 이루어진 클래스 = 인터페이스 클래스


#include <iostream>
#include <string>

using namespace std;


class Animal 
{
protected:
string m_name;

public:
	Animal(std::string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }
	// Pure Virtual Function
	// virtual 뒤 const = 0으로 선언된 변수
	// 부모 클래스에서는 일단 정의만 된 함수이고, 
	// 자식 클래스에서 무조건 override 해서 구현해야 한다는 의미 
	virtual void speak() const = 0;
	// Pure Virtual Function이 하나라도 포함된 함수 = Abstract Class
	// Abstract Class는 instance를 만들 수 없다


	//virtual void speak() const
	//{

	//	cout << m_name << " ??? " << endl;
	//}
};

////Pure Virtual Function은 별도로 body 정의 가능
//void Animal::speak() const
//{
//
//	cout << m_name << " ??? " << endl;
//}

class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)
	{
	}

	void speak() const
	{
		cout << m_name << " Meow " << endl;
	}

};

class Dog : public Animal
{
public:
	Dog(string name)
		:Animal(name)
	{
	}

	void speak() const
	{
		cout << m_name << " Woof " << endl;
	}
};


class Cow : public Animal
{
public:
	Cow(string name)
		:Animal(name)
	{}
	// 부모 클래스에 정의된 Fure Virtual Function을 
	// 자식 클래스에서 오버라이드해서 Fure Virtual Function 구현해야 함
	virtual void speak() const
	{
		cout << m_name << " Moooo " << endl;
	}
};


int main() 
{
	
	Cow cow("Hello");
	cow.speak();


	return 0;

}