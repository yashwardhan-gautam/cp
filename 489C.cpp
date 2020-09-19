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
bool possible(int m, int s)
{
	return ((s >= 0) and (s <= 9 * m));
}
int32_t main()
{
	fast();
	int m, s;	cin >> m >> s;
	string min, max;
	int sum = s;
	if ((s <= 0 and m > 1) or (s > 9 * m))
	{
		cout << "-1 -1";
		return 0;
	}

	for (int pos = 0; pos < m; pos++)
	{
		for (int digit = 0; digit <= 9; digit++)
		{
			if ((pos > 0 or digit > 0 or (m == 1 and digit == 0)) and possible(m - pos - 1, sum - digit))
			{
				min += ('0' + digit);
				sum -= digit;
				break;
			}
		}
	}
	sum = s;
	for (int pos = 0; pos < m; pos++)
	{
		for (int digit = 9; digit >= 0; digit--)
		{
			if (possible(m - pos - 1, sum - digit))
			{
				max += ('0' + digit);
				sum -= digit;
				break;
			}
		}
	}
	cout << min << " " << max ;
	return 0;
}