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
	int test;	cin>>test;
	while(test--)
	{
		vi v(3);
		for(int i=0;i<3;i++)	cin>>v[i];
		int n;	cin>>n;
		sort(v.begin(),v.end());
		int ans=v[2]-v[0]+v[2]-v[1];
		if((n-ans)>=0 and (n-ans)%3==0)	cout<<"YES\n";
		else 				cout<<"NO\n";
	}
	return 0;
}

