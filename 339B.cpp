#include<bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
	int n,k;	cin>>n>>k;
	int arr[k];
	for(int i=0;i<k;i++)	cin>>arr[i];
	int ans=arr[0]-1;
	for(int i=1;i<k;i++)
	{
		if(arr[i]<arr[i-1])
		{
			ans+=n-arr[i-1]+arr[i];
		}
		else 
		{
			ans+=arr[i]-arr[i-1];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
