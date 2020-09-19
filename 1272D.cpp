
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
	/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif*/
}


int32_t main()
{
	fast();
	int n;	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)	cin>>v[i];
	vector<pair<int,int> > v1;
	for(int i=0;i<n;)
	{
		int d=0;
		int i1=i;
		while(i<n-1 and v[i+1]>v[i])
		{
			d++;
			i++;
		}
		//cout<<i1<<" "<<i<<endl;
		if(d>=1)
		v1.pb(mp(i-d,i));
		i++;
	}
	//cout<<v1.size()<<endl;
	int ans=0;
	for(int i=0;i<v1.size();i++)
	{
		//cout<<v1[i].first<<" "<<v1[i].second<<"\n";
		ans=max(ans,v1[i].second-v1[i].first+1);
	}
	sort(v1.begin(),v1.end());
	//for(int i=0;i<v1.size();i++)	cout<<v1[i].first<<" "<<v1[i].second<<endl;
	//cout<<endl;
	
	for(int i=0;i<v1.size()-1;i++)
	{
		//cout<<v1[i].second<<" "<<v1[i+1].first<<"\n";
		if(v1[i].second+1==v1[i+1].first)
		{
			//cout<<"im in\n";
			//cout<<v[v1[i].second-1]<<" "<<v[v1[i+1].first]<<endl;
			if(v[v1[i].second-1]<v[v1[i+1].first])
			{
				//cout<<"im in 2"<<"\n";
				//cout<<v[v1[i].second-1]<<" "<<v[v1[i+1].first]<<"\n";
				ans=max(ans,v1[i].second-v1[i].first+v1[i+1].second-v1[i+1].first+1);
				//cout<<v1[i].second-v1[i].first+v1[i+1].second-v1[i+1].first+1<<endl;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
