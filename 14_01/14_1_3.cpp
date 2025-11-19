// Exception Handling (예외 처리)

#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main()
{
	// try, catch, throw
	// try 블록에서 코드를 실행하다가
	// throw를 만나면 try를 빠져나와
	// 타입이 맞는 catch 블록으로 점프
	// 예외 처리 후 프로그램 계속 실행
	double x;
	cin >> x;

	// 예외가 발생할 수 있는 코드
	try
	{
		// something happened
		throw std::string("My error message ");
	}
	// 예외 발생 시 처리하는 코드
	catch (int x)
	{
		cout << "Catch integer" << x << endl;
	}
	catch (double x)
	{
		cout << "Catch double" << x << endl;
	}
	catch (const char * error_message)
	{
		cout << "Char *" << error_message << endl;
	}
	catch (std::string error_message)
	{
		cout << error_message << endl;
	}

	return 0;
}