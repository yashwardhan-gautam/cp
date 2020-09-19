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
int solve(int a,int b)
{
	if(a==b)	return 0;
	if(b>a)
	{
		if((b-a)&1)	return 1;
		return 2;
	}
	else
	{
		if((a-b)%2==0)	return 1;
		return 2;
	}
}
int32_t main()
{
	fast();
	int test;	cin>>test;
	while(test--)
	{
		int a,b;	cin>>a>>b;
		cout<<solve(a,b)<<"\n";
	}
	return 0;
}

