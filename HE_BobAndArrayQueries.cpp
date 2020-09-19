#include<bits/stdc++.h>
#define int long long 
using namespace std;
vector<int> arr;
int count_bits(int n)
{
	int count=0;
	while(n)
	{
		n&=(n-1);
		count++;
	}
	return count;
}
struct segment_tree
{
	vector<int> st;
	void init(int n)
	{
		st.resize(4*n);
	}
	int query(int start,int end,int node,int l,int r)
	{
		if(l<=start and end<=r)	return st[node];
		else if(end<l or r<start) return 0;
		int mid=(start+end)>>1;
		return query(start,mid,2*node+1,l,r)+query(mid+1,end,2*node+2,l,r);
	}
	void update1(int start,int end,int node,int index)
	{
		if(start==end)
		{
			arr[start]=2*arr[start]+1;
			st[node]=count_bits(arr[start]);
			return ;
		}
		int mid=(start+end)>>1;
		if(index<=mid)	
			update1(start,mid,2*node+1,index);
		else 	
			update1(mid+1,end,2*node+2,index);
		
		st[node]=st[2*node+1]+st[2*node+2];
	}
	void update2(int start,int end,int node,int index)
	{
		if(start==end)
		{
			arr[start]=floor(arr[start]/2);
			st[node]=count_bits(arr[start]);
			return ;
		}
		int mid=(start+end)>>1;
		if(index<=mid)	
			update2(start,mid,2*node+1,index);
		else 	
			update2(mid+1,end,2*node+2,index);
		
		st[node]=st[2*node+1]+st[2*node+2];
	}
};

int32_t main()
{
	int n,q;	cin>>n>>q;
	arr.resize(n);
	segment_tree t;
	t.init(n);
	//t.build(0,n-1,0);
	for(int i=0;i<q;i++)
	{
 		int temp,x,y;
 		cin>>temp;
 		if(temp==1)
 		{
			cin>>x;	x--;
			t.update1(0,n-1,0,x);
		}
		else if(temp==2)
		{
			cin>>x;	x--;
			t.update2(0,n-1,0,x);
		}
		else 
		{
			cin>>x>>y;
			cout<<t.query(0,n-1,0,x-1,y-1)<<"\n";
		}
		//for(int i=0;i<n;i++)	cout<<arr[i]<<" ";	cout<<endl;
	}
	return 0;
}
