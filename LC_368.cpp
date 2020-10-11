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
vector<int> largestDivisibleSubset(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<int> dp(nums.size(), 1);
	int mx = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] % nums[j] == 0)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		if (dp[i] > mx)
			mx = dp[i];
	}
	vector<int> res;
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		if (dp[i] == mx and (res.size() == 0 or (nums[i] < res[0] and res[0] % nums[i] == 0)))
		{
			mx--;
			res.insert(res.begin(), nums[i]);
		}
	}
	return res;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)	cin >> nums[i];
	vector<int> res = largestDivisibleSubset(nums);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}