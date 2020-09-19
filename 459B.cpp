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
	if(v[0]==v[n-1])
	{
		int ans=((n)*(n-1))/2;
		cout<<"0 "<<ans<<"\n";
	}
	else 
	{
		int a=0,b=0;
		int index=0;
		while(index<n and v[index]==v[0])
		{
			index++;
			a=(a+1);
		}	
		index=n-1;
		while(index>=0 and v[index]==v[n-1])
		{
			index--;
			b=(b+1);
		}
		int ans=(a*b);
		cout<<v[n-1]-v[0]<<" "<<ans<<"\n";
	}
	return 0;
}
//To be noted if all the flowers are of same beauty, then number of ways are n*(n-1)/2  and not n*(n-1)
