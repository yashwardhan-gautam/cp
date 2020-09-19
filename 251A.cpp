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
	int n,d;	cin>>n>>d;
	vi v(n);
	for(int i=0;i<n;i++)	cin>>v[i];
	int r=0;
	int ans=0;
	for(int l=0;l<n-1;l++)
	{
		while(r<n and v[r]-v[l]<=d) r++;
		r--;
		int t=r-l;
		ans+=((t)*(t-1))/2;
	}
	cout<<ans<<"\n";
	return 0;
}


/*
M E T 5 E U Y 5


*/

/*
m e t5 e uy 5
e t5 w r m
m e t5 e m w 2 q

Bb = jwt


*/
