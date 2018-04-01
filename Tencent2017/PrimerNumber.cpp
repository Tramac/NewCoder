#include <iostream>
using namespace std;

bool isPrimer(int n)
{
	if (n == 2)
		return false;
    for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n / 2; ++i)
	{
		if (isPrimer(i) && isPrimer(n - i))
			count++;
	}
	cout << count << endl;
	return 0;
}
