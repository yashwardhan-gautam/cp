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
int sum;
bool solve(vi &v)
{
	int a = 0, b = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 1)
			a++;
		else
			b++;
	}
	if (b % 2 == 0) return (a % 2 == 0);
	else       return (a != 0 and a % 2 == 0);
}
int32_t main()
{
	fast();
	int t;	cin >> t;
	while (t--)
	{
		int n;	cin >> n;
		vector<int> v(n);
		sum = 0;
		for (int i = 0; i < n; i++)
			cin >> v[i], sum += v[i];
		if (sum & 1)
		{
			cout << "NO\n";
			continue;
		}
		if (solve(v))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}