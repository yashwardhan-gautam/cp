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
vector<int> v1,v2;
bool solve(int n)
{
	//cout<<n<<"\n";
	if(n==4 or n==7)
	{
		if(n==4)	v1.pb(4);
		else v2.pb(7);
		return true;
	} 
	if(n<4 or (n==5 or n==6)) return false;
	if(solve(n-4))
	{
		v1.pb(4);
		return true;
	}
	if(solve(n-7))
	{
		v2.pb(7);
		return true;
	}
	return false;
}
int32_t main()
{
	fast();
	int n;	cin>>n;
	if(solve(n))
	{
		
		while(v1.size()>=7)
		{
			//v1.erase(v1.begin(),7);
			for(int i=0;i<7;i++)	v1.pop_back();
			for(int i=0;i<4;i++)	v2.push_back(7);
		}
		int ans=0;
		for(int i=0;i<v1.size();i++)	cout<<v1[i];
		for(int i=0;i<v2.size();i++)	cout<<v2[i];
		/*for(int i=0;i<v.size();i++)	
		{
			ans=(ans*10)+v[i];
		}
		cout<<ans<<"\n";*/
	}
	else 
	cout<<"-1\n";
	return 0;
}

