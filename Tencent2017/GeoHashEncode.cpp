#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int left = -90;
	int right = 90;
	for (int i = 0; i < 6; ++i)
	{
		if (n < (left + right) / 2)
		{
			cout << 0;
			right = (left + right) / 2;
		}
		else
		{
			cout << 1;
			left = (left + right) / 2;
		}
	}
	cout << endl;
	return 0;
}
