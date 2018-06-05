#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, x, y;
	cin >> n;
	vector<vector<int>> coords;
	coords.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		coords[i].push_back(x);
		coords[i].push_back(y);
	}
	int count = 0;
	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = i + 1; j < n - 1; ++j)
		{
			for (int k = j + 1; k < n; ++k)
			{
				int y1 = coords[i][1] - coords[j][1];
				int y2 = coords[i][0] - coords[j][0];
				int x1 = coords[i][1] - coords[k][1];
				int x2 = coords[i][0] - coords[k][0];
				if (y1 * x2 != y2 * x1)
					count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
