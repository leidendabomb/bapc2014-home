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

#define NORTH_SOUTH 2
#define EAST_WEST 1

using namespace std;

struct Intersection
{
	int conns[4]; // n, e, s, w
} graph[100001];

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();

	while (numEntries--)
	{
		int n, g;
		cin >> n >> g;
		--g;

		memset(graph, 0, sizeof(graph));

		int todo[100001];

		for (int i = 0; i < n; i++)
		{
			auto &node = graph[i];
			cin >> node.conns[0] >> node.conns[1] >> node.conns[2] >> node.conns[3];
			for (int j = 0; j < 4; j++)
				node.conns[j]--;
			if (i != g)
				todo[i] = NORTH_SOUTH | EAST_WEST;
		}

		int amountOfWalks = 0;
		for (int i = 0; i < n;)
		{
			if (todo[i] == 0)
			{
				++i;
				continue;
			}

			++amountOfWalks;
			int cur = i;
			//cerr << "Walking for " << cur << endl;

			bool foundGoal = false;

			auto &node = graph[cur];
			int walk;
			int previous = cur;
			int enddir;
			if (todo[i] & NORTH_SOUTH)
			{
				todo[i] ^= NORTH_SOUTH;
				walk = node.conns[0];
				enddir = 0;
			}
			else
			{
				todo[i] ^= EAST_WEST;
				walk = node.conns[1];
				enddir = 1;
			}

			while (true)
			{
				//cerr << "Walking through " << walk << " waiting for " << node.conns[enddir] << endl;
				int newdir = 1;
				for (int i = 0; i < 3; i++)
					if (graph[walk].conns[i] == previous)
					{
						newdir = (i+2)%4;
					   	break;
					}

				if (walk == g && !foundGoal)
				{
					foundGoal = true;
					--amountOfWalks;
				}

				if (walk == cur && newdir == enddir)
					break;

				if (newdir % 2)
				{
					todo[walk] &= ~EAST_WEST;
					//cerr << "Walked through " << walk << " in e/w direction" << endl;
				}
				else
				{
					todo[walk] &= ~NORTH_SOUTH;
					//cerr << "Walked through " << walk << " in n/s direction" << endl;
				}

				previous = walk;
				walk = graph[walk].conns[newdir];
			}

			if (!todo[i])
				++i;
		}

		cout << amountOfWalks << endl;
	}

	return 0;
}
