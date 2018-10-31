											// copyright @ unknownSK //
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define clear(a,x) memset(a,x,sizeof(a))
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
#define show(a) for(int bm=0;bm<a.size();bm++)cout<<a[bm]<<" ";
#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sc4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define sc5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define pr1(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)
#define pr4(a,b,c,d) printf("%d %d %d %d\n",a,b,c,d)
#define pr5(a,b,c,d,e) printf("%d %d %d %d %d\n",a,b,c,d,e)
#define scl(x) scanf("%lld",&x)
#define prl(x) printf("%lld\n",x)
#define u(i,a,b) for(int i=a;i<b;i++)
#define U(i,a,b) for(i=a;i<b;i++)
#define d(i,a,b) for(int i=a;i>b;i--)
#define D(i,a,b) for(i=a;i>b;i--)
#define cinall(x,n) for(int i=0;i<n;i++)cin>>x[i];
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define mod 1000000007
#define vec vector<int>
#define vll vector<ll> v
#define itr vector<int>::iterator

int main(){
	ll p,s,t,h,x;
	cin>>p>>s>>t>>h>>x;
	ll ans=0;
	u(i,0,x){
		if(s>t)ans+=p;
		else ans+=h;
		s--;
	}
	cout<<ans<<endl;
}
