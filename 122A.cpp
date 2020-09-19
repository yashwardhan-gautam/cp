#include<bits/stdc++.h>
#define int long long int
using namespace std;
bool is_lucky(int n)
{
	while(n)
	{
		if(n%10!=4 and n%10!=7)	return false;
		n=n/10;
	}
	return true;
}
bool solve(int n)
{
	for(int i=4;i<=n;i++)
	{
		if(is_lucky(i))
		{
			if(n%i==0)	return true;
		}
	}
	return false;
}
int32_t main()
{
	int n;	cin>>n;
	if(solve(n))	cout<<"YES\n";
	else 			cout<<"NO\n";
	return 0;
}
