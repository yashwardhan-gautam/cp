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
#define endl			"\n"
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
	int n, m;	cin >> n >> m;
	vector<int> arr(n);
	vector<int> q(m);
	for (int i = 0; i < n; i++)	cin >> arr[i];
	for (int i = 0; i < m; i++)	cin >> q[i];
	vector<int> prefix;
	prefix.push_back(0);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		prefix.push_back(sum);
	}
	for (int i = 0; i < m; i++)
	{
		int f = lower_bound(prefix.begin(), prefix.end(), q[i]) - prefix.begin() ;
		int k = q[i] - prefix[f - 1];
		cout << f << " " << k << endl;
	}
	return 0;
}