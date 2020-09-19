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
vector<int> primes;
void solve()
{
	primes.pb(2);
	vector<bool> mark(10000001,0);
	for(int i=3;i<=10000000;i+=2)
	{
		if(!mark[i])
		{
			primes.pb(i);
			for(int j=i;j<=10000000;j+=2*i) mark[j]=1;
		}
	}
}
int32_t main()
{
	fast();
	solve();
	int n;	cin>>n;
	for(int i=0;i<n;i++)	cout<<primes[i]<<" ";	cout<<"\n";
	//cout<<primes[n-1]<<"\n";
	return 0;
}

