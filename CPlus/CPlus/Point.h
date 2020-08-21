#pragma once
#include <iostream>
class Point
{
private:
	const int xy;
	int x;
	int y;
public:
	Point(int nx, int ny);

	void ShowPoint() const;

};

class  AAA
{
public:
	AAA(void);
	void ShowText();
	void AddNum();
	AAA& GetInstance(int num) const; 
	AAA* GetInstance2(int num) const;
private:
	AAA(int);
	int num;
};

class BBB
{
public :
	BBB(AAA& a, const int& n);
	void ShowText();
private:
	AAA& ref;
	const int& num;
};
