#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
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
int largestRectangleArea(vector<int>& v) 
{
    int n=v.size();
    if(n==1)	return v[0];
    else if(n==0)	return 0;
    vector<int> left(n),right(n);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
    	if(st.empty() or v[st.top()]<=v[i])
    		st.push(i);
    	else 
    	{
    		while(!st.empty() and v[st.top()]>v[i])
    		{
    			right[st.top()]=i;
    			st.pop();
    		}
    		st.push(i);
    	}
    }
    while(!st.empty())	
    {
    	right[st.top()]=n;
    	st.pop();
    }
    for(int i=n-1;i>=0;i--)
    {
    	if(st.empty() or v[st.top()]<=v[i])
    		st.push(i);
    	else 
    	{
    		while(!st.empty() and v[st.top()]>v[i])
    		{
    			left[st.top()]=i;
    			st.pop();
    		}
    		st.push(i);
    	}
    }
    while(!st.empty())
    {
    	left[st.top()]=-1;
    	st.pop();
    }  
    /*for(int i=0;i<n;i++)	cout<<v[i]<<" ";	cout<<endl;
    for(int i=0;i<n;i++)	cout<<right[i]<<" ";	cout<<endl;
    for(int i=0;i<n;i++)	cout<<left[i]<<" ";	cout<<endl;*/
    int ans=(right[0]-left[0]-1)*v[0];
    for(int i=1;i<n;i++)
    	ans=max(ans,(right[i]-left[i]-1)*v[i]);
    return ans;
}

int32_t main()
{
	fast();
	int n;	cin>>n;
	vi v(n);
	for(int i=0;i<n;i++)	cin>>v[i];
	cout<<largestRectangleArea(v)<<endl;
	return 0;
}
