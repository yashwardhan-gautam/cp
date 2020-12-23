#include<bits/stdc++.h>
using namespace std;
#define fi              first
#define se              second
#define int             unsigned long long
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
bool compare(pii a, pii b)
{
	return a.fi < b.fi;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	unordered_map<int, int> m;
	m[0] = -1;
	vector<pair<int, int> > v1;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += v[i];
		if (m.find(sum) != m.end())
		{
			v1.pb({m[sum] + 1, i});
			//cout << m[sum] + 1 << " " << i << endl;
		}
		m[sum] = i;
	}
	sort(v1.begin(), v1.end(), compare);
	vector<pair<int, int> > res;
	if (v1.size() == 0)
	{
		cout << "0\n";
		return 0;
	}
	res.pb(v1[0]);
	for (int i = 0; i < v1.size(); i++)
	{
		if (res[res.size() - 1].fi <= v1[i].fi and res[res.size() - 1].se >= v1[i].se)
			continue;
		else
			res.pb(v1[i]);
	}
	cout << res.size() << endl;
	for (auto it : v1)
		cout << it.fi << " " << it.se << endl;
	cout << endl;
	for (auto it : res)
		cout << it.fi << " " << it.se << endl;
	return 0;
}