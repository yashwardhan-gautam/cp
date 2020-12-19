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
int solve(int n, int m)
{
	if (n < m)
		return -1;
	if (n == m) return n;
	for (int a = n / 2 + 1; a >= 1; a--)
	{
		if ((n - a) % m == 0 and (n - 2 * a >= 0))
		{
			//cout << a << "\n";
			return (n - a);
		}
	}
	return -1;
}
int32_t main()
{
	fast();
	int n, m;	cin >> n >> m;
	cout << solve(n, m);
	return 0;
}