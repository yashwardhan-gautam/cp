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

void generate_parenthesis(string s, int n, int i, int open, int close)
{
	if (i == 2 * n)
	{
		cout << s << endl;
		return ;
	}
	if (open < n)
	{
		s += '(';
		generate_parenthesis(s, n, i + 1, open + 1, close);
	}
	if (open > close)
	{
		s += ')';
		generate_parenthesis(s, n, i + 1, open + 1, close);
	}
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	string s;
	generate_parenthesis(s, n, 0, 0, 0);
	return 0;
}
