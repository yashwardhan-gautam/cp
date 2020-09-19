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
	/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif*
	*/
}
int32_t main()
{
	fast();
	int n;	cin>>n;
	vi v(n);
	for(int i=0;i<n;i++)	cin>>v[i];
	int a=0,b=0,c=0;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(v[i]==50) 
		{
			if(a<1)	
			{
				flag=1;
				break;
			}
			else a--;
		}
		else if(v[i]==100)
		{
			if(!(a>=3 or (a>=1 and b>=1)))
			{
				flag=1; break;
			}
			else 
			{
				if(b>=1)	
				{
					b-=1;
					a-=1;
				}
				else a-=3;
			}
		}
		if(flag)	break;
		if(v[i]==25)	a++;
		if(v[i]==50)	b++;
		if(v[i]==100)	c++;
	}
	if(flag)	cout<<"NO\n";
	else 		cout<<"YES\n";
	return 0;
}
