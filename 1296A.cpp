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
		int o=0,e=0;
		vi arr(n); 
		int sum=0;
		for(int i=0;i<n;i++)	
		{
			cin>>arr[i];
			sum+=arr[i];
			if(arr[i]&1)	o++;
			else 			e++;
		}
		if(o==0)	cout<<"NO\n";
		else 
		{
			if(sum&1)	cout<<"YES\n";
			else if(e==0)	cout<<"NO\n";
			else 			cout<<"YES\n";
		}
	}
	return 0;
}

