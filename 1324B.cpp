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
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	int maxlen=1;
	for(int i=0;i<n;i++)	dp[i][i]=1;
	for(int i=0;i<n-1;i++)
	{
		if(v[i]==v[i+1])	dp[i][i+1]=2;
	}
	for(int l=3;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			if(v[i]==v[j])	
			{
				dp[i][j]=dp[i+1][j-1]+2;
				if(l>=3) return true;
			}
			else 			dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
		}
	}
	return false;
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

