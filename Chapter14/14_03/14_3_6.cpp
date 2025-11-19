// 예외 클래스와 상속
#include <iostream>
using namespace std;

class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException : public Exception
{

public:
	void report()
	{
		cerr << "Array exception" << endl;
	}
};


class MyArray 
{
private:
	int m_data[5];

public:
	int & operator [] (const int& index)
	{
		//if (index < 0 || index >= 5) throw - 1;
		if (index < 0 || index >= 5) throw ArrayException();
		return m_data[index];
	}
};

void doSomething()
{
	MyArray my_array;

	try 
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	//catch (ArrayException& e)
	//{
	//	cout << "doSomething()" << endl;
	//	e.report();
	//	throw e; // stack rewinding
	//}
	catch (Exception & e)
	{
		cout << "doSomething()" << endl;
		e.report(); 
		throw;
	}

}


int main()
{
	try
	{
		doSomething(); // doSomething으로 들어가서 exception 처리
	}
	catch (ArrayException& e) // stack rewinding으로 인해 해당 catch에서 한번 더 받음
	{
		cout << "main()" << endl;
		e.report();
	}
	catch (Exception& e)
	{
		cout << "main()" << endl;
		e.report();
	}
	return 0;
}