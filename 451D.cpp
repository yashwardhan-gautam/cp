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


int32_t main()
{
	fast();
	string s;	cin >> s;
	int b_at_odd = 0;
	int b_at_even = 0;
	int a_at_odd = 0;
	int a_at_even = 0;
	int odd = 0, even = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (i & 1)	//inserting at odd position
		{
			if (s[i] == 'a')
			{
				//cout << "adding a at odd position odd incremented to" << a_at_odd << endl;
				odd += a_at_even;
				a_at_even++;
				even += a_at_odd;
			}
			else
			{
				//cout << "adding b at odd position even incremented to" << b_at_even << endl;
				odd += b_at_even;
				b_at_even++;
				even += b_at_odd;
			}
		}
		else //inserting at even position
		{
			if (s[i] == 'a')
			{
				//cout << "adding a at even position even incremented to" << a_at_odd << endl;
				odd += a_at_odd;
				a_at_odd++;
				even += a_at_even;
			}
			else
			{
				//cout << "adding b at even position odd incremented to" << b_at_even << endl;
				odd += b_at_odd;
				b_at_odd++;
				even += b_at_even;
			}
		}
		odd++;
		//cout << s.substr(0, i + 1) << " " << even << " " << odd << endl << endl;
	}
	cout << even << " " << odd << "\n";
	return 0;
}
