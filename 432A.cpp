#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;	cin>>n>>k;
	int arr[n];
	int count=0;
	for(int i=0;i<n;i++)	
	{
		cin>>arr[i];
		if(arr[i]+k<=5 and arr[i]<5)	count++;
	}
	cout<<count/3<<"\n";
	return 0;
}
