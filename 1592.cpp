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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
string reorderSpaces(string text)
{
	int original_size = text.size();
	//cout << text.size() << endl;
	int spaces = 0;
	int words = 0;
	int i = 0;
	while (i < text.size())
	{
		while (i < text.size() and text[i] == ' ')
		{
			spaces++;
			i++;
		}
		if (i < text.size() and text[i] != ' ')
		{
			while (i < text.size() and text[i] != ' ')
			{
				i++;
			}
			words++;
		}
	}
	if (words == 1)
	{
		while (text[0] == ' ')
			text.erase(text.begin());
		while (spaces--)
			text.insert(text.begin() + text.size(), ' ');
		return text;
	}
	//cout << words << " " << spaces << endl;
	int t = spaces / (words - 1);
	while (text.size() > 0 and text[0] == ' ')
		text.erase(text.begin());
	i = 0;
	while (i < text.size())
	{
		while (i < text.size() and text[i] == ' ')
		{
			text.erase(text.begin() + i );
		}
		for (int j = 0; j < t; j++)
		{
			text.insert(text.begin() + i , ' ');
			i++;
		}
		if (i < text.size() and text[i] != ' ')
		{
			while (i < text.size() and text[i] != ' ')
			{
				i++;
			}
			words++;
		}
	}
	while (text[0] == ' ')
		text.erase(text.begin());
	while (text[text.size() - 1] == ' ')
		text.erase(text.begin() + text.size() - 1);
	int new_size = text.size();
	int rem = (original_size - new_size);
	while (rem--)
		text.insert(text.begin() + text.size(), ' ');
	//cout << text.size() << endl;
	return text;
}
int32_t main()
{
	fast();
	string s;
	getline(cin, s);
	cout << reorderSpaces(s);
	return 0;
}