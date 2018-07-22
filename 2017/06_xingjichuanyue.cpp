#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	long long h;
	cin >> h;
	long long x = (sqrt(1 + 4 * h) - 1) / 2;
	cout << x << endl;
	return 0;
}
