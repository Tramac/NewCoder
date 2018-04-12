#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct Coord
{
	char rgb;
	int x, y, z;
};

float GetArea(Coord c1, Coord c2, Coord c3)
{
	double a = sqrt(double((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y) + (c1.z - c2.z) * (c1.z - c2.z)));
	double b = sqrt(double((c1.x - c3.x) * (c1.x - c3.x) + (c1.y - c3.y) * (c1.y - c3.y) + (c1.z - c3.z) * (c1.z - c3.z)));
	double c = sqrt(double((c2.x - c3.x) * (c2.x - c3.x) + (c2.y - c3.y) * (c2.y - c3.y) + (c2.z - c3.z) * (c2.z - c3.z)));
	if ((a + b) <= c || (a + c) <= b || (b + c) < a) return -1;
	double p = (a + b + c)/2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
	int N;
	cin >> N;
	vector<Coord> coords;
	Coord coord;
	for (int i = 0; i < N; ++i)
	{
		cin >> coord.rgb >> coord.x >> coord.y >> coord.z;
		coords.push_back(coord);
	}
	double maxArea = 0;
	double currentArea;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			for (int k = j + 1; k < N; ++k)
			{
				if ((coords[i].rgb == coords[j].rgb && coords[i].rgb == coords[k].rgb) || (coords[i].rgb != coords[j].rgb && coords[i].rgb != coords[k].rgb && coords[j].rgb != coords[k].rgb))
				{
					currentArea = GetArea(coords[i], coords[j], coords[k]);
					maxArea = maxArea > currentArea ? maxArea : currentArea;
				}
				else
					continue;
			}
		}
	}
	printf("%.5lf", maxArea);
	return 0;
}
