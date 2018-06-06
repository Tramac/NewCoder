#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int n_current = n, m_current = m;
	while (m_current / (pow(2, n_current)) <= 1)
	{
		int start = 1, end = n_current;
		while (start < end)
		{
			int mid = (start + end) / 2;
			if (m_current / pow(2, mid) <= 1)
				end = mid - 1;
			else
				start = mid + 1;
		}
		int day1 = (start + end) / 2;
		n_current = day1 - 1;
		m_current = m - (n - n_current);
	}
	float sum = 0, x = 1;
	for (int i = 0; i < n_current; ++i)
	{
		sum += x;
		x /= 2;
	}
	if (m_current % 2 == 1)
		m_current--;
	int result = floor(m_current/ sum);
	cout << result << endl;
	return 0;
}
