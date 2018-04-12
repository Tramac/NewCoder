#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, x, y;
	cin >> n;
	vector<vector<int>> points;
	points.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		points.at(i).push_back(x);
		points.at(i).push_back(y);
	}
	sort(points.begin(), points.end());
	int flag;
	for (int i = 0; i < n; ++i)
	{
		flag = 1;
		for (int j = i + 1; j < n; ++j)
		{
			if (points[j][1] > points[i][1])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			cout << points[i][0] << " " << points[i][1] << endl;
	}
	return 0;
}
