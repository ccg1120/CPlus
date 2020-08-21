#include "Point.h"


Point::Point(int nx, int ny) : x(nx), y(ny), xy(100)
{}

//Point::Point(int nx, int ny, int nxy)
//{
//
//}
void Point::ShowPoint() const
{
	std::cout << "x : " << x << " y : " << y << std::endl;
}

AAA::AAA()
{
	num = 300;
	ShowText();
}
AAA::AAA(int num)
{
	this->num = num;
}
AAA& AAA::GetInstance(int num) const
{
	AAA* p = new AAA(num);
	return *p;
}
AAA* AAA::GetInstance2(int num) const
{
	AAA* p = new AAA(num);
	return p;
}

void AAA::ShowText()
{
	std::cout << "AAA = " << num << std::endl;
}
void AAA::AddNum()
{
	num += 300;
}

BBB::BBB(AAA& a, const int& n)
	: ref(a), num(n)
{

}
void BBB::ShowText()
{
	ref.ShowText();
	std::cout << "BBB : " << num << std::endl;
}

