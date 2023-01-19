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
#define endl		 	      "\n"
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int32_t main()
{
	fast();
	int z, o, x;	cin >> z >> o >> x;
	string s = "10";
	z--;
	o--;
	x--;
	for (int i = 2; i <= x; i += 2)
	{
		s += "10";
		z--;
		o--;
	}
	if (x & 1)
	{
		if (o > 0)
		{
			o--;
			s += '1';
		}
		else
		{
			z--;
			s = '0' + s;
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
		if (s[i] == '0')
		{
			while (z > 0)
			{
				cout << '0';
				z--;
			}
		}
		else
		{
			while (o > 0)
			{
				cout << '1';
				o--;
			}
		}
	}
	return 0;
}
