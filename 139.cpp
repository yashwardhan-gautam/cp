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

unordered_set<string> st;
vector<int> dp;
vector<string> v;
int solve(string s, int pos)
{
	if (pos == s.size())
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		return 1;
	}
	if (dp[pos] != -1)
		return dp[pos];
	for (int end = pos + 1; end <= s.size(); end++)
	{
		string x = s.substr(pos, end - pos);
		// s.substr(pos,len) makes the substring s[pos,pos+len)
		if (st.find(x) != st.end() and solve(s, end))
		{
			v.push_back(x);
			return dp[pos] = true;
			v.erase(v.begin() + v.size() - 1);
		}

	}
	return dp[pos] = false;
}
bool wordBreak(string s, vector<string>& wordDict) {
	for (int i = 0; i < wordDict.size(); i++)
		st.insert(wordDict[i]);
	dp.resize(s.size() + 1, -1);
	return solve(s, 0);
}
int32_t main()
{
	fast();
	string s;
	int n;	cin >> n;
	vector<string> dict(n);
	for (int i = 0; i < n; i++)	cin >> dict[i];
	if (wordBreak(s, dict))	cout << "Yes\n";
	else 										cout << "No\n";
	return 0;
}
