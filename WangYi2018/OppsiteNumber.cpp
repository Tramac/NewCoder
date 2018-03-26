#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int StrToNum(string s)
{
	stringstream ss;
	int n;
	ss << s;
	ss >> n;
	return n;
}

void OppositeNumber(string s)
{
	int num = StrToNum(s);
	reverse(s.begin(), s.end());
	int reverseNum = StrToNum(s);
	cout << num + reverseNum << endl;
	return;
}

int main()
{
	string s;
	cin >> s;
	OppositeNumber(s);
	return 0;
}
