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
	int n,m,k;	cin>>n>>m>>k;
	int mat[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)	cin>>mat[i][j];
	vector<int> rows(n);
	vector<int> cols(m);
	for(int i=0;i<n;i++)	rows[i]=i;
	for(int j=0;j<m;j++)	cols[j]=j;
	while(k--)
	{
		char s;
		int x,y;	cin>>s>>x>>y;
		x--; y--;
		if(s=='c')
		{
			swap(cols[x],cols[y]);
		}
		else if(s=='r')
		{
			swap(rows[x],rows[y]);
		}
		else 
		{
			cout<<mat[rows[x]][cols[y]]<<"\n";
		}
	}
	return 0;
}
/*
Jenny&Covid-19
*/
