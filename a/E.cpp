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

struct engineer_t {
	int64_t a,b,c;
	int64_t dist;
	bool eaten;
};

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();

	while (numEntries--)
	{
		int n;
		cin >> n;
		vector<engineer_t> engineers(n);
		for (int i = 0; i < n; i++) {
			auto &eng = engineers[i];
			cin >> eng.a >> eng.b >> eng.c;
			eng.dist = eng.a + eng.b + eng.c;
			eng.eaten = false;
		}

		sort(engineers.begin(), engineers.end(), [](const engineer_t& a, const engineer_t& b) {
				return a.dist < b.dist;
				});

		int numEngineers = n;
		for (auto &eng : engineers)
		{
			if (eng.eaten) continue;
			for (auto &eng2 : engineers)
			{
				if (&eng == &eng2 || eng2.eaten) continue;

				if (eng.a < eng2.a && eng.b < eng2.b && eng.c < eng2.c)
				{
					eng2.eaten = true;
					numEngineers--;
				}
			}
		}

		cout << numEngineers << endl;
		/*for (auto &eng : engineers)
			cerr << "(" << eng.a << "," << eng.b << "," << eng.c << ")" << endl;*/
	}

	return 0;
}
