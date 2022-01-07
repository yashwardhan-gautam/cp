#include<bits/stdc++.h>
using namespace std;
#define fi              first
#define se              second
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
/*
input: 7 2
	   abacaba
	   a b

index: 0 1 2 3 4 5 6
v[]:   1 1 1 0 1 1 1 

// substrings ending at 0th index
0-0

//substrings ending at first index
0-1
1-1

//substrings ending at third index and so on
0-2
1-2
2-2

// if the v[i] is 1, then increase counter and add it to the answer
// otherwise make the counter as 0.
// return answer
*/
int32_t main()
{

	fast();
	int n,m;	cin>>n>>m;
	string s;	cin>>s;
	unordered_set<char> st;
	for(int i=0;i<m;i++)
	{
		char c;	cin>>c;
		st.insert(c);
	}
	vector<int> v(n,0);
	for(int i=0;i<s.size();i++) {
		if(st.count(s[i]))
			v[i]=1;
	}
	int res=0;
	int consecutive=0;
	for(int i=0;i<v.size();i++) {
		if(v[i]) {
			consecutive++;
			res+=consecutive;
		}
		else {
			consecutive=0;
		}
	}
	cout<<res;
	return 0;
}
