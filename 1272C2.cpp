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
	int n,k;	cin>>n>>k;
	string s;	cin>>s;
	unordered_set<char> unborken_keys;
	for(int i=0;i<k;i++) {
		char c;	cin>>c;
		unborken_keys.insert(c);
	}
	vector<bool> a(n);
	for(int i=0;i<s.size();i++) {
		if(unborken_keys.count(s[i])) 
			a[i]=1;
		else 
			a[i]=0;
	}
	// dp[i] represents number of substrings that end at character s[i-1]
	int total_substrings=0;
	vector<int> f(n+1,0);
	for(int i=1;i<=n;i++) {
		if(!a[i-1])
			continue;
		f[i] = f[i-1] + 1;
		total_substrings+=f[i];
	}
	cout<<total_substrings;
}