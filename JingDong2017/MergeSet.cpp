#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MergeSet(vector<int> data1, vector<int> data2, int start1, int start2, int behind)
{
	if (start1 >= data1.size())
	{
		for (int i = start2; i < data2.size() - 1; ++i)
		{
			if (data2[i] != behind)
			{
				cout << data2[i] << ' ';
				behind = data2[i];
			}
		}
		if (data2[data2.size() - 1] != behind)
		{
			cout << data2[data2.size() - 1] << endl;
		}
		return;
	}
	if (start2 >= data2.size())
	{
		for (int i = start1; i < data1.size() - 1; ++i)
		{
			if (data1[i] != behind)
			{
				cout << data1[i] << ' ';
				behind = data1[i];
			}
		}
		if (data1[data1.size() - 1] != behind)
		{
			cout << data1[data1.size() - 1] << endl;
		}
		return;
	}
	while (data1[start1] == behind)
		start1++;
	while (data2[start2] == behind)
		start2++;
	if (data1[start1] <= data2[start2])
	{
		cout << data1[start1] << ' ';
		behind = data1[start1];
		MergeSet(data1, data2, start1 + 1, start2, behind);
	}
	else
	{
		cout << data2[start2] << ' ';
		behind = data2[start2];
		MergeSet(data1, data2, start1, start2 + 1, behind);
	}
	return;
}

int main()
{
	int n, m, temp;
	cin >> n;
	cin >> m;
	vector<int> data1;
	vector<int> data2;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		data1.push_back(temp);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		data2.push_back(temp);
	}
	sort(data1.begin(), data1.end());
	sort(data2.begin(), data2.end());
	MergeSet(data1, data2, 0, 0, 0);
	return 0;
}
