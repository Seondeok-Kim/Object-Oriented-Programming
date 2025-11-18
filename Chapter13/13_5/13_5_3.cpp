// Class Template Specialization
#include <iostream>
#include <array>
#include "Storage.h"

using namespace std;

template<typename T>
class A
{
public:

	A(const T& input)
	{

	}


	void doSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void test()
	{}
};



int main()
{
	// Define a Storage8 for integers
	Storage8<int> intStorage;

	for (int count = 0; count < 8; ++count)
		intStorage.set(count, count);

	for (int count = 0; count < 8; ++count)
		cout << intStorage.get(count) << endl;

	cout << "Sizeof Storage8<int> " << sizeof(Storage8<int>) << " bytes " << endl;

	// Define a Storage8 for bool
	Storage8<bool> boolStorage;
	for (int count = 0; count < 8; ++count)
		cout << (boolStorage.get(count) ? "true" : "false") << endl;

	cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << " bytes " << endl;

	return 0;
}