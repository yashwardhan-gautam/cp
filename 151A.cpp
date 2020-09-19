#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,l,c,d,p,nl,np;	cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	int first=(k*l)/nl;
	int second=c*d;
	int third=p/np;
	cout<<min(first,min(second,third))/n<<"\n";
	return 0;
}
