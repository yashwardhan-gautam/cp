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
map<int, int> m;
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	vector<int> powers;
	for (int i = 0; i < 31; i++)
		//cout << (1 << i) << endl;
		powers.pb(1 << i);
	int ans = 0;
	for (auto it : m)
	{
		bool found = 0;
		for (auto pw : powers)
		{
			if (m.find(pw - it.fi) != m.end())
			{
				if ((pw == 2 * it.fi) and it.se == 1)
					continue;
				found = 1;
			}
		}
		if (!found)
			ans += it.se;
	}
	cout << ans << endl;
	return 0;
}