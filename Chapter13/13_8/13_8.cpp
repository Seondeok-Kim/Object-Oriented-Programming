//멤버 함수를 한번 더 템플릿화하기(Templatize)
//어떤 클래스가 template화 되어 있는 경우에도
//멤버함수에 추가적인 template를 적용하는 방법이 있다.

#include <iostream>
using namespace std;

template<class T>
class A
{
private:
	T m_value;
public:
	A(const T& input)
		: m_value(input)
	{
	}

	// TT는 doSomething()에서만 부분적으로 적용되는 template parameter
	template<typename TT>
	void doSomething(const TT & input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)m_value << endl;
	}

	void print()
	{
		cout << m_value << endl;
	}
};


int main()
{
	A<int> a_int(123);
	a_int.print();

	a_int.doSomething(123.4);
	a_int.doSomething('a');

	A<char> a_char('A');
	a_char.print();

	// 파라미터로 memeber function의 instantiation을 구분하고자 함
	a_char.doSomething(int());
	a_char.doSomething(char());


	return 0;
}