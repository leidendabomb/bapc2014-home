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

bool maze[200][200];

enum dir_t
{
	EAST = 0,
	SOUTH = 1,
	WEST = 2,
	NORTH = 3
};

dir_t direction_from_step(dir_t direction, const char &step)
{
	switch(step)
	{
		case 'F':
			break;
		case 'L':
			direction = (dir_t) ((direction + 3)%4);
			break;
		case 'R':
			direction = (dir_t) ((direction + 1)%4);
			break;
		case 'B':
			direction = (dir_t) ((direction + 2)%4);
			break;
	}

	return direction;
}

int main()
{
	int numEntries = 0;
	cin >> numEntries;
	cin.ignore();
	cout << numEntries << endl;

	while (numEntries--)
	{
		string path;
		int x = 100, y = 100;
		int xmin = 100, ymin = 100;
		int xmax = 100, ymax = 100;
		dir_t direction = EAST;

		memset(maze, 0, sizeof(maze));
		getline(cin, path);

		// True is open
		maze[x][y] = true;

		for (auto &step : path)
		{
			direction = direction_from_step(direction, step);

			switch(direction)
			{
			case EAST:
				x += 1;
				break;
			case SOUTH:
				y += 1;
				break;
			case WEST:
				x -= 1;
				break;
			case NORTH:
				y -= 1;
				break;
			}

			if (x < xmin)
				xmin = x;
			if (x > xmax)
				xmax = x;
			if (y < ymin)
				ymin = y;
			if (y > ymax)
				ymax = y;

			maze[x][y] = true;
		}

		dir_t initial_direction = direction_from_step(EAST, path[0]);

		switch(initial_direction)
		{
		case EAST:
			--ymin;
			++ymax;
			++xmax;
			break;
		case SOUTH:
			--xmin;
			++xmax;
			++ymax;
			break;
		case WEST:
			--ymin;
			++ymax;
			--xmin;
			break;
		case NORTH:
			--xmin;
			++xmax;
			--ymin;
			break;
		}

		cout << ymax-ymin+1 << " " << xmax-xmin+1 << endl;

		for (int y = ymin; y <= ymax; y++)
		{
			for (int x = xmin; x <= xmax; x++)
			{
				cout << (maze[x][y] ? '.' : '#');
			}
			cout << endl;
		}
	}

	return 0;
}

/*
dabomb@dabomb:~/a$ ./J < ~/sampledata/J.in 
(101,100)
(102,100)
(102,101)
(102,100)
(101,100)
(100,100)
4 4
####
...#
##.#
####
(101,100)
(102,100)
(102,101)
(102,102)
(101,102)
(102,102)
(102,103)
(102,104)
(102,103)
(102,102)
(103,102)
(102,102)
(102,101)
(102,100)
(101,100)
(100,100)
7 5
#####
...##
##.##
#...#
##.##
##.##
#####
(101,100)
(101,101)
(102,101)
(103,101)
(104,101)
(105,101)
(105,101)
(105,102)
(104,102)
(103,102)
(102,102)
(101,102)
(101,101)
(101,100)
(101,99)
(101,98)
(102,98)
(103,98)
(103,99)
(103,100)
(103,99)
(104,99)
(105,99)
(105,99)
(105,100)
(104,100)
(103,100)
(103,99)
(102,99)
(101,99)
(101,100)
(101,101)
(101,102)
(100,102)
7 7
#######
#...###
#.....#
..#...#
#.....#
......#
#######
*/
