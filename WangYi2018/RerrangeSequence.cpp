#include <iostream>

using namespace std;

int main()
{
	int t, n, temp;
	int NumOf4; //被4整除的个数
	int NumOf2; //被2整除的个数
	int NumOf1; //既不被4整除又不被2整除的个数，也就是奇数。
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		NumOf4 = 0;
		NumOf2 = 0;
		NumOf1 = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			if (temp % 4 == 0)
				NumOf4++;
			else if (temp % 2 == 0)
				NumOf2++;
			else
				NumOf1++;
		}
		if (NumOf4 >= NumOf1 || (NumOf2 == 0 && NumOf4 >= NumOf1 - 1))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
