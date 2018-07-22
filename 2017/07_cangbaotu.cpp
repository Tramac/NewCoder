#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	int i = 0, j = 0;
	while(t[j] != '\0')
	{
		while(s[i] != t[j] && s[i] != '\0')
		{
			i++;
		}
		if(s[i] == '\0')
		{
			cout << "No" << endl;
			return 0;
		}
		else
		{
			i++;
			j++;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
