#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
	int n,m;	cin>>n>>m;
	int arr[m];
	for(int i=0;i<m;i++)	cin>>arr[i];
	sort(arr,arr+m);
	int ans=INT_MAX;
	//for(int i=0;i<m;i++)	cout<<arr[i]<<" ";	cout<<"\n";
	for(int i=0;i+n<=m;i++)
	{
		//cout<<arr[i]<<" "<<arr[i+n-1]<<"\n";
		ans=min(ans,arr[i+n-1]-arr[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
