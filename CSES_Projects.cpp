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
struct job {
	int start, finish, money;
};
bool compare(job a, job b)
{
	return a.finish < b.finish;
}
int find(vector<job> &v, int i)
{
	// Linear search won't work in one TC, since the array is sorted already we can use Binary search
	/*
	for (int j = i - 1; j >= 0; j--)
	{
		if (v[j].finish < v[i].start)
			return j;
	}
	return -1;
	*/
	int l = 0, h = i - 1;
	int res = -1;
	while (l <= h)
	{
		int mid = (l + h) >> 1;
		if (v[mid].finish < v[i].start)
		{
			res = mid;
			l = mid + 1;
		}
		else
			h = mid - 1;
	}
	return res;
}
int32_t main()
{
	fast();
	cin >> n;
	vector<job> v;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].start >> v[i].finish >> v[i].money;
	sort(v.begin(), v.end(), compare);
	vector<int> dp(n);
	dp[0] = v[0].money;
	for (int i = 1; i < n; i++)
	{
		dp[i] = dp[i - 1];
		int prev = find(v, i);
		if (prev != -1)
			dp[i] = max(dp[i], v[i].money + dp[prev]);
		dp[i] = max(dp[i], v[i].money);
	}
	cout << dp[n - 1];
	return 0;
}