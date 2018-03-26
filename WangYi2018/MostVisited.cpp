#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mostVisited(vector<int>& parents, int n, int L)
{
	int mostVis = 0;
	vector<int> dp(n, 0); // 注意数组的一种初始化方式，全部初始化为0.到达n号城市时游历的城市数目
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[i] = dp[parents[i - 1]] + 1; //因为parents[i-1]指向i号城市，所以
		mostVis = max(dp[i], mostVis); // 更新最长路径长度，这样就不用单独循环遍历了
	}
	if (mostVis > L) // 如果最长路径大于步数L，直接在最长路径上走L步好了
	{
		return L + 1;
	}
	else
	{
		int len = mostVis + (L + 1 - mostVis) / 2; // 多余的步数先走短的分支，然后再把最长的走完。但是如何保证存在这样的分支且不与最长路径重叠呢？
		return len;
	}
}

int main()
{
	int n, L, temp;
	cin >> n;
	cin	>> L;
	vector<int> parents;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		parents.push_back(temp);
	}
	cout << mostVisited(parents, n, L) << endl;
	return 0;
}
