#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
const int mod = 1e9 + 7;
int dp[1001][1001];
int main()
{
	int k, a, x, b, y;
	while (cin >> k >> a >> x >> b >> y)
	{
		vector<int> lens;
		for (int i = 0; i < x; ++i)
			lens.push_back(a);
		for (int i = 0; i < y; ++i)
			lens.push_back(b);
		
		for (int i = 0; i < x + y; ++i)
			dp[0][i] = 1;
		for (int i = 1; i <= k; ++i)
		{
			if (lens[0] != i)
				dp[i][0] = 0;
			else
				dp[i][0] = 1;
		}
		for (int i = 1; i <= k; ++i)
		{
			for (int j = 1; j < x + y; ++j)
			{
				if (i >= lens[j])
					dp[i][j] = (dp[i][j - 1] + dp[i - lens[j]][j - 1]) % mod;
				else
					dp[i][j] = dp[i][j - 1] % mod;
			}
		}
		cout << dp[k][x + y - 1] << endl;
	}
	return 0;
}
