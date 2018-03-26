/*直接运用STL里的set来做，比较简单*/
#include<iostream>
#include<iterator>
#include<set>
 
using namespace std;
int main(void)
{
    int n, m;
    while (cin >> n, cin >> m)
    {
        set<int> st;
        int num;
        for (int i = 0; i < n + m; ++i)
        {
            cin >> num;
            st.insert(num);
        }
        int size = st.size();
        set<int>::iterator it = st.begin();
        for (int i = 0; i < size - 1; ++i)
        {
            cout << *it << " ";
            ++it;
        }
        cout << *it << endl;
    }
    return 0;
}
