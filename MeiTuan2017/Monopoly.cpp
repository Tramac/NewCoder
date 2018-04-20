#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int f[6] = {1, 2, 4, 8, 16, 32};
    cout << f[n - 1] << endl;
    return 0;
}
