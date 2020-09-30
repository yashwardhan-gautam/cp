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
int n, m, r, c, x, y;
vector<string> v;
int dx[] = {0, 0, 1, -1};
int dy[] = { -1, 1, 0, 0};
int cost[] = {1, 0, 0, 0};
bool valid(int a, int b)
{
	return (a >= 0 and a<n and b >= 0 and b < m and v[a][b] == '.');
}
void solve()
{
	int left[n][m];
	memset(left, -1, sizeof(left));
	left[r][c] = 0;
	deque<pii> q;
	q.push_front({r, c});
	while (!q.empty())
	{
		pii curr = q.front();
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int nx = curr.fi + dx[i];
			int ny = curr.se + dy[i];
			if (valid(nx, ny) and (left[nx][ny] == -1 or left[nx][ny] > left[curr.fi][curr.se] + cost[i]))
			{
				left[nx][ny] = left[curr.fi][curr.se] + cost[i];
				if (cost[i] == 0)
					q.push_front({nx, ny});
				else
					q.push_back({nx, ny});
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (left[i][j] != -1)
			{
				int l = left[i][j];
				int r = l + j - c;
				//cout << i << " " << j << " " << left[i][j] << " " << right << endl;
				if (l >= 0 and r >= 0 and l <= x and r <= y)
					ans++;
			}
		}
	}
	cout << ans << endl;
}
int32_t main()
{
	fast();
	cin >> n >> m >> r >> c >> x >> y;
	r--, c--;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	solve();
	return 0;
}