/*
Given a list of reviews, a list of keywords and an integer k. Find the most popular k keywords, in order of most to least frequently mentioned.
The comparison of strins is case-insensitive.
Multiple occurances of a keyword in a review should be considered as a single mention.
Example 1:

Input:
k = 2
keywords = ["anacell", "cetracular", "betacellular"]
reviews = [
  "Anacell provides the best services in the city",
  "betacellular has awesome services",
  "Best services provided by anacell, everyone should use anacell",
]

Output:
["anacell", "betacellular"]

Explanation:
"anacell" is occuring in 2 different reviews and "betacellular" is only occuring in 1 review.
Example 2:

Input:
k = 2
keywords = ["anacell", "betacellular", "cetracular", "deltacellular", "eurocell"]
reviews = [
  "I love anacell Best services; Best services provided by anacell",
  "betacellular has great services",
  "deltacellular provides much better services than betacellular",
  "cetracular is worse than anacell",
  "Betacellular is better than deltacellular.",
]

Output:
["betacellular", "anacell"]

Explanation:
"betacellular" is occuring in 3 different reviews. "anacell" and "deltacellular" are occuring in 2 reviews, but "anacell" is lexicographically smaller.
*/


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
vector<string> topKFrequent(vector<string> &keywords, vector<string> &reviews, int k)
{
	unordered_set<string> keyword(keywords.begin(), keywords.end());
	unordered_map<string, int> count;
	for (auto s : reviews)
	{
		stringstream ss(s);
		string temp;
		unordered_set<string> words;
		while (ss >> temp)
		{
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			if (keyword.find(temp) != keyword.end())
				words.insert(temp);
		}
		for (auto it : words)
			count[it]++;
	}
	vector<pair<string, int> > v;
	for (auto it : count)
		v.pb({it.first, it.second});
	sort(v.begin(), v.end(), [](const pair<string, int> &a, const pair<string, int> &b)
	{
		if (a.second == b.second)
			return a.first < b.first;
		return a.second > b.second;
	});
	vector<string> res;
	for (int i = 0; i < v.size() and i < k; i++)
		res.push_back(v[i].first);
	return res;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<string> keywords(n);
	for (int i = 0; i < n; i++)	cin >> keywords[i];
	int m;	cin >> m;
	vector<string> reviews(m);
	cin.ignore();
	for (int i = 0; i < m; i++)
	{
		string s;
		getline(cin, s);
		reviews[i] = s;
	}
	int k;	cin >> k;
	vector<string> res = topKFrequent(keywords, reviews, k);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}