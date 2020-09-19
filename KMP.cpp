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

void KMP(string s, string p)
{
	vector<int> table(p.size(), 0);
	int i = 1, j = 0;
	int lp = p.size();
	int ls = s.size();
	while (i < lp)
	{
		while (j > 0 and p[i] != p[j])
		{
			j = table[j - 1];
		}
		if (p[i] == p[j])
		{
			table[i] = j + 1;
			i++;
			j++;
		}
		else
			i++;
	}
	for (int i = 0; i < table.size(); i++)	cout << table[i] << " ";	cout << endl;
	i = 0, j = 0;
	while (i < ls)
	{
		while (j > 0 and s[i] != p[j])
			j = table[j - 1];
		if (s[i] == p[j])
		{
			i++;
			j++;
		}
		else
			i++;
		if (j == lp)
		{
			cout << "Pattern found at " << i - j << endl;
			j = table[j - 1];
		}
	}
}
int32_t main()
{
	fast();
	string s;	cin >> s;
	string p;	cin >> p;
	KMP(s, p);
	return 0;
}
