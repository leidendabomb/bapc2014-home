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

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();

	while (numEntries--)
	{
		int n, t;
		cin >> n >> t;
		vector<int> buttons;
		for (int i = 0; i < n; i++) {
			int b;
			cin >> b;
			buttons.push_back(b);
		}
		sort(buttons.begin(), buttons.end());
		int nums[3601];
		int VEEL = 1000000;
		fill_n(nums, 3601, VEEL);
		queue<int> todo;
		for (int b : buttons) {
			if (b >= 0) {
				nums[b] = 1;
				todo.push(b);
			}
		}
		nums[0] = 0;

		while (!todo.empty()) {
			int cur = todo.front();
			todo.pop();
			for (int b : buttons) {
				int next = cur + b;
				if (next > 3600) next = 3600;
				if (next < 0) next = 0;
				if (nums[next] != VEEL) {
					continue;
				}
				nums[next] = nums[cur] + 1;
				if (next == t) {
					todo = queue<int>();
					break;
				}
				todo.push(next);
			}
		}

		int i;
		for (i = t; nums[i] == VEEL; i++) {
		}
		cout << nums[i] << " " << i - t << endl;
	}

	return 0;
}
