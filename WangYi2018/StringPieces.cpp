#include <iostream>
#include <string>

using namespace std;

void StringPieces(string s)
{
	char currentChar = 'A';
	float PiecesNum = 0.0; 
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != currentChar)
		{
			PiecesNum++;
			currentChar = s[i];
		}
	}
	printf("%.2f", s.size() / PiecesNum);
	return;
}

int main()
{
	string s;
	cin >> s;
	StringPieces(s);
	return 0;
}
