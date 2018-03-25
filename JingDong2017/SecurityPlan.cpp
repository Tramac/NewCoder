#include <iostream>
#include <vector>

using namespace std;

void countNum(vector<int> high, int n)
{
	int count = 0;
	int min;
	for (int start = 0; start < n - 1; start++)
	{
		for (int end = start + 1; end < n; end++)
		{
			int flag1 = 1;
			int flag2 = 1;
			int flag3 = 1;
			min = high[start] < high[end] ? high[start] : high[end];
			for (int i = start + 1; i < end; i++)
			{
				if (high[i] > min)
					flag1 = 0;
			}
			if (flag1 == 0)
			{
				for (int i = 0; i < start; i++)
				{
					if (high[i] > min)
						flag2 = 0;
				}
				for (int i = end + 1; i < n; i++)
				{
					if (high[i] > min)
						flag3 = 0;
				}
			}
			count += (flag1 || (flag2 && flag3));
		}
	}
	cout << count << endl;
	return;
}

int main()
{
	int n;
	cin >> n;
	int temp;
	vector<int> high;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		high.push_back(temp);
	}
	countNum(high, n);
	return 0;
}
