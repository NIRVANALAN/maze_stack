#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
int maze[100][100];
auto w = 0;
auto h = 0;
auto x = 0;
auto y = 0;

void print_maze()
{
	cout << "your maze:" << endl;
	for (int i = 0; i <= w + 1; ++i)
	{
		for (int j = 0; j <= h + 1; j++)
		{
			cout << maze[i][j] << " ";;
		}
		cout << endl;
	}
}

void initial_maze()
{
	cout << "maze width:";
	cin >> w;
	cout << "maze height";
	cin >> h;
	char q = 'n';
	for (int i = 0; i <= w + 1; ++i)
	{
		maze[0][i] = maze[h + 1][i] = 1;
	}
	for (int i = 0; i <= h + 1; ++i)
	{
		maze[i][0] = maze[i][w + 1] = 1;
	}
	while (true)
	{
		cout << "input maze wall coordinate, like 1 2 which means (1,2) is wall, input 0 if over" << endl;
		cin >> x;
		if (x == 0)
			break;
		cin >> y;
		maze[x][y] = 1;
	}
}

bool Solution()
{
	int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	stack<pair<int, int>> s;
	stack<pair<int, int>> track;
	x = y = 1;
	pair<int, int> pos = {x, y};
	s.push(pos);
	while (true)
	{
		if (pos.first == w && pos.second == h)
		{
			cout << "finish" << endl;
			stack <pair<int, int>> tmp;
			while(!s.empty())
			{
				tmp.push(s.top());
				s.pop();
			}
			while (!tmp.empty())
			{
				// pos = s.top;
				cout <<"("<< tmp.top().first << "," << tmp.top().second <<")"<< "-";
				tmp.pop();
			}
			cout << "Destination arrived~"<<endl;
			return true;
		}
		for (int i = 0; i < 4; ++i)
		{
			if (abs(maze[pos.first + move[i][0]][pos.second + move[i][1]]) != 1)
			{
				pos.first += move[i][0];
				pos.second += move[i][1];
				s.push(pos);
				track.push(pair<int,int>(move[i][0],move[i][1]));
				maze[pos.first][pos.second] = -1;
				break;
			}
			if (i==3)
			{
				pos.first -= track.top().first;
				pos.second -= track.top().second;
				track.pop();
				s.pop();
				// return false;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	initial_maze();
	print_maze();
	Solution();
	system("pause");
	return 0;
}
// test input
// 4 4 1 2 1 3 2 2 3 4 4 1 4 2 0
/* output:
your maze:
1 1 1 1 1 1
1 0 1 1 0 1
1 0 1 0 0 1
1 0 0 0 1 1
1 1 1 0 0 1
1 1 1 1 1 1
finish
(1,1)-(2,1)-(3,1)-(3,2)-(3,3)-(4,3)-(4,4)-Destination arrived~
 */

// ppt input
// 8 8 1 3 1 7 2 3 2 7 3 5 3 6 4 2 4 3 4 4 5 4 6 2 6 6 7 3 7 4 7 3 7 7 7 6 8 1 0
//output:
// your maze :
// 1 1 1 1 1 1 1 1 1 1
// 1 0 0 1 0 0 0 1 0 1
// 1 0 0 1 0 0 0 1 0 1
// 1 0 0 0 0 1 1 0 0 1
// 1 0 1 1 1 0 0 0 0 1
// 1 0 0 0 1 0 0 0 0 1
// 1 0 1 0 0 0 1 0 0 1
// 1 0 0 1 1 0 1 1 0 1
// 1 1 0 0 0 0 0 0 0 1
// 1 1 1 1 1 1 1 1 1 1
// finish
// (1, 1) - (1, 2) - (2, 2) - (3, 2) - (3, 1) - (4, 1) - (5, 1) - (5, 2) - (5, 3) - (6, 3) - (6, 4) - (6, 5) - (7, 5) - (8, 5) - (8, 6) - (8, 7) - (8, 8) -Destination arrived~
