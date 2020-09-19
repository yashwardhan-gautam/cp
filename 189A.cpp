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
int32_t main()
{
	int n;	cin>>n;
	vi v(3);
	for(int i=0;i<3;i++)	cin>>v[i];
	int dp[n+1];
	fill(dp,dp+n+1,-1e10);	
	dp[0]=0;
	for(int i=0;i<3;i++)
		for(int j=v[i];j<=n;j++)	
			dp[j]=max(dp[j],dp[j-v[i]]+1);
	cout<<dp[n]<<"\n";
	//for(int i=0;i<=n;i++)	cout<<dp[i]<<" ";	cout<<endl;
	return 0;
}
