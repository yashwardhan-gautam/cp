#include<bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int test;	cin>>test;
	while(test--)
	{
		int a,b,c;	cin>>a>>b>>c;
		int ans=INT_MAX;
		vector<int> v(3);
		for(int ta=1;ta<=100000;ta++)
		{
			for(int tb=ta;tb<=100000;tb+=ta)
			{
				//cout<<ans<<" "<<ta<<" "<<tb<<endl;
				int tc1=(c/tb)*tb;
				int tc2=(c+tb)/tb*tb;
				int tc3=(c-tb)/tb*tb;
				if(tc1>0 and tb<=tc1)
				{
					if(ans>abs(ta-a)+abs(tb-b)+abs(tc1-c))
					{
						ans=abs(ta-a)+abs(tb-b)+abs(tc1-c);
						v[0]=ta;	v[1]=tb;	v[2]=tc1;
					}
				}
				if(tc2>0 and tb<=tc2)
				{
					if(ans>abs(ta-a)+abs(tb-b)+abs(tc2-c))
					{
						ans=abs(ta-a)+abs(tb-b)+abs(tc2-c);
						v[0]=ta;	v[1]=tb;	v[2]=tc2;
					}
				}
				if(tc3>0 and tb<=tc3)
				{
					if(ans>abs(ta-a)+abs(tb-b)+abs(tc3-c))
					{
						ans=abs(ta-a)+abs(tb-b)+abs(tc3-c);
						v[0]=ta;	v[1]=tb;	v[2]=tc3;
					}
				}
			}
		}
		cout<<ans<<"\n";
		cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
			
	}
	return 0;
}




/*#include<bits/stdc++.h>
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

int32_t main()
{
	fast();
	int test;	cin>>test;
	while(test--)
	{
		int a,b,c;	cin>>a>>b>>c;
		int ans=INT_MAX;
		vi v(3);
		for(int ta=1;ta<=b;ta++)
		{
			int tans=0;
			int tb1,tb2,tb3;
			tb1=(b/ta)*ta;
			tb2=(b+ta)/ta*ta;
			tb3=(b-ta)/ta*ta;
			int tc11,tc12,tc13,tc21,tc22,tc23,tc31,tc32,tc33;
			if(tb1>0 and ta<=tb1)
			{
				tc11=(c/tb1)*tb1;	tc12=(c+tb1)/tb1*tb1;	tc13=(c-tb1)/tb1*tb1;
				if(tc11>0  and tb1<=tc11)	
				{
					tans=abs(ta-a)+abs(tb1-b)+abs(tc11-c);
					if(tans<ans)	
					{
						ans=tans;
						v[0]=ta;	v[1]=tb1;	v[2]=tc11;
					}
				}
				if(tc12>0 and tb1<=tc12)	
				{
					tans=abs(ta-a)+abs(tb1-b)+abs(tc12-c);
					if(tans<ans)	
					{
						ans=tans;
						v[0]=ta;	v[1]=tb1;	v[2]=tc12;
					}
				}
				if(tc13>0 and tb1<=tc13)	
				{
					tans=abs(ta-a)+abs(tb1-b)+abs(tc13-c);
					if(tans<ans)	
					{
						ans=tans;
						v[0]=ta;	v[1]=tb1;	v[2]=tc13;
					}
				}
			}
			
			if(tb2>0 and ta<=tb2)
			{
				tc21=(c/tb2)*tb2;	tc22=(c+tb2)/tb2*tb2;	tc23=(c-tb2)/tb2*tb2;
				if(tc21>0 and tb2<=tc21)	
				{
					tans=abs(ta-a)+abs(tb2-b)+abs(tc21-c);
					if(tans<ans)	
					{
						ans=tans;
						v[0]=ta;	v[1]=tb2;	v[2]=tc21;
					}
				}
				if(tc22>0 and tb2<=tc22)	
				{
					tans=abs(ta-a)+abs(tb2-b)+abs(tc22-c);
					if(tans<ans)	
					{
						ans=tans;
						v[0]=ta;	v[1]=tb2;	v[2]=tc22;
					}
				}
				if(tc23>0 and tb2<=tc23)	
				{
					tans=abs(ta-a)+abs(tb2-b)+abs(tc23-c);
					if(tans<ans)	
					{
						ans=tans;
						v[0]=ta;	v[1]=tb2;	v[2]=tc23;
					}
				}
			}
			
			if(tb3>0 and ta<=tb3)
			{
				tc31=(c/tb3)*tb3;	tc32=(c+tb3)/tb3*tb3;	tc13=(c-tb3)/tb3*tb3;
				if(tc31>0 and tb3<=tc31)	
				{
					tans=abs(ta-a)+abs(tb3-b)+abs(tc31-c);
					if(tans<ans)	
					{
						ans=tans;
						v[0]=ta;	v[1]=tb3;	v[2]=tc31;
					}
				}
				if(tc32>0 and tb3<=tc32)	
				{
					tans=abs(ta-a)+abs(tb3-b)+abs(tc32-c);
					if(tans<ans )	
					{
						ans=tans;
						v[0]=ta;	v[1]=tb3;	v[2]=tc32;
					}
				}
				if(tc33>0 and tb3<=tc33)	
				{
					tans=abs(ta-a)+abs(tb3-b)+abs(tc33-c);
					if(tans<ans)	
					{
						ans=tans;
						v[0]=ta;	v[1]=tb3;	v[2]=tc33;
					}
				}
			}
			
		}
		cout<<ans<<"\n";
		cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
	}
	return 0;
}
*/
