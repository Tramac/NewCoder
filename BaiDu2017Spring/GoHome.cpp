#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, temp;
	cin >> N;
	vector<int> locations;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		locations.push_back(temp);
	}
	int sumLength = 0;
	int decreceLength = 0;
	int currentLength;
	int nextLength;
	for (int i = 1; i < N - 1; ++i)
	{
		sumLength += abs(locations[i] - locations[i - 1]);
		currentLength = abs(locations[i] - locations[i - 1]) + abs(locations[i + 1] - locations[i]);
		nextLength = abs(locations[i + 1] - locations[i - 1]);
		if (decreceLength < (currentLength - nextLength))
		{
			decreceLength = currentLength - nextLength;
		}
	}
	sumLength += abs(locations[N - 1] - locations[N - 2]);
	cout << sumLength - decreceLength << endl;
	return 0;
}
