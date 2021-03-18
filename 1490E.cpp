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
	vector<pii> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].fi;
		v[i].se = i + 1;
	}
	sort(v.begin(), v.end());

	auto possible = [&](int mid)
	{
		int sum = 0;
		for (int i = 0; i <= mid; i++)
			sum += v[i].fi;
		for (int i = mid + 1; i < n; i++)
		{
			if (sum >= v[i].fi)
				sum += v[i].fi;
			else
				return false;
		}
		return true;
	};

	int s = 0, e = n - 1;
	int ans = n - 1;
	while (s <= e)
	{
		int mid = (s + e) >> 1;
		if (possible(mid))
			ans = mid, e = mid - 1;
		else
			s = mid + 1;
	}
	vi res;
	for (int i = 0; i < n; i++)
	{
		if (v[i].fi >= v[ans].fi)
			res.pb(v[i].se);
	}
	sort(res.begin(), res.end());
	cout << res.size() << endl;
	for (auto it : res)
		cout << it << " ";
	cout << endl;
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
		solve();
	return 0;
}