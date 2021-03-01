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
int n;
bool flip(vector<vector<int> > a, vector<vector<int> > b)
{
	// first do all the vertical flips
	for (int j = 0; j < n; j++)
	{
		if (a[0][j] != b[0][j])
		{
			for (int i = 0; i < n; i++)
				a[i][j] = (a[i][j] ^ 1);
		}
	}
	// let's check horizontal flips
	for (int i = 0; i < n; i++)
	{
		if (a[i][0] != b[i][0])
		{
			for (int j = 0; j < n; j++)
				a[i][j] = (a[i][j] ^ 1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != b[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
void solve()
{
	cin >> n;
	vector<vector<int> > a(n, vector<int> (n)), b(n, vector<int> (n));
	for (int i = 0; i < n; i++)
	{
		string s;	cin >> s;
		for (int j = 0; j < s.size(); j++)
			a[i][j] = s[j] - '0';
	}
	for (int i = 0; i < n; i++)
	{
		string s;	cin >> s;
		for (int j = 0; j < s.size(); j++)
			b[i][j] = s[j] - '0';
	}
	vector<vector<int> > c(a);
	for (int j = 0; j < n; j++)	c[0][j] ^= 1;
	if (flip(a, b) or flip(c, b))
		cout << "YES\n";
	else
		cout << "NO\n";
}
int32_t main()
{
	fast();
	int test;	cin >> test;
	while (test--)
		solve();
	return 0;
}