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
#define MAX (1<<16)
#define MAX1 (MAX<<2)

int A[MAX];
struct node{
	int bestleftsum,bestrightsum,sum,bestsum;
	void merge(node &A,node &B){
		sum=A.sum+B.sum;
		bestleftsum=max(A.bestleftsum,A.sum+B.bestleftsum);
		bestrightsum=max(A.bestrightsum+B.sum,B.bestrightsum);
		bestsum=max(max(A.bestsum,B.bestsum),A.bestrightsum+B.bestleftsum);
	}
	void createleaf (int val){
		sum=bestleftsum=bestrightsum=bestsum=val;
	}
};
node T[MAX1];
void init(int index,int l,int r){
	if(l==r){
		T[index].createleaf(A[l]);
		return;
	}
	else{
		int mid=(l+r)/2;
		init(2*index,l,mid);
		init(2*index+1,mid+1,r);
		T[index].merge(T[2*index],T[2*index+1]);
	}
}
void query(node &result,int l,int r,int u,int v,int index){
	if(u==l && v==r){
		result=T[index];
		return;
	}
	else{
		int mid=(l+r)/2;
		if(mid>=v){
			query(result,l,mid,u,v,2*index);
		}else if(mid<u){
			query(result,mid+1,r,u,v,2*index+1);
		}else{
			node left,right;
			query(left,l,mid,u,mid,2*index);
			query(right,mid+1,r,mid+1,v,2*index+1);
            result.merge(left,right);

		}
	}
}
int main(){
	boost;
	int n,x,y;
	cin>>n;
	cinall(A,n);
	init(1,0,n-1);
	int t;
	cin>>t;
	node Ans;
	while(t--){
		cin>>x>>y;
		query(Ans,0,n-1,x-1,y-1,1);
		cout<<Ans.bestsum<<"\n";
	}
}
