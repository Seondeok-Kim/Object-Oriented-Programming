// ¿¹¿Ü Ã³¸®¿Í ½ºÅÃ µÇ°¨±â(Stack Unwinding)
#include <iostream>
using namespace std;

// void last() throw(int) exception specifier
// void last() throw(...) exception specifier

void last() throw(...) // char이 아닌 다른 type의 exception을 thow 할 수 있다느 ㄴ뜻
{
	cout << "Last " << endl;
	cout << "Throws exception" << endl;

	throw 'a';

	cout << "End last" << endl;
}


void third()
{
	cout << "Third" << endl;
	last();
	cout << "End third" << endl;
}


void second()
{
	cout << "Second" << endl;
	try
	{
		third();
	}
	catch (double)
	{
		cerr << "Second caught double exception" << endl;
	}
	cout << "End second" << endl;
}


void first()
{

	cout << "First" << endl;
	try
	{
		second();
	}
	catch (double)
	{
		cerr << "first caught int exception" << endl;
	}

	cout << "End first " << endl;
}

/*
Start 출력
try 블록 내에서 first() 호출
catch(int) pass

Second 출력
try 블록 내에서 third() 호출

Third 출력
try 블록 내에서 last() 호출
last()에서 exception이 발생하므로 End third 실행x

Last 출력
Throws exception 출력
throw -1 실행 -> int 타입 예외 발생
이후 End last 실행x
프로그램은 function call stack을 하나씩 종료하면서
해당 exception을 잡을 수 있는 catch를 찾을 때까지 위로 올라감

// Stack unwinding 시작
last() 중단 후 third()로 되돌아감
third() 내 try-catch가 없으니 exception을 못 잡음 -> third() 중단
second() 내 try-catch는 double 타입만 있으므로 해당 catch는 무시됨 -> second() 중단
first() 내 try-catch는 double 타입만 있으므로 해당 catch는 무시됨 -> second() 중단
main()에서 try-catch는 int 타입만 있으므로 여기서도 exception 해결할 수 없음

어디서도 exception 잡을 수 없으므로
catch(...)에서 처리
main caught ellipses exception 출력
End main 출력


[Stack] 
last()
third()
second()
first()
main()

*/



int main()
{
	cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		cerr << "main caught int exception" << endl;
	}

	/* uncaught exceptions (잡을 수 없는 exception의 경우) */
	// 어떤 타입의 exception이든 다 받음
	 catch (...) // catch-all handlers
	{
	    cerr << "main caught ellipses exception" << endl;
	}

	cout << "End main" << endl;

	return 0;
}

