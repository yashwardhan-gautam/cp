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
	int abf = s.find("AB");
	int abl = s.rfind("AB");
	int baf = s.find("BA");
	int bal = s.rfind("BA");
	//cout << abf << " " << abl << " " << baf << " " << bal << endl;
	if (abf != string::npos and bal != string::npos and abf + 1 < bal )
		cout << "YES\n";
	else if (baf != string::npos and abl != string::npos and baf + 1 < abl)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}