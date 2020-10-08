// https://www.interviewbit.com/problems/minimum-lights-to-activate/
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
int solve(vector<int> &v, int k)
{
	int n = v.size();
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = min(n - 1, i + k - 1); j >= i - k + 1; j--)
		{
			if (v[j] == 1)
			{
				ans++;
				flag = 1;
				i = j + k - 1;
				break;
			}
		}
		if (!flag)
			return -1;
	}
	return ans;
}
int32_t main()
{
	fast();

	int n, k;	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	cin >> k;
	cout << solve(v, k);
	return 0;
}