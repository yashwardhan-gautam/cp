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
struct temp
{
	int x,y;
};
vector<temp> v;
void dfs(vector<bool> &vis,int n,int t)
{
	vis[t]=true;
	//cout<<v[t].x<<" "<<v[t].y<<"\n";
	for(int i=0;i<n;i++)
	{
		if(!vis[i] and (v[i].x==v[t].x or v[i].y==v[t].y))
		{		
			dfs(vis,n,i);
		}
	}
}
int32_t main()
{
	fast();
	int n;	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i].x>>v[i].y;
	}
	vector<bool> vis(n,0);
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			count++;
			dfs(vis,n,i);
			//cout<<v[i].x<<" "<<v[i].y<<"-";
		}
		//cout<<"\n";
	}
	cout<<count-1<<"\n";
	return 0;
}

