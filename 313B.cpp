/*
#include<bits/stdc++.h>
using namespace std;
string s;
struct segment_tree
{
	vector<int> st;
	void init(int n)
	{
		st.resize(4*n);
	}
	void build(int start,int end,int node)
	{
		if(start==end)
		{
			st[node]=0;
			return ;
		}
		int mid=(start+end)>>1;
		build(start,mid,2*node+1);
		build(mid+1,end,2*node+2);
		st[node]=st[2*node+1]+st[2*node+2];
		if(s[mid]==s[mid+1])	st[node]++;
		cout<<start<<" "<<end<<" "<<st[node]<<"\n";
	}
	int query(int start,int end,int node,int l,int r)
	{
		if(l<=start and end<=r)	
		{
			cout<<start<<" "<<end<<" "<<st[node]<<"\n";
			return st[node];
		}
		else if(end<l or r<start)	
		{
			cout<<start<<" "<<end<<" "<<"0\n";
			return 0;
		}
		int mid=(start+end)>>1;
		int left=query(start,mid,2*node+1,l,r);
		int right=query(mid+1,end,2*node+2,l,r);
		if(s[mid]==s[mid+1])	
		{
			cout<<start<<" "<<end<<" "<<left+right+1<<"\n";
			return left+right+1;
		}
		else 					
		{
			cout<<start<<" "<<end<<" "<<left+right<<"\n";
			return left+right;
		}
	}
};
int main()
{
	cin>>s;
	int n=s.size();
	segment_tree t;
	t.init(n);
	t.build(0,n-1,0);
	cout<<endl;
	int q;	cin>>q;
	while(q--)
	{
		int l,r;	cin>>l>>r;
		cout<<t.query(0,n-1,0,l-1,r-1)<<"\n";
	}
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;	cin>>s;
	int n=s.size();
	vector<int> dp(n,0);
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1])	dp[i]=dp[i-1]+1;
		else 				dp[i]=dp[i-1];
	}
	int m;	cin>>m;
	for(int i=0;i<m;i++)
	{
		int l,r;	cin>>l>>r;
		cout<<dp[r-1]-dp[l-1]<<"\n";
	}
	return 0;
}
