#include <iostream>
#include <string>
#include <set>
using namespace std;

bool IsValid(const string& s)
{
	int flag = 1;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == '(')
			flag++;
		else 
			flag--;
		if (flag < 0)
			return false;
	}
	return true;
}

void LongestCommonSubsequence(const string& s)
{
	set<string> sequece; // 创建一个容器，用于保存新生成的序列
	for (int i = 1; i < s.size() - 1; ++i)
	{
		string temp(s);
		temp.erase(i, 1); // erase(i, n), 删除位置i处开始的n个字符
		for (int j = 1; j < s.size(); ++j)
		{
			string temp2(temp);
			if (s[j] == s[i]) continue;
			temp2.insert(j, 1, s[i]);
			if (IsValid(temp2))
				sequece.insert(temp2);
		}
	}
	cout << sequece.size() << endl;
	return;
}

int main()
{
	string s;
	cin >> s;
	LongestCommonSubsequence(s);
	return 0;
}
