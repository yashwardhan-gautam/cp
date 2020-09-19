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
bool solve(int n,int m,vector<int> v,set<int> &s)
{
	if(n==1 or s.size()==n-1)	return true;
	for(int i=0;i<n;i++)
	{
	for(int i=0;i<n-1;i++)
	{
		if(v[i]>v[i+1])
		{
			if(s.find(i)!=s.end())	//return false;
				swap(v[i],v[i+1]);
		}
	}
	}
	//cout<<endl;
	//for(int i=0;i<n;i++)	cout<<v[i]<<" ";	cout<<endl;   
	for(int i=0;i<n-1;i++)	if(v[i]>v[i+1])	return false;
	return true;
}
int32_t main()
{
	fast();
	int test;	cin>>test;
	while(test--)
	{
		int n,m;	cin>>n>>m;
		vi arr(n);
		for(int i=0;i<n;i++)	cin>>arr[i];
		set<int> s;
		for(int i=0;i<m;i++)
		{
			int t;	cin>>t;
			s.insert(t-1);
		}
		if(solve(n,m,arr,s))	cout<<"YES\n";
		else 				cout<<"NO\n";
	}
	return 0;
}

