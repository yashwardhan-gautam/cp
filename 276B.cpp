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
	string s;	cin>>s;
	int n=s.size();
	int L[n][n];
	memset(L,0,sizeof(L));
	for(int i=0;i<n;i++)	L[i][i]=1;
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			// if the size is  2
			if(s[i]==s[j] and j==i+1)	L[i][j]=2;
			else if(s[i]==s[j])	L[i][j]=L[i+1][j-1]+2;
			else L[i][j]=max(L[i+1][j],L[i][j-1]);
		}
	}
	int max_pal_sub=L[0][n-1];
	if((n-max_pal_sub)&1)	cout<<"Second\n";
	else 					cout<<"First\n";
	return 0;
}

