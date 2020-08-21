#include <iostream>
#include <list>
#include <vector>
#include "Point.h"

#define SQUARE(x) ((x)*(x))

const int NAME_LENGHT = 100;

inline int SQUARE2(int x)
{
	return x * x;

}
template <typename T>
inline T SQUARE3(T x)
{
	return x * x;
}

namespace hi
{
	void Check()
	{
		std::cout << "Check" << std::endl;

	}
}

struct Account
{
	int ID;
	char Name[NAME_LENGHT];
	int Money;
};


void CreateAccount();
int ShowMeneAndUserInput();
void DepositMenuAndUserInput();
void WithdrawalMenuAndInput();
int AccountCheck(int);
void PrintAccountInfo();
void SwapByRef2(int& , int& );
std::vector<Account> m_AccountList;


int main()
{
	Point p1(1,2);
	Point* p2 = new Point(3, 4);

	AAA a;
	BBB b(a, 100);
	a.AddNum();
	std::cout << std::endl;
	b.ShowText();
	std::cout << std::endl;
	a.AddNum();
	b.ShowText();
	AAA aa = a.GetInstance(3000);
	AAA* aa2 = a.GetInstance2(4000);

	int num = 12;
	int* pnum = &num;
	int** ppnum = &pnum;

	int& num2 = num;
	int* (&refnum2) = pnum;
	int** (&refnum3) = ppnum;

	int swapnum1 = 10;
	int swapnum2 = 20;
	std::cout << "num1 : " << swapnum1 << ", num2 : " << swapnum2 << std::endl;
	SwapByRef2(swapnum1, swapnum2);
	std::cout << "num1 : " << swapnum1 << ", num2 : " << swapnum2 << std::endl;
	
	for (;;)
	{
		int input = ShowMeneAndUserInput();

		switch (input)
		{
		case 1:
			CreateAccount();
			break;
		case 2:
			DepositMenuAndUserInput();
			break;
		case 3:
			WithdrawalMenuAndInput();
			break;
		case 4:
			PrintAccountInfo();
			break;
		case 5:
			return 0;
			break;
		default:
			break;
		}
	}

	
	
	return 0;
}

void SwapByRef2(int &num, int &num2)
{
	int temp = num;
	num = num2;
	num2 = temp;
}

int ShowMeneAndUserInput()
{
	std::cout << "-----Menu-----" << std::endl;
	std::cout << "1. 계좌 개설" << std::endl;
	std::cout << "2. 입금" << std::endl;
	std::cout << "3. 출금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;

	int input;
	std::cout << "선택";
	std::cin >> input;
	std::cout << std::endl;

	return input;
}

void CreateAccount()
{
	int num;
	char name[NAME_LENGHT];
	std::cout << "[계좌 개설]" << std::endl;
	std::cout << "계좌 ID: ";  std::cin >> num;
	int index = AccountCheck(num);
	if (index != -1)
	{
		std::cout << "이미 계좌가 있습니다." << std::endl;
	}

	std::cout << "이름:"; std::cin >> name;

	Account acc;
	acc.ID = num;
	acc.Money = 0;
	strcpy_s(acc.Name, name);
	m_AccountList.push_back(acc);

	std::cout << "개설 완료! " << m_AccountList.size() << std::endl;
}


void WithdrawalMenuAndInput()
{
	int num;
	int money;
	std::cout << "[출금]" << std::endl;
	std::cout << "계좌 ID: ";  std::cin >> num;
	std::cout << "출금액:"; std::cin >> money;
	int index = AccountCheck(num);
	if (index == -1)
	{
		std::cout << "계좌가 없습니다." << std::endl;
	}

	int totalmoney = m_AccountList[index].Money; 
	if (totalmoney < money)
	{
		std::cout << "잔액이 부족합니다." << std::endl;
		return;
	}

	m_AccountList[index].Money = totalmoney - money;
	std::cout << "출금 완료" << std::endl;
}

void DepositMenuAndUserInput()
{
	int num; 
	int money;
	std::cout << "[입금]" << std::endl;
	std::cout << "계좌 ID: ";  std::cin >> num;
	std::cout << "입금액:"; std::cin >> money;
	int index = AccountCheck(num);
	if (index == -1)
	{
		std::cout << "계좌가 없습니다." <<  std::endl;
	}
	m_AccountList[index].Money = m_AccountList[index].Money + money;
	std::cout << "입금 완료" << std::endl;
}

int AccountCheck(int num)
{
	size_t size = m_AccountList.size();
	int index = -1;

	for (size_t i = 0; m_AccountList.size(); i++)
	{
		if (m_AccountList[i].ID == num)
		{
			index = i;
			break;
		}
	}
	return index;
}
void PrintAccountInfo()
{
	int num;
	std::cout << "[계좌 확인]" << std::endl;
	std::cout << "계좌 ID: ";  std::cin >> num;

	int index = AccountCheck(num);
	if (index == -1)
	{
		std::cout << "계좌가 없습니다." << std::endl;
	}
	
	std::cout << "이름 : " << m_AccountList[index].Name  << std::endl;
	std::cout << "금액 : " << m_AccountList[index].Money << std::endl;
}