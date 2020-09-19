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
		int n;	cin>>n;
		vector<pair<int,int> > v(n);
		for(int i=0;i<n;i++)
			cin>>v[i].first>>v[i].second;
		sort(v.begin(),v.end());
		/*for(int i=0;i<n;i++)
		{
			cout<<v[i].first<<" "<<v[i].second<<"\n";
		}*/
		int flag=0;
		int ix=0;
		int iy=0;
		string s;
		for(int i=0;i<n;i++)
		{
			int tx=v[i].first-ix;
			int ty=v[i].second-iy;
			if(tx<0 or ty<0)
			{
				flag=1;
				break;
			}
			for(int i=0;i<tx;i++)	s+='R';
			for(int i=0;i<ty;i++)	s+='U';
			ix=v[i].first;
			iy=v[i].second;
		}
		if(flag)	cout<<"NO\n";
		else 		
		{
			cout<<"YES\n";
			cout<<s<<endl;
		}
	}
	return 0;
}
