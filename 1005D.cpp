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
	string s;	cin >> s;
	vector<int> a(s.size());
	for (int i = 0; i < s.size(); i++)
		a[i] = (s[i] - '0');
	int rem[3] = {0};
	rem[0] = 0;
	int ans = 0;
	int sum = 0;
	rem[0] = 1;
	for (int i = 0; i < a.size(); i++)
	{
		sum += a[i];
		sum = sum % 3;
		if (rem[sum])
		{
			// the range is [index when last time this remainder was seen + 1, i]
			rem[1] = rem[2] = 0;
			rem[0] = 1;
			ans++;
			sum = 0;
		}
		else
			rem[sum]++;
	}
	cout << ans << endl;
	return 0;
}