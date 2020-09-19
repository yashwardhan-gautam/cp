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
		int n,m;	cin>>n>>m;
		string s;	cin>>s;
		vi v(m);
		for(int i=0;i<m;i++)	cin>>v[i];
		v.pb(n);
		sort(v.begin(),v.end());
		vector<int> a(26,0);
		for(int i=0;i<n;i++)
		{
			auto it=upper_bound(v.begin(),v.end(),i);
			int id=it-v.begin();
			//cout<<s[i]<<" "<<id<<endl;
			a[s[i]-'a']+=(v.size()-id);
		}
		for(int i=0;i<a.size();i++)	cout<<a[i]<<" ";	cout<<endl;
	}
	
	return 0;
}

