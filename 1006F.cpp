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
int mat[21][21];
int n, m, k;
int mid, cnt = 0, ans = 0;
map<int, int> g[21][21];
void solve(int r, int c, int x, int count)
{
	// taking xor till the diagonal element including the diagonal element
	x = x ^ mat[r][c];
	if (count == mid)
	{
		g[r][c][x]++;
		return ;
	}
	if (r < n - 1)
		solve(r + 1, c, x, count + 1);
	if (c < m - 1)
		solve(r, c + 1, x, count + 1);
}
void solverev(int r, int c, int x, int count)
{
	if (count == (n + m - 2 - mid))
	{
		ans += g[r][c][k ^ x];
		return ;
	}
	x = x ^ mat[r][c];
	if (r > 0)
		solverev(r - 1, c , x, count + 1);
	if (c > 0)
		solverev(r , c - 1, x, count + 1);
}
int32_t main()
{
	fast();
	cin >> n >> m >> k;
	mid = (n + m - 2) / 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	solve(0, 0, 0, 0);
	solverev(n - 1, m - 1, 0, 0);
	cout << ans << endl;
	return 0;
}