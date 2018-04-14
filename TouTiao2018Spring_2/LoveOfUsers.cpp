#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, temp;
	cin >> n;
	int *Loves = new int[n];
	for (int i = 0; i < n; ++i)
	{
		//cin >> temp;
		//Loves.push_back(temp);
		cin >> Loves[i];
	}
	int q, l, r, k, count;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		count = 0;
		cin >> l >> r >> k;
		for (int j = l - 1; j <= r - 1; ++j)
		{
			if (Loves[j] == k) count++;
		}
		cout << count << endl;
	}
	return 0;
}
