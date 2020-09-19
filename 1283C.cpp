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

struct temp
{
	int a;
	int b;
};
bool compare(temp t1,temp t2)
{
	if(t1.a==t1.b or t2.a==t2.b)	return false;
	return true;
}
int32_t main()
{
	fast();
	int n;	cin>>n;
	vi v(n);
	vi v1;
	vector<bool> mark(n+1,0);
	
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		if(v[i])
			mark[v[i]]=1;
		else 
			v1.pb(i+1);
	}
	vi v2;
	for(int i=1;i<=n;i++)
		if(!mark[i])	v2.pb(i);
	sort(v2.begin(),v2.end());
	//for(int i=0;i<n;i++)	cout<<v[i]<<" ";	cout<<endl; 
	//for(int i=0;i<v1.size();i++)	cout<<v1[i]<<" ";	cout<<endl;
	//for(int i=0;i<v2.size();i++)	cout<<v2[i]<<" ";	cout<<endl;
	if(v1[0]==v2[0])
		swap(v2[0],v2[1]);
	//v[v1[0]-1]=v2[0];
	for(int i=1;i<v1.size();i++)
	{
		if(v2[i]==v1[i])
			swap(v2[i],v2[i-1]);
	}
	int index=0;
	for(int i=0;i<n;i++)
	{
		if(v[i])	cout<<v[i]<<" ";
		else 
		{
			cout<<v2[index]<<" ";
			index++;
		}
	}
	cout<<endl;
	return 0;
}