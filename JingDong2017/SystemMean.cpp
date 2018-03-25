#include <iostream>
#include <vector>
using namespace std;

int ComonFact(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return ComonFact(b, a%b);
}

void FracOut(int numerator, int denominator)
{
	int comonFact = ComonFact(numerator, denominator);
	if (comonFact == 1)
	{
		cout << numerator << '/' << denominator << endl;
		return;
	}
	else
		return FracOut(numerator/comonFact, denominator/comonFact);
}

int countBaseSum(int value, int base)
{
	int sum = 0;
	if (value / base < base)
		return value / base + value % base;
	sum += (countBaseSum(value / base, base) + value % base);
	return sum;
}

void SystemMean(vector<int> data)
{
	int value;
	int sum, base_sum;
	for (int i = 0; i < data.size(); ++i)
	{
		sum = 0;
		value = data[i];
		if (value < 2)
			continue;
		if (value == 2)
		{
			cout << 1 << '/' << 1 << endl;
			continue;
		}
		for (int base = 2; base < value; ++base)
		{
			base_sum = countBaseSum(value, base);
			sum += base_sum;
		}
		FracOut(sum, value - 2);
	}
	return;
}

int main()
{
	int temp;
	vector<int> data;
	while (cin >> temp)
		data.push_back(temp);
	SystemMean(data);
	return 0;
}
