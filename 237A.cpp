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
struct temp
{
	int h,m;
};
int32_t main()
{
	fast();
	int n;	cin>>n;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++)
		cin>>v[i].first>>v[i].second;
	int ans=1;
	for(int i=0;i<n;)
	{
		//cout<<v[i].first<<" "<<v[i].second<<"-";
		int index=i+1;
		while(index<n and v[i]==v[index])	
		{
			//cout<<v[index].first<<" "<<v[index].second<<",";
			index++;
		}
		ans=max(ans,index-i);
		//cout<<"ans"<< index-i<<" ";
		i=index;
		//cout<<endl;
	}
	cout<<ans<<"\n";
	return 0;
}

