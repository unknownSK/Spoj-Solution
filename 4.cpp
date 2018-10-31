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
bool safe(vector<string>v,int i,int j,int n,int m){
	if(v[i][j]=='.')return 0;
	if(i>=2&&v[i-2][j]=='#')return 1;
	if(j>=2&&v[i][j-2]=='#')return 1;
	if(i<=n-3&&v[i+2][j]=='#')return 1;
	if(j<=n-3&&v[i][j+2]=='#')return 1;
	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		bool f=1;
		vector<string>v;
		int ct=0;
		u(i,0,n){
			string s;
			cin>>s;
			v.pb(s);
		}
		u(i,0,n){
			string s=v[i];
			u(j,0,m){
				if(f==1&&((i==1&&s[j]=='#')||(i==n-2&&s[j]=='#')||(j==1&&s[j]=='#')||(j==m-2&&s[j]=='#')||safe(v,i,j,n,m))){
					f=0;
				//	cout<<i<<" "<<j<<endl;
				break;
				}
			}
			if(!f)break;
		}
		if(f)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
