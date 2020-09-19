#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
//#define int             long long
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
		long long int n ;
		cin >> n ;
		string s ;
		cin >> s;
		map <pii,long long int> mp ;
		mp[{0,0}] = 0;
		long long int x = 0 , y = 0;
		long long int diff = INT_MAX ;
		long long int a= -1 , b= -1 ;
	   
		for(int i = 0 ; i < n ;i++){
			char c = s[i] ;
			
			if(c=='U') y++;
			else if(c=='D')y--;
			else if(c=='L')x--;
			else if(c=='R')x++;
			pii p = {x,y} ;
			if(mp.count(p)>0){
				long long int nt = i + 1;
				long long int last = mp[p] ;
			   
				if(nt - last < diff){
				 
					a = last+1 , b = nt ;
					diff = nt - last ;
				}
			}
		   
			mp[p] = i + 1;

		}
		if(a != -1){
			cout << a << " " << b << endl ;
		}
		else
			cout << -1 << endl ;
	}
	return 0;
}
	
