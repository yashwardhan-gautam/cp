// https://codeforces.com/problemset/problem/417/C
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
	int n, k;	cin >> n >> k;
	// each node has k outdegree, but n*k<=n*(n-1)/2
	if (n >= 2 * k + 1)
	{
		cout << n*k << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= i + k; j++)
			{
				if (j > n)
					cout << i << " " << j % n << endl;
				else
					cout << i << " " << j  << endl;
			}
		}
	}
	else
		cout << "-1\n";
	return 0;
}