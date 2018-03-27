#include <iostream>
#include <vector>
using namespace std;

bool IsParallel(const int& x1, const int& x2, const int& x3, const int& y1, const int& y2, const int& y3)
{
	if ((x1 - x2)*(y1 - y3) == (x1 - x3)*(y1 - y2)) // || (x1 - x2)*(y1 - y3) == -(x1 - x3)*(y1 - y2)
		return true;
	return false;
}

bool IsVertical(const int& x1, const int& x2, const int& x3, const int& x4, const int& y1, const int& y2, const int& y3, const int& y4)
{
	if ((x1 - x2)*(x3 - x4) == -(y1 - y2)*(y3 - y4))
		return true;
	return false;
}

void ShootGame(const vector<int>& Xcoord, const vector<int>& Ycoord, int n)
{
	if (n <= 3)
	{
		cout << n << endl;
		return;
	}
	bool allSame = true;
	for (int i = 2; i < n; ++i)
	{
		if (!IsParallel(Xcoord[0], Xcoord[1], Xcoord[i], Ycoord[0], Ycoord[1], Ycoord[i]))
			allSame = false;
	}
	if (allSame)
	{
		cout << n << endl;
		return;
	}
	int count;
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if (k == i || k == j || IsParallel(Xcoord[i], Xcoord[j], Xcoord[k], Ycoord[i], Ycoord[j], Ycoord[k])) continue;
				count = 3;
				for (int m = 0; m < n; ++m)
				{
					if (m == i || m == j || m == k) continue;
					if (IsParallel(Xcoord[i], Xcoord[j], Xcoord[m], Ycoord[i], Ycoord[j], Ycoord[m]) || IsVertical(Xcoord[i], Xcoord[j], Xcoord[k], Xcoord[m], Ycoord[i], Ycoord[j], Ycoord[k], Ycoord[m]))
						count++;
				}
				max = max > count ? max : count;
			}
		}
	}
	cout << max << endl;
	return;
}

int main()
{
	int n, temp;
	vector<int> Xcoord;
	vector<int> Ycoord;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		Xcoord.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		Ycoord.push_back(temp);
	}
	ShootGame(Xcoord, Ycoord, n);
	return 0;
}
