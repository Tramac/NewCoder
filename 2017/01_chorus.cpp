#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int>& students, int n, int k, int d)
{
	long long int res = 0;
	long long int fm[50][11], fn[50][11];
	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{	
			fm[i][j] = 0;
			fn[i][j] = 0;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if(j == 1)
			{
				fm[i][j] = students[i];
				fn[i][j] = students[i];
			}
			else
			{
				for (int m = 1; m <= d; ++m)
				{
					if((i - m) >= 0 && (i - m) < n)
					{
						fm[i][j] = max(fm[i][j], max(fm[i - m][j - 1] * students[i], fn[i - m][j - 1] * students[i]));
						fn[i][j] = min(fn[i][j], min(fm[i - m][j - 1] * students[i], fn[i - m][j - 1] * students[i]));
					}
				}
			}
		}
		res = max(res, fm[i][k]);
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<int> students;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		students.push_back(temp);
	}
	int k, d;
	cin >> k >> d;
	long long int res = maxProduct(students, n, k, d);
	cout << res << endl;
	return 0;
}
