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
vector<int> dp;
vector<int> find_digits(int n)
{
	int t = n;
	vector<int> v;
	while (t)
	{
		if (t % 10 != 0)
			v.pb(t % 10);
		t = t / 10;
	}
	return v;
}
int solve(int n)
{
	if (n == 0)
		return 0;
	if (dp[n] != -1)
		return dp[n];
	vector<int> digits = find_digits(n);
	//cout << n << ":";
	//for (int i = 0; i < digits.size(); i++)	cout << digits[i] << " ";
	//cout << endl;
	int ans = INT_MAX;
	for (int i = 0; i < digits.size(); i++)
	{
		ans = min(ans, 1 + solve(n - digits[i]));
	}
	return dp[n] = ans;
}
int32_t main()
{
	fast();
	cin >> n;
	dp.resize(n + 1, -1);
	cout << solve(n);
	return 0;
}