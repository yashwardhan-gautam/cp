#include<bits/stdc++.h>
using namespace std;
#define fi              first
#define se              second
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
#define endl			"\n"
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}
struct sub
{
	int m;
	int b;
};
bool compare(sub s1,sub s2)
{
	if(s1.b==s2.b)	return s1.m<s2.m;
	else 			return s1.b<s2.b;
}
int32_t main()
{
	fast();
	int n,r,a;	cin>>n>>r>>a;
	a=a*n;
	vector<sub> v(n);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>v[i].m>>v[i].b;
		ans+=v[i].m;
	}
	sort(v.begin(),v.end(),compare);
i	nt count=0;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(v[i].m<r and ans<a)
		{
			if(ans+r-v[i].m>a)
			{
				count+=(a-ans)*v[i].b;
				flag=1;
				break;
			}
			else 
			{
				ans+=(r-v[i].m);
				count+=(r-v[i].m)*v[i].b;
			}
		}
		if(flag)	break;
	}
	cout<<count<<" "<<endl;
	return 0;
}
