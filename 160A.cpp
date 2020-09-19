#include<bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
	int n;	cin>>n;
	vector<int> arr(n);
	int total_sum=0;
	for(int i=0;i<n;i++)	
	{
		cin>>arr[i];
		total_sum+=arr[i];
	}
	sort(arr.begin(),arr.end(),greater<int>());
	int temp_sum=0;
	for(int i=0;i<arr.size();i++)	//cout<<arr[i]<<" ";
	{
		temp_sum+=arr[i];
		if(temp_sum>total_sum-temp_sum)
		{
			cout<<i+1;
			break;
		}
	}
	return 0;
}
