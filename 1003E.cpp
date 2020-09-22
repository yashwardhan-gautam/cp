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

int32_t main()
{
	fast();
	int n, d, k;	cin >> n >> d >> k;
	if (d >= n)
	{
		cout << "NO\n";
		return 0;
	}
	vector<int> deg(n + 1, 0);
	vector<pii> ans;
	for (int i = 1; i <= d; i++)
	{
		deg[i]++;
		deg[i + 1]++;
		if (deg[i] > k or deg[i + 1] > k)
		{
			cout << "NO\n";
			return 0;
		}
		ans.pb({i, i + 1});
	}
	//pair<maximum distance of a node u from any node v,node u> in increasing order
	set<pii> q;
	for (int i = 1; i <= d ; i++)
	{
		//cout << i << " " << i - 1 << " " << d - (i - 1) << endl;
		q.insert({max(i - 1, d - (i - 1)), i});
	}
	//for (auto it : q)
	//	cout << it.se << " " << it.fi << endl;
	for (int i = d + 2; i <= n; i++)
	{
		while (!q.empty() and deg[q.begin()->se] == k)
			q.erase(q.begin());
		if (q.empty() or q.begin()->fi == d + 1 or q.begin()->se == 1)
		{
			cout << "NO\n";
			return 0;
		}
		deg[i]++;
		deg[q.begin()->se]++;
		ans.pb({i, q.begin()->se});
		q.insert({q.begin()->fi + 1, i});
	}
	cout << "YES" << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].fi << " " << ans[i].se << endl;
	return 0;
}