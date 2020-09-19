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
#define limit 1000000
int prime[limit];
void is_prime()
{
	prime[0]=prime[1]=1;
	for(int i=2;i<limit;i++)
	{
		if(prime[i]==0)
		{
			for(int j=i*i;j<limit;j+=i)
				prime[j]=1;
		}
	}
}
bool solve(int n)
{
	double sq=sqrt(n);
	if(sq==(int) sq)
		return true;
	return false;
}
int32_t main()
{
	is_prime();
	int test;	cin>>test;
	while(test--)
	{
		int n;	cin>>n;
		if(n==4)	cout<<"YES\n";
		else if(n%2==0)	cout<<"NO\n";
		else if(solve(n) and prime[(int)(sqrt(n))]==0)	cout<<"YES\n";
		else 	cout<<"NO\n";
	}
	return 0;
}
