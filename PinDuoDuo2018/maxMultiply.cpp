#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n;
	long long temp;
	cin >> n;
	vector<long long> A;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		A.push_back(temp);
	}
	long long min1 = 1;
	long long min2 = 1;
	long long max1 = 1;
	long long max2 = 1;
	long long max3 = 1;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] < min1)
		{
			min2 = min1;
			min1 = A[i];
		}
		else if (A[i] < min2 && A[i] > min1)
			min2 = A[i];
		else if (A[i] > max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = A[i];
		}
		else if (A[i] > max2)
		{
			max3 = max2;
			max2 = A[i];
		}
		else if (A[i] > max3)
			max3 = A[i];
	}
	long long result1 = min1 * min2 * max1;
	long long result2 = max1 * max2 * max3;
	long long result = (result1 > result2) ? result1 : result2;
	cout << result;
	return 0;
}
