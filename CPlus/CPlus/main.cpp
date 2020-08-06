#include <iostream>
#define SQUARE(x) ((x)*(x))

inline int SQUARE2(int x)
{
	return x * x;

}
template <typename T>
inline T SQUARE3(T x)
{
	return x * x;

}
int main()
{

	std::cout << "test" << std::endl;
	int num = 0;
	std::cin >> num;
	std::cout << "num" << num << SQUARE(num) << std::endl;

	char str[50];

	std::cin >> str;
	std::cout << "string : " << str << std::endl;

	return 0;
}