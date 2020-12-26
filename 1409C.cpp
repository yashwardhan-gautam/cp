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
int solve(int n, int x, int y)
{
	int l = y - x;
	if (n == 2) return y - x;
	for (int i = l; i >= 2; i--)
	{
		if (l % i == 0 and y / i >= n)
		{
			return i;
		}
	}
	for (int i = 1; i <= l; i++)
		if (l % i == 0)
			return i;
	return 1;
}
int32_t main()
{
	fast();
	int t;	cin >> t;
	while (t--)
	{
		int n, x, y;	cin >> n >> x >> y;
		int d = solve(n, x, y);
		cout << d << ": ";
		int y1 = y;
		int count = 0;
		while (y1 > 0 and count < n)
		{
			count++;
			cout << y1 << " ";
			y1 -= d;
		}
		for (int i = count + 1; i <= n; i++)
		{
			count++;
			cout << y + d << " ";
			y += d;
		}
		if (t)
			cout << endl;
	}
	return 0;
}