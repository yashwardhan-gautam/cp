#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
void fast()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
vector<int> v;
/*
bool prime(int n)
{
	for(int i=2;i*i<n;i++)	
		if(n%i==0)	return false;
	return true;
}*/
int32_t main()
{
	fast();
	int test;	cin>>test;
	while(test--)
	{
		v.clear();
		int n;	cin>>n;
		v.resize(n+1);
		int index=2;
		int n1=n;
		while(n1>1)
		{
			while(n1%index==0)
			{
				v[index]++;
				//cout<<index<<" "<<v[index]<<"\n";
				n1=n1/index;
			}
			index++;
		}
		int count=0;
		int a=-1,b=-1,c=-1;
		for(int i=2;i<=index;i++)
			if(v[i])	count++;
			//cout<<i<<" "<<v[i]<<endl;
		
		if(count>=3)
		{
			for(int i=2;i<=index;i++)
			{
				if(v[i])
				{
					if(a==-1)	a=i;
					else if(a!=1 and b==-1)	b=i;
				}
			}
			c=n/(a*b);
			cout<<"YES\n";
			cout<<a<<" "<<b<<" "<<c<<"\n";
		}
		else if(count==1)
		{
			int flag=0;
			for(int i=0;i<=index;i++)
			{
				if(v[i]>=6)
				{
					flag=1;
					a=i;
					b=i*i;
					c=n/(a*b);
					cout<<"YES\n";
					cout<<a<<" "<<b<<" "<<c<<"\n";
					break;
				}
			}
			if(flag==0)	cout<<"NO\n";
		}
		else if(count==2)
		{
			int t=0;
			for(int i=0;i<=index;i++)
			{
				if(v[i])
					t+=v[i];
			}
			if(t>3)
			{
				for(int i=0;i<=index;i++)
				{
					if(v[i])
					{
						if(a==-1)	a=i;
						else if(a!=-1 and b==-1)	
						{
							b=i;
							break;
						}
					}
				}
				
				c=n/(a*b);
				cout<<"YES\n";
				cout<<a<<" "<<b<<" "<<c<<"\n";
			}
			else cout<<"NO\n";
		}
		else 
		cout<<"NO\n";
	}	
	return 0;
}

