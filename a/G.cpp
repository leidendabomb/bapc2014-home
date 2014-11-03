// Team: :(){:|:&};: #dabomb
// 💩
#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <map>
#include <list>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();

	while (numEntries--)
	{
		int numGears;
		cin >> numGears;

		int maxGear = 0;
		double maxTorque = 0;
		for (int i = 0; i < numGears; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			double torque = (b*b)/(4.0*a)+c;
			if (torque > maxTorque)
			{
				maxTorque = torque;
				maxGear = i;
			}
		}

		cout << maxGear+1 << endl;
	}

	return 0;
}
