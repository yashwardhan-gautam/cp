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
int solve(int n, int w, int h)
{
	int a = 1, b = 1;
	while (n % 2 == 0)
	{
		a *= 2;
		n = n / 2;
		if (a >= h or b >= h)
			return h;
	}
	while (w % 2 == 0)
	{
		b *= 2;
		w = w / 2;
		if (a >= h or b >= h)
			return h;
	}
	return a * b;
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
	{
		int n, w, h;	cin >> n >> w >> h;
		if (solve(n, w, h) >= h)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}