#include<bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
	int n,k;	cin>>n>>k;
	int arr[n];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	int count=0;
	if(sum>0)
	{
		while(sum>0)
		{
			sum=sum-k;
			count++;
		}
	}
	else 
	{
		while(sum<0)
		{
			sum=sum+k;
			count++;
		}
	}
	cout<<count<<"\n";
	return 0;
}
