#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;	cin>>n>>k;
	//int arr[k];
	vector<vector<int> > v(k);
	vector<bool> mark(n*k+1,0);
	for(int i=0;i<k;i++)
	{
		int t;	cin>>t;
		mark[t]=1;
		v[i].push_back(t);
	}
	int index=0;
	for(int i=1;i<=n*k;i++)
	{
		if(!mark[i])
		{
			v[index].push_back(i);
			mark[i]=true;
			index=(index+1)%k;
		}
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
