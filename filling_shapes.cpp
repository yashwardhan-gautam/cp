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
int solve(int n) {
	if (n==0) return 1;
	return 2*solve(n-2);
}
int32_t main()
{
	fast();
	// rectangle can't be filled if the number of rows are odd
	// there are two ways to fill two consecutive columns : 
	// **    **
	// -* or *-
	// --    --
	int  n;	cin>>n;
	if(n&1) 
		cout<<"0";
	else 
		cout << solve(n);
}