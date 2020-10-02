#include<bits/stdc++.h>
using namespace std;
#define fi              first
#define se              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define endl		 	      "\n"
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int dist[25][25] = {0};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char a[25][25];
int col, row;
int src_x, src_y, des_x, des_y;
bool valid(int x, int y)
{
	return (x >= 0 and x<row and y >= 0 and y < col and a[x][y] != 'X');
}
void dijkstra()
{
	dist[src_x][src_y] = 0;
	queue<pii> q;
	q.push({src_x, src_y});
	while (!q.empty())
	{
		pii curr = q.front();	q.pop();
		int ci = curr.fi, cj = curr.se;
		for (int i = 0; i < 4; i++)
		{
			int ni = ci + dx[i], nj = cj + dy[i];
			if (valid(ni, nj) and (dist[ni][nj] > (dist[ci][cj] + (a[ci][cj] - '0'))))
			{
				dist[ni][nj] = dist[ci][cj] + (a[ci][cj] - '0');
				q.push({ni, nj});
			}
		}
	}
}
int32_t main()
{
	fast();
	cin >> col >> row;
	while (row and col)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				char ch;	cin >> ch;
				a[i][j] = ch;
				if (ch == 'S')
				{
					src_x = i, src_y = j;
					a[i][j] = '0';
				}
				else if (ch == 'D')
				{
					des_x = i, des_y = j;
					a[i][j] = '0';
				}
				dist[i][j] = 1e9;
			}
		}
		dijkstra();
		cout << dist[des_x][des_y] << endl;
		cin >> col >> row;
	}
	return 0;
}