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
// this function returs gcd
int eea(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		cout << a << " " << b << ":" << x << " " << y << " " << endl;
		return a;
	}
	int x1, y1;
	int ans = eea(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	cout << a << " " << b << ":" << x << " " << y << endl;
	return ans;
}
int32_t main()
{
	fast();
	int a, b;	cin >> a >> b;
	int x, y;
	cout << eea(a, b, x, y) << endl;
	cout << x << " " << y << endl;
	return 0;
}
