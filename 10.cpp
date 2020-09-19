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


bool solve(string s, string p, int i, int j)
{
	cout << i << " " << j << endl;
	if (j == p.size())
		return (i == s.size());
	bool first = (i < s.size() and (s[i] == p[j] or p[j] == '.'));
	bool ans = false;
	if (j + 1 < p.size() and p[j + 1] == '*')
		ans = ((first and solve(s, p, i + 1, j)) or solve(s, p, i, j + 2));
	else
		ans = (first and solve(s, p, i + 1, j + 1));
	return ans;
}
bool isMatch(string s, string p) {
	return solve(s, p, 0, 0);
}
int32_t main()
{
	fast();
	string s, p;	cin >> s >> p;
	if (isMatch(s, p))
		cout << "true\n";
	else
		cout << "false\n";
	return 0;
}
