#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, temp;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	vector<int> arr_s = arr;
	sort(arr_s.begin(), arr_s.end());
	int count = 0;
	int start = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == arr_s[start])
		{
			count++;
			start++;
		}
	}
	cout << N - count << endl;
	return 0;
}
