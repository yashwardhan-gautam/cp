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


int32_t main()
{
	fast();
	int test;	cin>>test;
	while(test--)
	{
	int a,b,c;	cin>>a>>b>>c;
	int ans=INT_MAX;
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			for(int k=-1;k<=1;k++)
			{
				int a1=a+i;
				int b1=b+j;
				int c1=c+k;
				int ans1=abs(a1-b1)+abs(a1-c1)+abs(b1-c1);
				ans=min(ans,ans1);
			}
		}
	}
	cout<<ans<<"\n";
	}
	return 0;
}
