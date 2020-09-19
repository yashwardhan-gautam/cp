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
#define endl			"\n"
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif*/
}


int32_t main()
{
	fast();
	int test;	cin>>test;
	while(test--)
	{
		string s;	cin>>s;
		int l=0,r=0,u=0,d=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='L')	l++;
			else if(s[i]=='R')	r++;
			else if(s[i]=='U')	u++;
			else if(s[i]=='D')	d++;
		}
		int lr=min(l,r);	int ud=min(u,d);
		if(lr==0)
		{
			if(u and d)	
			{
				cout<<"2"<<endl;
				cout<<"UD"<<endl;
			}		
			else 		
				cout<<"0"<<endl<<endl;
		}
		else if(ud==0)
		{
			if(l and r)
			{
				cout<<"2"<<endl;
				cout<<"LR"<<endl;
			}
			else 
				cout<<"0"<<endl<<endl;
		}
		else 
		{
			vector<char> v;	
			for(int i=0;i<lr;i++)	v.pb('L');
			for(int i=0;i<ud;i++)	v.pb('D');
			for(int i=0;i<lr;i++)	v.pb('R');
			for(int i=0;i<ud;i++)	v.pb('U');
			cout<<v.size()<<endl;
			for(int i=0;i<v.size();i++)	cout<<v[i];	cout<<endl;
		}
		
	}
	return 0;
}
