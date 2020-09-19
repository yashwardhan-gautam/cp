#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
	int n;	cin>>n;
	vector<int> v(n);
	int ans=0;
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		ans+=abs(v[i]-i-1);
	}
	cout<<ans<<"\n";
	return 0;
}
