#include <bits/stdc++.h>
#define int long long int
using namespace std;
struct dragon
{
	int x;
	int y;
};
bool compare(dragon a,dragon b)
{
	return a.x<b.x;
}
int32_t main()
{
	int s,n;	cin>>s>>n;
	dragon d[n];
	for(int i=0;i<n;i++)
		cin>>d[i].x>>d[i].y;
	sort(d,d+n,compare);
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(s>d[i].x)
			s+=d[i].y;
		else 
		{
			flag=1;
			break;
		}
	}
	if(!flag)	cout<<"YES\n";
	else 		cout<<"NO\n";
	return 0;
}
