#include <iostream>
#include <vector>

using namespace std;

int countNum(vector<int>& nums)
{
	int count = 0;
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		for (int j = i + 1; j < nums.size(); ++j)
		{
			if(nums[i] < nums[j])
			    count++;
		}
	}
	return count;
}

bool changeturn(vector<int>& nums)
{
    int pos1, pos2, pos3;
    pos1 = nums.size() - 1;
    while (pos1 > 0)
    {
        pos2 = pos1;
        pos1--;
        if (nums[pos1] < nums[pos2])
        {
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                if (nums[i] > nums[pos1])
                {
                    pos3 = i;
                    break;
                }
            }
            int tp = nums[pos1];
            nums[pos1] = nums[pos3];
            nums[pos3] = tp;
            for (int i = pos2; i < (nums.size() + pos2) / 2; i++)
            {
                tp = nums[i];
                nums[i] = nums[nums.size() - i + pos1];
                nums[nums.size() - i + pos1] = tp;
            }
            return true;
        }
    }
    return false;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> nums;
	vector<int> pos = vector<int>(n, 0);
	vector<int> zeropos;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
		if(temp != 0)
		{
			pos[temp - 1] = temp;
		}
		else
		{
			zeropos.push_back(i);
		}
	}
	vector<int> array;
	for (int i = 0; i < n; ++i)
	{
		if(pos[i] == 0)
			array.push_back(i + 1);
	}
	int res = 0;
	do
	{
		for (int m = 0; m < array.size(); ++m)
		{
			nums[zeropos[m]] = array[m];
		}
		if(countNum(nums) == k)
				res++;
	} while (changeturn(array));
	cout << res << endl;
	return 0;
}
