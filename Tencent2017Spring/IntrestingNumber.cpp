#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Intresting(vector<int>& data, int n)
{
	sort(data.begin(), data.end());
	if (data[0] == data[n - 1])
	{
		cout << (n * (n - 1) / 2) << " " << (n * (n - 1) / 2) << endl;
		return;
	}
	int MIN = 0x7fffffff;
	int min_count = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (data[j] - data[i] < MIN)
			{
				MIN = data[j] - data[i];
				min_count = 1;
			}
			else if (data[j] - data[i] == MIN)
				min_count++;
			else
				break;
		}
	}
	int max_num = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (data[i] == data[n - 1])
			max_num++;
		else
			break;
	}
	int min_num = 0;
	for (int i = 0; i < n; ++i)
	{
		if (data[i] == data[0])
			min_num++;
		else
			break;
	}
	cout << min_count << " " << min_num*max_num << endl;
	return;
}

int main()
{
	int n, temp;
	vector<int> data;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		data.push_back(temp);
	}
	Intresting(data, n);
	return 0;
}
