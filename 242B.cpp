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
struct segment
{
	int f;
	int l;
};
int32_t main()
{
	fast();
	int n;	cin>>n;
	segment s[n];
	int start=INT_MAX;
	int end=INT_MIN;
	for(int i=0;i<n;i++)
	{
		cin>>s[i].f>>s[i].l;
		start=min(start,s[i].f);
		end=max(end,s[i].l);
	}
	segment m=s[0];
	int mark=0;
	for(int i=1;i<n;i++)
	{
		if(s[i].l-s[i].f>m.l-m.f)
		{
			m=s[i];
			mark=i;
		}
	}
	if(m.f<=start and m.l>=end)	cout<<mark+1<<"\n";
	else 	cout<<"-1\n";
	return 0;
}

