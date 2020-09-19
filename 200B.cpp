#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;	cin>>n;
	int arr[n];
	long long int sum=0;
	for(int i=0;i<n;i++)	
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	cout<<fixed<<setprecision(12)<<1.0*sum/(1.0*n)<<"\n";
	return 0;
}
