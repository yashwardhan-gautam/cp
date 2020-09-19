#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;	cin>>n;
	int arr[n];
	unordered_map<int,int> m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		m[arr[i]]=i+1;
	}
	for(int i=1;i<=n;i++)
	{
		if(m.find(i)!=m.end())
		{
			cout<<m[i]<<" ";
		}
		else cout<<i<<" ";
	}
	return 0;
}
