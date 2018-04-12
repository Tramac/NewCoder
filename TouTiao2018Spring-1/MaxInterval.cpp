#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, temp;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	int Max = 0;
	int sum;
	for (int i = 0; i < n; i++)
	{
		sum = arr[i];
		int j = i - 1;
		while (j >= 0)
		{
			if (arr[j] >= arr[i])
			{
				sum += arr[j];
				j--;
			}
			else
				break;
		}
		int k = i + 1;
		while (k < n)
		{
			if (arr[k] >= arr[i])
			{
				sum += arr[k];
				k++;
			}
			else
				break;
		}
		Max = Max > (arr[i] * sum) ? Max : (arr[i] * sum);
	}
	cout << Max << endl;
	return 0;
}
