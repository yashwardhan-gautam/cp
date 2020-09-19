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

string solve(int k, string s, vector<int> v)
{
	vector<int> v1;
	for (int i = 0; i < v.size(); i++)
	{
		//cout << v[i] << " ";
		if (v[i] == 0)
			v1.push_back(i);
	}
	int index = 0;
	//for (int i = 0; i < v1.size(); i++)
	//	cout << char(v1[i] + 'a') << endl;
	if (s.size() & 1 and s[s.size() / 2] == '?')
	{
		if (v1.size() == 0)
			index = 0;
		else
			index = v1[v1.size() - 1];
		s[s.size() / 2] = index + 'a';
		if (!v1.empty())
			v1.erase(v1.begin() + v1.size() - 1);
	}
	index = v1.size() - 1;
	int i = (s.size() - 2) / 2;
	int j = (s.size() + 1) / 2;
	//cout << s.size() << endl;
	while (i >= 0 and j < s.size())
	{
		//cout << i << " " << j << endl;
		if (s[i] == '?' and s[j] == '?')
		{
			if (v1.size() == 0)
				index = 0;
			else
				index = v1[v1.size() - 1];
			s[i] = s[j] = index + 'a';
			if (!v1.empty())
				v1.erase(v1.begin() + v1.size() - 1);
		}
		i--;
		j++;
	}
	//cout << v1.size() << " ";
	if (!v1.size())
		return s;
	return "IMPOSSIBLE";
}
int32_t main()
{
	fast();
	int k; string s;
	cin >> k >> s;
	int i = 0;
	int j = s.size() - 1;
	bool flag = true;
	vector<int> v(k, 0);
	while (i < j)
	{
		if (s[i] == '?' and s[j] == '?')
		{
			i++;
			j--;
			continue;
		}
		else if (s[i] == '?' and s[j] != '?')
		{
			s[i] = s[j];
			i++;
			j--;
		}
		else if (s[i] != '?' and s[j] == '?')
		{
			s[j] = s[i];
			i++;
			j--;
		}
		else if (s[i] != '?' and s[j] != '?' and s[i] != s[j])
		{
			flag = false;
			break;
		}
		else if (s[i] != '?' and s[j] != '?' and s[i] == s[j])
		{
			i++;
			j--;
			continue;
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '?')
			v[s[i] - 'a'] = 1;
	}
	//cout << s << endl;
	if (flag)
		cout << solve(k, s, v) << endl;
	else
		cout << "IMPOSSIBLE\n";
	return 0;
}
