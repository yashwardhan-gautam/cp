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
#define endl			"\n"
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}
int n,h,l,r;
int dp[2001][2001];
vector<int> arr;
int solve(int index,int time)
{
	if(index==n)	
	{
		if(time>=l and time<=r)	return 1;
		return 0;
	}
	if(dp[index][time]!=-1)	return dp[index][time];
	int lans=solve(index+1,(time+arr[index])%h);
	int rans=solve(index+1,(time+arr[index]-1)%h);
	dp[index][time]=max(lans,rans);
	//here we use index!=0 because we don't want to add 1 into the answer returned from root node
	if(index!=0 and time>=l and time<=r) dp[index][time]++;
	return dp[index][time];
}
int32_t main()
{
	fast();
	cin>>n>>h>>l>>r;
	arr.resize(n+1);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)	cin>>arr[i];
	cout<<solve(0,0);
	return 0;
}
