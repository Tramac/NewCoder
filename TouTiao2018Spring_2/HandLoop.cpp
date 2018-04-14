#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, c;
	cin >> n >> m >> c;
	vector<vector<int> > pearls;
	pearls.resize(n + m -1);
	for (int i = 0; i < n; ++i)
	{
		int num_i;
		cin >> num_i;
		pearls[i].push_back(num_i); // 可以这样赋值
		for (int j = 1; j <= num_i; ++j)
		{
			int temp;
			cin >> temp;
			pearls[i].push_back(temp);
		}
	}
	for (int i = n; i < n + m - 1; ++i) // 注意令首尾相连
	{
		pearls[i] = pearls[i - n];
	}
	int sum = 0;
	for (int i = 1; i <= c; ++i)
	{
		int sign = 0;
		for (int j = 0; j < n; ++j)
		{
			int count = 0;
			for (int k = j; k <= j + m - 1; ++k)
			{
				for (int l = 1; l <= pearls[k][0]; ++l)
				{
					if (pearls[k][l] == i) count++;
				}
			}
			if (count >= 2)
			{
				sign = 1;
				break;
			}
		}
		if (sign == 1) sum += 1;
	}
	cout << sum << endl;
	return 0;
}
