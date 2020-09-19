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
int solve(int n,int k,vector<int> &v)
{
	if(k==n)	return 1;
	int res=0;
	for(int i=0;i<k;i++)	res+=v[i];
	int ans=res;
	int ans_index=1;
	for(int i=k;i<n;i++)
	{
		res+=v[i]-v[i-k];
		//cout<<v[i]<<" "<<v[i-k]<<endl;
		if(res<ans)
		{
			ans=res;
			ans_index=i-k+2;
			//cout<<ans<<" "<<ans_index<<"\n";
		}
	}
	return ans_index;
}
int32_t main()
{
	fast();
	int n,k;	cin>>n>>k;
	vi v(n);	for(int i=0;i<n;i++)	cin>>v[i];
	cout<<solve(n,k,v)<<"\n";
	return 0;
}

