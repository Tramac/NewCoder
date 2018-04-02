#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int dp[MAX][MAX]; //为什么定义到函数中会出错

int BiggestComonSub(string str1, string str2)
{
	int length1 = str1.size();
	int length2 = str2.size();
	for (int i = 0; i < length1; ++i)
		dp[i][0] = 0;
	for (int i = 0; i < length2; ++i)
		dp[0][i] = 0;
	for (int i = 1; i <= length1; ++i)
	{
		for (int j = 1; j <= length2; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[length1][length2];
}

int main()
{
	string str1;
	while (cin >> str1)
	{
		int length = str1.size();
		string str2 = str1;
		reverse(str2.begin(), str2.end());

		int big = BiggestComonSub(str1, str2);
		cout << length - big << endl;
	}
	return 0;
}
