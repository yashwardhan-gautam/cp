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
struct num {
	int fi, si, sum;
};
class compare {
public:
	bool operator() (num a, num b)
	{
		return a.sum > b.sum;
	}
};
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	priority_queue<num, vector<num>, compare> pq;
	vector<vector<int> > res;
	map<pair<int, int>, int> m;
	pq.push({0, 0, nums1[0] + nums2[0]});
	m[ {0 , 0}] = 1;
	while (!pq.empty() and res.size() < k)
	{
		num t = pq.top();
		pq.pop();
		res.push_back(vector<int> {nums1[t.fi], nums2[t.si]});
		//cout << nums1[t.fi] << " " << nums2[t.si] << " " << t.sum << endl;
		pair<int, int> p1;
		if (t.fi + 1 < nums1.size())
		{
			p1 = make_pair(t.fi + 1, t.si);
			if (!m[p1])
			{
				m[p1] = 1;
				pq.push({t.fi + 1, t.si, nums1[t.fi + 1] + nums2[t.si]});
			}
		}
		if (t.si + 1 < nums2.size())
		{
			p1 = make_pair(t.fi , t.si + 1);
			if (!m[p1])
			{
				m[p1] = 1;
				pq.push({t.fi, t.si + 1, nums1[t.fi] + nums2[t.si + 1]});
			}
		}
	}
	return res;
}

int32_t main()
{
	fast();
	int n1;	cin >> n1;
	vector<int> v1(n1);
	for (int i = 0; i < n1; i++)	cin >> v1[i];
	int n2;	cin >> n2;
	vector<int> v2(n2);
	for (int i = 0; i < n2; i++)	cin >> v2[i];
	int k;	cin >> k;
	vector<vector<int> > res = kSmallestPairs(v1, v2, k);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}