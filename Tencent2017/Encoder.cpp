#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int result = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (i == 0)
		{
			result += (s[i] - 'a')*(25 * 25 * 25 + 25 * 25 + 25 + 1);
		}
		else if (i == 1)
		{
			result += (s[i] - 'a')*(25 * 25 + 25 + 1) + 1;
		}
		else if (i == 2)
		{
			result += (s[i] - 'a')*(25 + 1) + 1;
		}
		else
		{
			result += (s[i] - 'a') + 1;
		}
	}
	cout << result << endl;
	return 0;
}
