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
bool compare(pii a, pii b)
{
	return a.se < b.se;
}
int32_t main()
{
	fast();
	int n, k;	cin >> n >> k;
	priority_queue<pii> pq;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		pq.push({t, i});
	}
	vector<pair<int, int> > v;
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		pii curr = pq.top();
		pq.pop();
		sum += curr.fi;
		v.pb(curr);
	}
	v.pb({1e9, n});
	cout << sum << endl;
	sort(v.begin(), v.end(), compare);
	v[0].se = 0;
	for (int i = 0; i < v.size() - 1; i++)
		cout << v[i + 1].se - v[i].se << " ";
	//cout << v[i].fi << " " << v[i].se << endl;
	return 0;
}