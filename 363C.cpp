//Go through the characters of the given string and build the resulting string ans. Let's denote the current character as ch.
//If ch is equal to the last two characters of ans, skip ch. If ch is equal to the last character of ans and ans[length(ans) - 2] = ans[length(ans) - 3] (assume that ans is 1-indexed), skip ch. Otherwise, append ch to ans.
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
#define endl			"\n"
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
	string ans;
	for (int i = 0; i < s.size(); i++)
	{
		if (i >= 2 and ans.size() >= 2 and s[i] == ans[ans.size() - 1] and s[i] == ans[ans.size() - 2])
			continue;
		else if (i >= 3 and ans.size() >= 3 and s[i] == ans[ans.size() - 1] and ans[ans.size() - 2] == ans[ans.size() - 3])
			continue;
		ans += s[i];
	}
	cout << ans;
	return 0;
}
