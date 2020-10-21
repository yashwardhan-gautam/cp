/*
Given the number of five-star and total reviews for each product a company sells, as well as the threshold percentage, what is the minimum number of additional five-star reviews the company needs to become five star seller.
For ex, there are 3 products (n=3) with productRatings =[[4,4],[1,2],[3,6]], percentage rating threshold = 77.
[1,2] indicates => [1 (five star reviews) ,2 (total reviews)].
We need to get the seller reach the threshold with minimum number of additional five star reviews.
Before we add more five star reviews, the percentage for this seller is ((4/4) + (1/2) + (3/6))/3 = 66.66%
If we add a five star review to 2nd product, ((4/4) + (2/3) + (3/6))/3 = 72.22%
If we add another five star review to 2nd product, ((4/4) + (3/4) + (3/6))/3 = 75%
If we add a five star review to 3rd product, ((4/4) + (3/4) + (4/7))/3 = 77.38%
At this point, 77% (threshold) is met. Therefore, answer is 3 (because that is the minimum five star reviews we need to add, to get the seller reach the threshold).
*/
/*
Constraints:
1<= productRatings.size() <=200
In product ratings, [fivestar, total], fivestar <=100, total<=100
1<=ratingsThreshold< 100
productRatings contains only non negative integers.
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
double computeThreshold(vector<vector<int> > &v)
{
	double sum = 0.0, n = v.size() * 1.0;
	for (int i = 0; i < v.size(); i++)
		sum += (double)(v[i][0] * 1.0 / v[i][1] * 1.0);
	return (sum / n) * 100.00;
}
struct cmp
{
	bool operator() (const pair<double, vector<vector<int> > > &a, const pair<double, vector<vector<int> > > &b)
	{
		// greater goes on top
		return a.first < b.first;
	}
};
int fiveStarReviews(vector<vector<int> > productRatings, int ratingsThreshold)
{
	std::priority_queue<pair<double, vector<vector<int>>>, vector<pair<double, vector<vector<int>>>>, cmp> pq;
	pq.push(make_pair(computeThreshold(productRatings), productRatings));
	int count = 0;
	while (!pq.empty())
	{
		double rating = pq.top().first;
		vector<vector<int> > t = pq.top().second;
		pq.pop();
		if (rating >= ratingsThreshold)
			return count;
		for (int i = 0; i < t.size(); i++)
		{
			t[i][0]++; t[i][1]++;
			pq.push({computeThreshold(t), t});
			t[i][0]--; t[i][1]--;
		}
		count++;
	}
	return count;
}
int32_t main()
{
	fast();
	int n;	cin >> n;
	vector<vector<int> > productRatings;
	for (int i = 0; i < n; i++)
	{
		int fivestar, totalratings;
		cin >> fivestar >> totalratings;
		productRatings.push_back({fivestar, totalratings});
	}
	int ratingsThreshold;	cin >> ratingsThreshold;
	cout << fiveStarReviews(productRatings, ratingsThreshold);
	return 0;
}