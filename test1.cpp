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
#define endl             "\n"
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int n, m;
vector<vector<int> > g;
vector<pair<int, int> > p;
set<pii> st;
int dis(pair<int, int> a, pair<int, int> b)
{
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}
pii next_nearest(pii node)
{
	pii res;
	int min_distance = inf;
	for (auto it : p)
	{
		if (st.count(it) == 0 and dis(it, node) < min_distance)
		{
			min_distance = dis(it, node);
			res = it;
		}
	}
	return res;
}
int solve()
{
	cin >> n >> m;
	g.resize(n, vector<int> (m));
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> g[i][j];
			ans += g[i][j];
			if (g[i][j])
				p.pb({i, j});
		}
	}
	if (p.size() <= 1) return ans;

	st.insert(p[0]);
	pii one = p[0];
	pii two = next_nearest(p[0]);
	st.insert(two);
	ans += dis(one, two) * 2;

	int k = p.size() - 2;
	cout << g[one.fi][one.se] << endl;
	cout << g[two.fi][two.se] << endl;
	while (k--)
	{
		pii next_one = next_nearest(one);
		pii next_two = next_nearest(two);
		if (dis(one, next_one) < dis(two, next_two))
		{
			ans += dis(one, next_one) * 2;
			st.insert(next_one);
			cout << "one: " << g[next_one.fi][next_one.se] << endl;
			one = next_one;
		}
		else
		{
			ans += dis(two, next_two) * 2;
			st.insert(next_two);
			cout << "two: " << g[next_two.fi][next_two.se] << endl;
			two = next_two;
		}
	}
	return ans;
}
int32_t main()
{
	fast();
	int t = solve();
	cout << t << endl;
	int ans = t / 8;
	if (t % 8)
		ans++;
	cout << ans << endl;
	return 0;
}