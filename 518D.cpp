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

void dfs(vector<int> list, char node, vector<bool> &visited)
{

	visited[node] = 1;
	for (int i = 0; i < list[node].size(); i++)
	{
		if (visited[list[node][i]] != -1)
			dfs(list, list[node][i], node);
	}
	cout << "compiling" << node << "now" << endl;
	comilation(node);
}
// m -> a,b,c
// a-> z,y
// z-> it'll get compiled first
// y->s
// s-> it'll get compiled now
// y is compiled
// a gets compiled
// b-> y,w
// w-> will get complied now
// b will get compiled now
// c - c will get complied now

// sequence in which the dependencies of m will get complied are: z,s,y,a,w,b,c

int32_t main()
{
	fast();
	// given sorted numbers, size of the sorted numbers is not known.
	// given: the sorted array, and the number we are looking
	// 1. iterate over all the elements of the array and look for the particular element O(N), N is the number of elements
	// 2. Binary searching over the elements, O(log(N)), N is the number of elements

	-1 - 2 0 1 2 3 5
	s       m     e
	e = 1e18;

	// m -> a,b,c
	// a -> z,y
	// b -> y,w
	// y-> s
	// we are using a dfs approach here

	vector<char> list[1000];
	vector<bool> visited[1000];
	memset(nodes, -1, sizeof(visited));
	dfs(list, m, visited);
	return 0;
}


