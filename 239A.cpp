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
}
int32_t main()
{
	fast();
	int y,k,n;	cin>>y>>k>>n;
	vi v;
	for(int i=k;i<=n;i+=k)
	{
		if(i-y>=1)	v.pb(i-y);
	}
	if(v.size()==0)	cout<<"-1\n";
	else
	{	
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}
	return 0;
}
