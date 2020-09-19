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
bool solve(int n,vector<int> &v)
{
	if(n==1)	return true;
	int index=0;
	for(int i=0;i<n-1;i++)
	{
		if(abs(v[i+1]-v[i])%2!=0)	return false;
	}
	return true;
}
int32_t main()
{
	fast();
	int test;	cin>>test;
	while(test--)
	{
		int n;	cin>>n;
		vi v(n);
		for(int i=0;i<n;i++)	cin>>v[i];
		if(solve(n,v))	cout<<"YES\n";
		else 			cout<<"NO\n";
	}
	return 0;
}

