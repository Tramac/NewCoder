#include <iostream>
#include <stack>

using namespace std;
void MagicCoin(int n)
{
	if (n <= 0)
		return;
	stack<int> s;
	while (n > 0)
	{
		if (n % 2 == 0)
		{
			s.push(2);
			n = (n - 2) / 2;
		}
		if (n % 2 == 1)
		{
			s.push(1);
			n = (n - 1) / 2;
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return;
}

int main()
{
	int n;
	cin >> n;
	MagicCoin(n);
	return 0;
}
