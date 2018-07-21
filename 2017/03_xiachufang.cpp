#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
	vector<string> materials;
	string s;
	while(cin >> s)
	{
		string material = "";
		int i = 0;
		while(s[i] != '\0')
		{
			if(s[i] == ' ')
			{
				materials.push_back(material);
				material = "";
			}
			else
			{
				material += s[i];
			}
			++i;
		}
		materials.push_back(material);
	}
	set<string> result;
	result.insert(materials.begin(), materials.end());
	int res = result.size();
	cout << res << endl;
	return 0;
}
