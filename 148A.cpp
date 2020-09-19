#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,l,m,n,d;	cin>>k>>l>>m>>n>>d;
	vector<bool> mark(d+1,0);
	for(int i=k;i<=d;i+=k)
		mark[i]=1;
	for(int i=l;i<=d;i+=l)
		mark[i]=1;
	for(int i=m;i<=d;i+=m)
		mark[i]=1;
	for(int i=n;i<=d;i+=n)
		mark[i]=1;
		
	int count=0;
	for(int i=1;i<=d;i++)	if(mark[i])	count++;
	//cout<<i<<" "<<mark[i]<<"\n";
	cout<<count<<"\n";
	return 0;
}
