#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> apples;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		apples.push_back(temp);
	}
	sort(apples.begin(), apples.end());
	int count = 0;
	while (apples[0] != apples[n - 1]) 
	{
		if(apples[n - 1] - apples[0] <= 2)
		{
			return -1;
		}
		apples[0] += 2;
		apples[n - 1] -= 2;
		sort(apples.begin(), apples.end());
		count++;
	}
	cout << count << endl;
	return 0;
}
