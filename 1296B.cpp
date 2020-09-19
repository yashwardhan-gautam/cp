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
		int ans=0;
		int t=1;
		while(n)
		{
			if(n/10==0)
			{
				ans+=n;
				break;
			}
			string s=to_string(n);
			int first=s[0]-'0';
			ans+=first*pow(10,s.size()-1);
			s=s.substr(1);
			int l=stoi(s);
			int r=first*pow(10,s.size()-1);
			n=l+r;
			//cout<<l<<"\n";
			//cout<<s<<"\n";
			//cout<<first*pow(10,s.size()-1)<<endl;
			//n=stoi(s)+first*pow(10,s.size()-1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

