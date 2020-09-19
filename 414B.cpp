#include<bits/stdc++.h>
#define int long long int
#define mod 1000000007
using namespace std;

int32_t main()
{
	int n,k;	cin>>n>>k;
	int dp[k+1][n+1];
	memset(dp,0,sizeof(dp));
	// dp[i][j] denotes a sequence of length i in which all the elements are in between 1 and j
	
	//base case: 
	//dp[1][j]=1 for 1<=j<=n
	for(int j=1;j<=n;j++)	dp[1][j]=1;
	
	for(int l=1;l+1<=k;l++)
	{
		for(int x=1;x<=n;x++)
		{
			for(int i=1;i*x<=n;i++)
			{
				dp[l+1][i*x]+=dp[l][x];
				dp[l+1][i*x]-=dp[l+1][i*x]/mod*mod;
			}
		}
	}
	int sum=0;
	for(int j=1;j<=n;j++)
	{
		sum+=dp[k][j];
		sum-=sum/mod*mod;
	}
	cout<<sum<<"\n";
	return 0;
}





/*
//This top down approach is not working
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
vector<vector<int> > dp;
int solve(int n,int pos,int x)
{
	if(dp[pos][x]!=-1)	return dp[pos][x];
	if(pos==0)
		return dp[pos][x]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i%x==0)
		{
			if(dp[pos-1][i]!=-1)	ans+=((dp[pos-1][i])%mod);
			else ans+=(solve(n,pos-1,i))%mod;
			ans=ans%mod;
		}
	}
	dp[pos][x]=ans%mod;
	return dp[pos][x];
}
int32_t main()
{
	fast();
	int n,k;	cin>>n>>k;
	dp.resize(k+1);
	for(int i=0;i<=k;i++)	dp[i].resize(n+1);
	for(int i=0;i<=k;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=-1;
	cout<<solve(n,k,1)%mod<<"\n";
	return 0;
}
*/


