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
#include <queue>

using namespace std;

int sink(vector<set<int>> ducks, vector<pair<int, int>> boats, map<int, int>& edgeSinks) {
	int sinks = 0;
	queue<pair<int, int>> edges;
	for (int i = 0; i < (int) ducks.size(); i++) {
		if (ducks[i].size() == 1) {
			edges.emplace(i, i);
		}
	}
	
	while (!edges.empty()) {
		auto cur = edges.front();
		auto curDuckInt = cur.second;
		auto& curDuck = ducks[curDuckInt];
		edges.pop();
		sinks++;
		edgeSinks[cur.first]++;

		int curBoatIndex = *curDuck.begin();
		if (curBoatIndex == -1) {
			// This is a spare boat, ignore.
			continue;
		}
		auto& boat = boats[curBoatIndex];
		int nextDuckIndex = boat.first == cur.second ? boat.second : boat.first;
		auto& nextDuck = ducks[nextDuckIndex];
		nextDuck.erase(nextDuck.find(curBoatIndex));
		if (nextDuck.size() == 1) {
			edges.emplace(cur.first, nextDuckIndex);
		}
	}

	return sinks;
}

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();

	while (numEntries--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		// Set of boats for every duck
		vector<set<int>> ducks(n);
		// Pair of ducks for every boat.
		vector<pair<int, int>> boats(m);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			boats[i].first = a;
			boats[i].second = b;
			ducks[a].insert(i);
			ducks[b].insert(i);
		}

		map<int, int> edgeSinks;
		sink(ducks, boats, edgeSinks);

		vector<pair<int, int>> worstEdges;
		for (auto& cur : edgeSinks) {
			worstEdges.push_back(make_pair(cur.second, cur.first));
		}
		sort(worstEdges.begin(), worstEdges.end(), greater<pair<int, int>>());
		for (int i = 0; i < k && i < (int) worstEdges.size(); i++) {
			ducks[worstEdges[i].second].insert(-1);
		}

		cout << sink(ducks, boats, edgeSinks) << endl;
	}

	return 0;
}
