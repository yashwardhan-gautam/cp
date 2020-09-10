// https://codeforces.com/contest/988/problem/E
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
	int n;	cin >> n;
	string s = to_string(n);
	int ans = INT_MAX;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < s.size(); j++)
		{
			if (i == j)
				continue;
			string t = s;
			int curr_ans = 0;
			for (int k = i; k < s.size() - 1; k++)
			{
				curr_ans++;
				swap(t[k], t[k + 1]);
			}
			for (int k = j - (j > i); k < s.size() - 2; k++)
			{
				curr_ans++;
				swap(t[k], t[k + 1]);
			}
			int pos = -1;
			for (int k = 0; k < s.size(); k++)
			{
				if (t[k] != '0')
				{
					pos = k;
					break;
				}
			}
			for (int k = pos; k > 0; k--)
			{
				swap(t[k], t[k - 1]);
				curr_ans++;
			}
			// use stoll instead of stoi
			int nn = stoll(t);
			if (nn % 25 == 0)
				ans = min(ans, curr_ans);
		}
	}
	if (ans == INT_MAX)
		ans = -1;
	cout << ans << endl;
	return 0;
}