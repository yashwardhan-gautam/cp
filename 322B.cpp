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
	int r,g,b;	cin>>r>>g>>b;
	int ans=0;
	for(int i=0;i<3;i++)
	{
		if(i>r or i>g or i>b)	break;
		ans=max(ans,i+(r-i)/3+(g-i)/3+(b-i)/3);
	}
	cout<<ans<<"\n";
	return 0;
}

