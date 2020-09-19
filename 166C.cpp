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
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}

int32_t main()
{
	int n,k;	cin>>n>>k;
	vi v(n);
	for(int i=0;i<n;i++)	cin>>v[i];
	int ans=0;
	while(1)
	{
		sort(v.begin(),v.end());
		if(v[(v.size()+1)/2-1]==k)	break;
		ans++;
		v.pb(k);
	}
	cout<<ans<<"\n";
	return 0;
}

