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
	fast();
	int n,m;	cin>>n>>m;
	vi v(n+1);
	for(int i=1;i<=n;i++)	cin>>v[i];
	vi ans(n+1);
	unordered_set<int> s;
	for(int i=n;i>=1;i--)
	{
		if(s.find(v[i])==s.end())	
		{
			s.insert(v[i]);
			if(i==n)	ans[i]=1;
			else ans[i]=ans[i+1]+1;
		}
		else ans[i]=ans[i+1];
	}
	// for(int i=1;i<=n;i++)	cout<<ans[i]<<" ";	cout<<"\n";
	for(int i=0;i<m;i++)
	{
		int t;	cin>>t;
		cout<<ans[t]<<"\n";
	}
	return 0;
}
