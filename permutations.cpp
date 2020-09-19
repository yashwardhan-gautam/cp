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

void permutations(string s, int i)
{
	if (i == s.size())
	{
		cout << s << endl;
		return  ;
	}

	for (int j = i; j < s.size(); j++)
	{
		swap(s[i], s[j]);
		permutations(s, i + 1);
		swap(s[i], s[j]);
	}
}
int32_t main()
{
	fast();
	string s;	cin >> s;
	permutations(s, 0);
	return 0;
}
