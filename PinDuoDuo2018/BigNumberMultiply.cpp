#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 10;


void solve(int* a, int* b, int length1, int length2)
{
	int result[N];
	for (int i = 0; i < N; ++i)
		result[i] = 0;
	for (int i = 0; i < length1; ++i)
	{
		for (int j = 0; j < length2; ++j)
		{
			int k = i + j;
			result[k] += a[i] * b[j];
			while (result[k] > 9)
			{
				result[k + 1] += result[k] / 10;
				result[k] %= 10;
				k++;
			}
		}
	}
	int length = length1 + length2 - 1;
	while (result[length] == 0 && length > 0)
		length--;
	for (int i = length; i >= 0; --i)
		cout << result[i];
	cout << endl;
	return;
}

int main()
{
	string s1, s2;
	int a[N], b[N];
	while (cin >> s1 >> s2)
	{
		int length1 = s1.size(), length2 = s2.size();
		for (int i = 0; i < length1; ++i)
			a[i] = (int)(s1[length1 - i - 1] - '0');
		for (int i = 0; i < length2; ++i)
			b[i] = (int)(s2[length2 - i - 1] - '0');

		solve(a, b, length1, length2);
	}
	return 0;
}
