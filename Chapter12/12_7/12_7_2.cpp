#include <iostream>
#include <string>
using namespace std;

// Interface 클래스: 내부에 있는 함수들이 모두 Pure Virtual Function인 경우
// 자기가 실제로 무엇을 수행할 지는 아무것도 정해지지 않은 상태, 내용물이 없음
// ~ 를 해야 한다라고 정의만 하는 구조
// 외부에서 사용할 때 ~ 한 기능을 사용할 것이라 '예측'만 가능 -> 중계기 역할

class IErrorLog // Interface class이므로 class명 앞자리에 I 붙여줌
{
public:
	virtual bool reportError(const char* errorMessage) = 0;

	virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a file" << endl;
		return true;

	}

};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override 
	{
		cout << "Printing error to a console" << endl;
		return true;
 	}

};

void doSomething(IErrorLog & log)
{
	log.reportError("Runtime error!!");
}

int main()
{
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);
	doSomething(console_log);

	return 0;
}