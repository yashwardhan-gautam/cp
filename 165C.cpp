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
int k;
string s;
int32_t main()
{
	fast();
	cin >> k >> s;
	vector<int> dp(s.size() + 1, 0);
	int ans = 0;
	int sum_till_now = 0;
	dp[0] = 1;
	for (int i = 0; i < s.size(); i++)
	{
		sum_till_now += s[i] - '0';
		if (sum_till_now >= k)
		{
			// substrings seen so far with sum "sum_till_now"-substrings seen so far with sum "sum_till_now - k "
			// = substrings seen so far with sum "k"
			ans += dp[sum_till_now - k];
		}
		dp[sum_till_now]++;
	}
	cout << ans << endl;
	return 0;
}