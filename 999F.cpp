// https://codeforces.com/contest/999/problem/F
// Top Down approach
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
const int N = 1e5 + 5;
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int n, k;
int freq[N];
int people[N];
int h[N];
int solve(int cards, int people, vector<vector<int> > &dp)
{
	if (cards == 0 or people == 0)
		return 0;
	if (dp[cards][people] != -1)
		return dp[cards][people];
	int ans = 0;
	for (int i = 1; i <= min(cards, k); i++)
	{
		ans = max(ans, h[i] + solve(cards - i, people - 1, dp));
	}
	return dp[cards][people] = ans;
}
int32_t main()
{
	fast();
	cin >> n >> k;
	for (int i = 1; i <= n * k; i++)
	{
		int t;	cin >> t;
		freq[t]++;
	}
	for (int i = 1; i <= n; i++)
	{
		int t;	cin >> t;
		people[t]++;
	}
	for (int i = 1; i <= k; i++)
		cin >> h[i];
	int ans = 0;
	for (int i = 1; i <= 1e5; i++)
	{
		if (!people[i] or !freq[i])
			continue;
		vector<vector<int> > dp(freq[i] + 1, vector<int> (people[i] + 1, -1));
		//cout << freq[i] << " " << people[i] << endl;
		ans += solve(freq[i], people[i], dp);
	}
	cout << ans << endl;
	return 0;
}