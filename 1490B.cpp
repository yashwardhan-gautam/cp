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
void solve()
{
	int n;	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	vector<int> m[3];
	for (int i = 0; i < n; i++)
	{
		m[v[i] % 3].pb(v[i]);
	}
	queue<int> extra;
	int ans = 0;
	for (int i = 0; i < 6; i++)
	{
		int curr = i % 3;
		while (m[curr].size() > v.size() / 3)
		{
			int temp = m[curr][m[curr].size() - 1];
			m[curr].erase(m[curr].begin() + m[curr].size() - 1);
			extra.push(temp);
		}
		while (m[curr].size() < v.size() / 3 and !extra.empty())
		{
			int tp = extra.front();	extra.pop();
			int t = ((curr + 3) - tp % 3) % 3;
			ans += t;
			m[curr].pb(tp + t);
		}
	}
	cout << ans << endl;
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
		solve();
	return 0;
}