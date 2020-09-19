#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;	cin>>n;
	int a[n],b[n];
	int cp=0;
	int ans=INT_MIN;
	for(int i=0;i<n;i++)	
	{
		cin>>a[i]>>b[i];
		cp+=-a[i]+b[i];
		ans=max(ans,cp);
	}
	cout<<ans<<"\n";
	return 0;
}
