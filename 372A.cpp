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
	sort(v.begin(),v.end());
	//for(int i=0;i<n;i++)	cout<<v[i]<<" ";	cout<<endl;
	int count=0;
	int k=n-1;
	for(int i=n-1;i>=0;i--)
	{
		if(v[i]*2<=v[k])
			k--,count++;
	}
	if(n%2)
	{
		if(count>n/2)
			cout<<(n/2+1)<<endl;
		else 	
			cout<<(n-count)<<endl;
	}
	else 
	{
		if(count>n/2)
			cout<<(n/2)<<endl;
		else 
			cout<<(n-count)<<endl;
	}
	return 0;
}

