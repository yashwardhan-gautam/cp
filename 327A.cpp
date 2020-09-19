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
	int n;	cin>>n;
	vi v(n);
	for(int i=0;i<n;i++)	cin>>v[i];
	int ans=0;
	/*for(int i=0;i<n;i++)
		if(v[i])
			ans++;*/
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			vi tv(v);
			int temp_ans=0;
			for(int t=i;t<=j;t++)
				tv[t]=1-v[t];
			
			//for(int t=0;t<n;t++)	cout<<tv[t]<<" ";	cout<<endl;
			for(int t=0;t<n;t++)
				if(tv[t])	temp_ans++;
			ans=max(ans,temp_ans);
		}
	}
	cout<<ans<<"\n";
	return 0;
}

