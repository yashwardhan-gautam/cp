#include<bits/stdc++.h>
#define int long long int
using namespace std;
vector<int> arr;
struct node
{
	int ps;
	int ss;
	int ts;
	int mss;
};
struct segment_tree
{
	vector<node> st;
	void init(int n)
	{
		st.resize(4*n);
	}
	void build(int start,int end,int index)
	{
		if(start==end)
		{
			st[index].ps=arr[start];
			st[index].ss=arr[start];
			st[index].ts=arr[start];
			st[index].mss=arr[start];
			return ;
		}
		int mid=(start+end)>>1;
		build(start,mid,2*index+1);
		build(mid+1,end,2*index+2);
		st[index].ps=max(st[2*index+1].ps, st[2*index+1].ts+st[2*index+2].ps);
		st[index].ss=max(st[2*index+2].ss, st[2*index+2].ts+st[2*index+1].ss);
		st[index].ts=st[2*index+1].ts+st[2*index+2].ts;
		st[index].mss=max(st[2*index+1].ss+st[2*index+2].ps,max(st[2*index+1].mss,st[2*index+2].mss));
		st[index].mss=max(st[index].mss,st[index].ps);
		st[index].mss=max(st[index].mss,st[index].ss);
	}
	node query(int start,int end,int index,int l,int r)
	{
		node t;
		if(start>r or end<l)	
		{
			t.ps=INT_MIN;	t.ss=INT_MIN;	t.ts=INT_MIN; 
			t.mss=INT_MIN;
			return t;
		}
		else if(start>=l and end<=r)	return st[index];
		
		int mid=(start+end)>>1;
		node t1=query(start,mid,2*index+1,l,r);
		node t2=query(mid+1,end,2*index+2,l,r);
		
		t.ps=max(t1.ps,t1.ts+t2.ps);
		t.ss=max(t2.ss,t2.ts+t1.ss);
		t.ts=t1.ts+t2.ts;
		t.mss=max(t1.ss+t2.ps,max(t1.mss,t2.mss));
		t.mss=max(t.mss,t1.ts+t2.ts);
		t.mss=max(t.mss,t.ps);
		t.mss=max(t.mss,t.ss);
		return t;
	}
};


int32_t main()
{
	int n;	cin>>n;
	arr.resize(n);
	for(int i=0;i<n;i++)	cin>>arr[i];
	segment_tree t;	t.init(n);
	t.build(0,n-1,0);
	
	node temp;
	int m;	cin>>m;
	for(int i=0;i<m;i++)
	{
		int l,r;	cin>>l>>r;
		l--;	r--;
		temp=t.query(0,n-1,0,l,r);
		cout<<temp.mss<<"\n";
	}
	
	return 0;
}
