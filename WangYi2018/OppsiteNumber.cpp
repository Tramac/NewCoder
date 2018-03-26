#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
//直接将数字反转
//int reverse(int n) {
//    int res = 0;
//    while (n) {
//        res = res * 10 + n % 10;
//        n /= 10;
//    }
//    return res;
//}

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
