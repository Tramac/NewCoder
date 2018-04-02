#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		int length = str.size();
		for (int i = 0; i < length - 1; ++i)
		{
			for (int j = 0; j < length - 1 - i; ++j)
			{
				if ((str[j] >= 'A' && str[j] <= 'Z') && (str[j + 1] >= 'a' && str[j + 1] <= 'z'))
				{
					char temp = str[j];
					str[j] = str[j + 1];
					str[j + 1] = temp;
				}
			}
		}
		cout << str << endl;
	}
	return 0;
}
