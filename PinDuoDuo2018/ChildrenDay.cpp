#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, temp;
	cin >> n;
	vector<int> h;
	for (int x = 0; x < n; ++x)
	{
		cin >> temp;
		h.push_back(temp);
	}
	cin >> m;
	vector<int> w;
	for (int y = 0; y < m; ++y)
	{
		cin >> temp;
		w.push_back(temp);
	}
	sort(h.begin(), h.end());
	sort(w.begin(), w.end());
	int i = 0, j = 0, count = 0;
	while (i < m && j < n)
	{
		for (int k = j; k < n; ++k)
		{
			if (w[i] >= h[k])
			{
				count++;
				j = ++k;
				break;
			}
		}
		++i;
	}
	cout << count << endl;
	return 0;
}
