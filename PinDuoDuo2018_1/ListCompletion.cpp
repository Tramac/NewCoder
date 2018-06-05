#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int offset, n, l1, l2;
	int start1, end1, start2, end2;
	while (cin >> offset >> n >> l1 >> l2)
	{
		if (offset <= l1)
		{
			start1 = offset;
			if (offset + n <= l1)
			{
				end1 = offset + n;
				start2 = 0;
				end2 = 0;
			}
			else if ((offset + n) <= (l1 + l2))
			{
				end1 = l1;
				start2 = 0;
				end2 = n - l1 + offset;
			}
			else
			{
				end1 = l1;
				start2 = 0;
				end2 = l2;
			}
		}
		else if (offset > l1 && offset <= l1 + l2)
		{
			start1 = l1;
			end1 = l1;
			start2 = offset - l1;
			if (n + offset <= l1 + l2)
				end2 = offset - l1 + n;
			else
				end2 = l2;
		}
		else
		{
			start1 = l1;
			end1 = l1;
			start2 = l2;
			end2 = l2;
		}
		cout << start1 << ' ' << end1 << ' ' << start2 << ' ' << end2 << endl;
	}
	return 0;
}
