#include<bits/stdc++.h>
#define int long long int
using namespace std;
bool check(int ans)
{
	if(ans==0)	return false;
	while(ans)
	{
		if(ans%10!=4 and ans%10!=7)	return false;
		ans=ans/10;
	}
	return true;
}
int32_t main()
{
	
	int n;	cin>>n;
	int ans=0;
	while(n)
	{
		if(n%10==4 or n%10==7)	ans++;
		n=n/10;
	}
	//cout<<ans<<" ";
	if(check(ans))	cout<<"YES\n";
	else 			cout<<"NO\n";
	
	return 0;
}
