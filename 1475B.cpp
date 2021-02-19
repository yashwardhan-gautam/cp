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
bool solve(int n)
{
	for (int i = 0; i <= ceil(n / 2020); i++)
	{
		int t = n - 2020 * i;
		if (t >= 0 and t % 2021 == 0)
		{
			//cout << i << " " << t / 2021 << endl;
			return true;
		}
	}
	return false;
}
int32_t main()
{
	fast();
	int t;	cin >> t;
	while (t--)
	{
		int n;	cin >> n;
		if (n < 2020)
			cout << "NO\n";
		else if (n == 2021 or n == 2020)
			cout << "YES\n";
		else if (solve(n))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}