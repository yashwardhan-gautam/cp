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
	int n;	cin>>n;
	int a[n],b[n];
	vector<pair<int,int> > v1;	//eo
	vector<pair<int,int> > v2;	//oe
 	int suma=0;
	int sumb=0;
	for(int i=0;i<n;i++)	
	{
		cin>>a[i]>>b[i];
		suma+=a[i];
		sumb+=b[i];
		if(!(a[i]&1) and (b[i]&1))	v1.pb({a[i],b[i]});
		else if((a[i]&1) and !(b[i]&1)) v2.pb({a[i],b[i]});
	}
	//ee
	if(suma%2==0 and sumb%2==0)	cout<<"0\n";
	//oo
	else if(suma%2==1 and sumb%2==1 and (v1.size()>0 or v2.size()>0))	cout<<"1\n";
	else cout<<"-1\n";	
	return 0;
}

