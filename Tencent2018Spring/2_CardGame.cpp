#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> cards;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		cards.push_back(temp);
	}
	sort(cards.begin(), cards.end());
	int x1 = 0, x2 = 0;

	for (int i = n - 1; i >= 0; i -= 2)
	{
		x1 += cards[i];
	}
	for (int i = n - 2; i >= 0; i -= 2)
	{
		x2 += cards[i];
	}
	cout << x1 - x2 << endl;
	return 0;
}
