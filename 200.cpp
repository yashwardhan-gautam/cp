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

vector<int> X{1, 0, -1, 0};
vector<int> Y{0, -1, 0, 1};
bool valid(int new_x, int new_y, vector<vector<char> > grid)
{
	return (new_x >= 0 and new_x<grid.size() and new_y >= 0 and new_y < grid[0].size());
}
void dfs(int x, int y, vector<vector<char> > grid, vector<vector<int> > &vis)
{
	vis[x][y] = 1;
	for (int i = 0; i <= 3; i++)
	{
		int new_x = x + X[i];  int new_y = y + Y[i];
		if (valid(new_x, new_y, grid) and grid[new_x][new_y] == '1' and !vis[new_x][new_y])
			dfs(new_x, new_y, grid, vis);
	}
}
int numIslands(vector<vector<char>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int> > vis(n, vector<int> (m, 0));
	int count = 0;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] == '1' and !vis[i][j])
			{
				cout << i << " " << j << endl << endl;
				count++;
				dfs(i, j, grid, vis);
			}
		}
	}
	return count;
}

int32_t main()
{
	fast();
	int n, m;	cin >> n >> m;
	vector<vector<char> > grid(n, vector<char> (m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];
	cout << numIslands(grid) << endl;
	return 0;
}