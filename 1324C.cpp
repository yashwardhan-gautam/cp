#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
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
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int solve(string s)
{
	vi v;
	v.pb(0);
	for(int i=0;i<s.size();i++)
		if(s[i]=='R')	v.pb(i+1);
	v.pb(s.size()+1);
	int ans=1;
	for(int i=0;i<v.size()-1;i++)
	{
		ans=max(ans,v[i+1]-v[i]);
	}
	return ans;
}
int32_t main()
{
	fast();
	int test;	cin>>test;
	while(test--)
	{
		string s;	cin>>s;
		cout<<solve(s)<<"\n";
	}
	return 0;
}

