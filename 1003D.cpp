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
int n, q;
map<int, int, greater<int> > m;
int32_t main()
{
	fast();
	cin >> n >> q;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int t;	cin >> t;
		sum += t;
		m[t]++;
	}
	//for (auto it : m)
	//	cout << it.fi << " " << it.se << endl;
	while (q--)
	{
		int t;	cin >> t;
		if (t > sum)
		{
			cout << "-1\n";
			continue;
		}
		if (t == sum)
		{
			cout << n << endl;
			continue;
		}
		int ans = 0;
		for (auto it : m)
		{
			int d = min(t / it.fi, it.se);
			t -= it.fi * d;
			ans += d;
		}
		if (t)
			cout << "-1\n";
		else
			cout << ans << endl;
	}
	return 0;
}