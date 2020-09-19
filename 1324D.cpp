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
	vi a(n),b(n);
	vector<int> v;
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int i=0;i<n;i++)	cin>>b[i];
	int c[n];
	for(int i=0;i<n;i++)	c[i]=a[i]-b[i];
	sort(c,c+n);
	//cout<<endl;
	//for(int i=0;i<n;i++)	cout<<c[i]<<" ";	cout<<endl; 
	int ans=0;
	for(int i=0;i<n;i++)
	{
		/*for(int j=i+1;j<n;j++)
		{
			if(c[i]>-1*c[j])
			{
				auto it=upper_bound(c+i+1,c+n,-c[i]);
				int id=it-c;
				cout<<id<<"\n";
				cout<<c[i]<<" "<<c[j]<<endl;
			}
		}
		cout<<endl;*/
		auto it=upper_bound(c+i+1,c+n,-c[i]);
		int id=it-c;
		ans+=n-id;
	}

	cout<<ans<<"\n";
	return 0;
}

