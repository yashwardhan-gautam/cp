#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
	int a1,a2,a3;	cin>>a1>>a2>>a3;
	int t=a1*a2*a3;
	int a=sqrt(t/(a1*a1));
	int b=sqrt(t/(a2*a2));
	int c=sqrt(t/(a3*a3));
	//cout<<a<<" "<<b<<" "<<c<<"\n";
	cout<<4*(a+b+c)<<"\n";
	return 0;
}
