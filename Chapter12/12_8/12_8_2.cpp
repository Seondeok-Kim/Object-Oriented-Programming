// Virtual base classes (가상 기본 클래스)와 다이아몬드 문제
// 부모 클래스 A, 자식 클래스 B1, B2가 있을 때
// 부모 클래스 앞에 virtual을 지정해주지 않으면
// 클래스 A가 2개가 생성되는 오류가 발생함

#include <iostream>
using namespace std;

class PoweredDevice
{
public:
	int m_i;

	PoweredDevice(int power)
	{
		cout << "PowerDevice: " << power << '\n';
	}
};

class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		cout << "Scanner: " << scanner << endl;
	}
};

class Printer : virtual public PoweredDevice
{
public:
	Printer(int printer, int power)
		: PoweredDevice(power)
	{
		cout << "Printer: " << printer << endl;
	}
};


class Copier : public Scanner, public Printer
{
public:
	// Constructor Initializer Liset
	Copier(int scanner, int printer, int power)
		: Scanner(scanner, power), Printer(printer, power),
		PoweredDevice(power)
	{
	}

};

int main()
{
	// 생성자 호출 
	Copier cop(1, 2, 3);

	// 주소 출력 -> 부모 클래스 상속시 virtual 추가 -> 두 PoweredDevice의 m_i의 주소가 같다
	// PoweredDevice 1번 호출됨
	// cop에서 Scanner로 PoweredDevice를 타고 m_i의 주소 출력
	cout << &cop.Scanner::PoweredDevice::m_i << endl; // 부모 클래스 1번 출력
	// cop에서 Printer로 PoweredDevice를 타고 m_i의 주소 출력
	cout << &cop.Printer::PoweredDevice::m_i << endl; // 부모 클래스 1번 출력
}