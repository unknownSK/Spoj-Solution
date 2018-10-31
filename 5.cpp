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
ll fac[200000+5]; 
    
ll power(ll x, ll y) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % mod;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % mod; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % mod; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
ll modInverse(ll n) 
{ 
    return power(n, mod-2); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
ll C(ll n, ll r) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    
    return (fac[n]* modInverse(fac[r]) % mod * 
            modInverse(fac[n-r]) %mod) % mod; 
} 
void dfs(vector<ll>v[],vector<ll>&nw,vector<ll>&sz,bool vis[],ll src){
	vis[src]=1;
	u(i,0,v[src].size()){
		if(!vis[v[src][i]])
			dfs(v,nw,sz,vis,v[src][i]);
	}
	if(v[src].size()>0){
		ll szz=sz[v[src][0]],nww=nw[v[src][0]];
		u(i,1,v[src].size()){
			nww=((nww*nw[v[src][i]])%mod*(C(szz+sz[v[src][i]],sz[v[src][i]]))%mod)%mod;
			szz+=sz[v[src][i]];
		}
		sz[src]=szz+1;
		nw[src]=nww;
	}
}
int main(){
    boost;
    fac[0] = 1; 
    for (int i=1 ; i<=200005; i++) 
        fac[i] = (fac[i-1]*i)%mod; 
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll>v[n+1],nw(n+1),sz(n+1),in(n+1);
        u(i,0,n+1){
        	nw[i]=1;
        	sz[i]=1;
        	in[i]=0;
		}
		u(i,0,m){
            ll x,y;
            cin>>x>>y;
            x--;y--;
            v[x].pb(y);
            in[y]++;
        }
        u(i,0,n){
        	if(in[i]==0){
        		v[n].pb(i);
			}
		}
		ll src=n;
		bool vis[n+1];
		memset(vis,0,sizeof vis);
		dfs(v,nw,sz,vis,src);
		cout<<nw[n]<<endl;
    }
}
