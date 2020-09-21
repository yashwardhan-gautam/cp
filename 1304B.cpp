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
	int zeroes, ones, x;	cin >> zeroes >> ones >> x;
	string s = "10";
	zeroes--;
	ones--;
	x--;
	while (x and zeroes and ones)
	{
		if (x > 1)
		{
			s += "10";
			ones--;
			zeroes--;
			x -= 2;
		}
	}
	if (x == 1)
	{
		if (zeroes)
		{
			if (s[s.size() - 1] == '1')
			{
				s += '0';
				zeroes--;
				x--;
			}
			else
			{
				s.insert(s.begin(), '0');
				zeroes--;
				x--;
			}
		}
		if (ones)
		{
			if (s[s.size() - 1] == '0')
			{
				s += '1';
				ones--;
				x--;
			}
			else
			{
				s.insert(s.begin(), '1');
				ones--;
				x--;
			}
		}
	}
	while (ones)
	{
		if (s[s.size() - 1] == '1')
		{
			s += '1';
			ones--;
		}
		else
		{
			s.insert(s.begin(), '1');
			ones--;
		}
	}
	while (zeroes)
	{
		if (s[s.size() - 1] == '0')
		{
			s += '0';
			zeroes--;
		}
		else
		{
			s.insert(s.begin(), '0');
			zeroes--;
		}
	}
	//cout << s  << " " << x << " " << zeroes << " " << ones << endl;
	cout << s << endl;
	return 0;
}