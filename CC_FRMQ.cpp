// not accepted 
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
		st[node]=max(st[2*node+1],st[2*node+2]);
	}
	int query(int start,int end,int node,int l,int r)
	{
		//complete overlap
		if(l<=start and end<=r)
			return st[node];
		//no overlap
		else if(end<l or start>r)	return INT_MIN;
		int mid=(start+end)>>1;
		return max(query(start,mid,2*node+1,l,r),query(mid+1,end,2*node+2,l,r));
	}
};
int main()
{
	int n;	cin>>n;
	arr.resize(n);
	for(int i=0;i<n;i++)	cin>>arr[i];
	int m,x,y;	cin>>m>>x>>y;
	segment_tree  t;
	t.init(n);
	t.build(0,n-1,0);
	int sum=0;
	for(int i=0;i<m;i++)
	{
		//cout<<x<<" "<<y<<":"<<t.query(0,n-1,0,min(x,y),max(x,y))<<endl;
		sum+=t.query(0,n-1,0,min(x,y),max(x,y));
		x=(x+7)%(n-1);
		y=(y+11)%n;
	}
	cout<<sum<<"\n";
	return 0;
}
