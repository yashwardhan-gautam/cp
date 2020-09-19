#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)	cin>>arr[i];
	int max=0;
	for(int i=0;i<n;i++)
		if(arr[i]>arr[max])	max=i;
	int min=n-1;
	for(int i=n-1;i>=0;i--)
		if(arr[i]<arr[min])	min=i;
	//cout<<max<<" "<<min<<"\n";
	if(min>max)	cout<<(max-0)+(n-1-min)<<"\n";
	else 		cout<<max+(n-1-min)-1<<"\n";
	return 0;
}
