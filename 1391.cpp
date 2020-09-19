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

void dfs(int x, int y, vector<vector<bool> > vis, vector<vector<int> > &grid)
{
	if (vis[x][y])
		return ;
	vis[x][y] = 1;
	int up = 0, down = 0, left = 0, right = 0;
	if (grid[x][y] == 1)	     left = right = 1;
	else if (grid[x][y] == 2) up = down = 1;
	else if (grid[x][y] == 3) down = left = 1;
	else if (grid[x][y] == 4) down = right = 1;
	else if (grid[x][y] == 5) left = up = 1;
	else 									 right = up = 1;



}
bool hasValidPath(vector<vector<int>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int> > vis(0, vector<int> (m, 0));
	dfs(0, 0, visited, grid);
	return visited[n - 1][m - 1];
}
int32_t main()
{
	fast();
	int n, m; cin >> n >> m;
	vector<vector<int> > grid(n, vector<int> (m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];
	}
	cout << hasValidPath(grid);
	return 0;
}