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
	int n;
	string s;	cin >> n >> s;
	int a = 0, b = 0, c = 0;
	int mul = 1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'c')
			c = (c + b) % mod;
		else if (s[i] == 'b')
			b = (b + a) % mod;
		else if (s[i] == 'a')
			a = (a + mul) % mod;
		else
		{
			c = (c * 3 + b) % mod;
			b = (b * 3 + a) % mod;
			a = (a * 3 + mul) % mod;
			mul *= 3;
			mul %= mod;
		}
	}
	cout << c % mod << endl;
	return 0;
}