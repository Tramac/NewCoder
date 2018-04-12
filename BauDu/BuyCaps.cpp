#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
 
int main()
{
    int N;
    unsigned int temp;
    set<unsigned int > prices;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        prices.insert(temp);
    }
    if (prices.size() < 3)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        int count = 0;
        for (auto it = prices.begin(); it != prices.end(); it++)
        {
            count++;
            if (count == 3)
            {
                cout << *it << endl;
                return 0;
            }
        }
    }
}
