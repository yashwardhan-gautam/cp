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
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}


int32_t main()
{
	fast();
	int n,k;	cin>>n>>k;
	string s;	cin>>s;
	unordered_set<char> st;
	for(int i=0;i<k;i++)
	{
		char c;	cin>>c;
		st.insert(c);
	}
	vector<bool> mark(n+1,0);
	for(int i=0;i<n;i++)
	{
		if(st.find(s[i])!=st.end())	mark[i]=1;
	}
	int ans=0;
	int count=0;
	//for(int i=0;i<n;i++)	cout<<mark[i];	cout<<endl;
	for(int i=0;i<n;)
	{
		if(mark[i]==0)
		{
			count=0;
			i++;
			continue;
		}
		else 
		{
			int ans1;
			while(i<n and mark[i]==1)
			{
				count++;
				i++;
			}
			if(count&1)	
			{
				ans1=(count+1)>>1;
				ans1*=count;
			}
			else 
			{
				ans1=(count)>>1;
				ans1*=(count+1);
			}
			i++;
			ans+=ans1;
			cout<<count<<" "<<ans<<"\n";
			count=0;
		}
	}

	cout<<ans<<"\n";
	return 0;
}
