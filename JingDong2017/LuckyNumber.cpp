#include <iostream>
#include <vector>
using namespace std;

int fx(int n, int base)
{
	if (n / base < base)
		return n / base + n % base;
	return fx(n / base, base) + n % base;
}

void LuckyNumber(int n)
{
	if (n <= 0)
		return;
	int count = 0;
	int SumOfDecimal;
	int SumOfBinary;
	for (int number = 1; number <= n; ++number)
	{
		SumOfDecimal = fx(number, 10);
		SumOfBinary = fx(number, 2);
		if (SumOfBinary == SumOfDecimal)
			count++;
	}
	cout << count << endl;
	return;
}

int main()
{
	int n;
	cin >> n;
	LuckyNumber(n);
	return 0;
}
