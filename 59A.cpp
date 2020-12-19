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
	string s;	cin >> s;
	int lc = 0, uc = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' and s[i] <= 'z') lc++;
		else uc++;
	}
	if (lc >= uc)	transform(s.begin(), s.end(), s.begin(), ::tolower);
	else 				transform(s.begin(), s.end(), s.begin(), ::toupper);
	cout << s << endl;
	return 0;
}