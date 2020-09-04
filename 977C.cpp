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
int n, k;
vector<int> v;
int32_t main()
{
	fast();
	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	sort(v.begin(), v.end());
	//for (int i = 0; i < n; i++)	cout << v[i] << " ";	cout << endl;
	int ans;
	if (k == 0)
		ans = v[0] - 1;
	else
	{
		ans = v[k - 1];
		if (k < n and v[k - 1] == v[k])
			ans = -1;
	}
	if (ans < 1)
		ans = -1;
	cout << ans << endl;
	return 0;
}