#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
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
			st[node]=arr[start];
			return ;
		}
		int mid=(start+end)>>1;
		build(start,mid,2*node+1);
		build(mid+1,end,2*node+2);
		
		st[node]=min(st[2*node+1],st[2*node+2]);
	}
	int query(int start,int end,int node,int l,int r)
	{
		if(l<=start and r>=end) return st[node];
		else if(end<l or r<start)	return INT_MAX;
		int mid=(start+end)>>1;
		return min(query(start,mid,2*node+1,l,r),query(mid+1,end,2*node+2,l,r));
	}
};
int main()
{
	int n;	cin>>n;
	arr.resize(n);
	for(int i=0;i<n;i++)	cin>>arr[i];
	segment_tree t;
	t.init(n);
	t.build(0,n-1,0);
	
	int q;	cin>>q;
	while(q--)
	{
		int l,r;	cin>>l>>r;
		cout<<t.query(0,n-1,0,l,r)<<"\n";
	}
	return 0;
}
