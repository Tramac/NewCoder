#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare1(int a, int b)
{
	return a > b;
}

bool compare2(vector<int> v1, vector<int> v2)
{
	return v1[0] > v2[0];
}

bool compare3(vector<int> v1, vector<int> v2)
{
	return v1[2] < v2[2];
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> candies;
	int temp;
	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		candies.push_back(temp);
	}
	sort(candies.begin(), candies.end(), compare1);
	vector<vector<int>> bears;
	bears.resize(n);
	int x, y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		bears[i].push_back(x);
		bears[i].push_back(y);
		bears[i].push_back(i);
	}
	sort(bears.begin(), bears.end(), compare2);
	int n1 = 0;
	while (n1 < n)
	{
		int k = 0;
		while (candies.size() > 0 && k < candies.size())
		{
			if (bears[n1][1] - candies[k] >= 0)
			{
				bears[n1][1] -= candies[k];
				candies.erase(candies.begin() + k);
			}
			else
				k++;
		}
		n1++;
	}
	sort(bears.begin(), bears.end(), compare3);
	for (int i = 0; i < n; ++i)
		cout << bears[i][1] << endl;
	return 0;
}
