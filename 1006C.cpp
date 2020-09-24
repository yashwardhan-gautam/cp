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
	int n;	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	vector<int> l(n), r(n);
	l[0] = v[0], r[n - 1] = v[n - 1];
	for (int i = 1; i < n; i++)
		l[i] = l[i - 1] + v[i];
	for (int i = n - 2; i >= 0; i--)
		r[i] = r[i + 1] + v[i];
	int ans = 0;
	//for (int i = 0; i < n; i++)	cout << l[i] << " ";	cout << endl;

	//for (int i = 0; i < n; i++)	cout << r[i] << " ";	cout << endl;
	for (int i = n - 1; i >= 0; i--)
	{
		auto it = lower_bound(l.begin(), l.end(), r[i]) - l.begin();
		if (it < i and l[it] == r[i])
			ans = max(ans, r[i]);
	}
	cout << ans << endl;
	return 0;
}