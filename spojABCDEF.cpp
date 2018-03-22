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

int first(vector<int> arr, int low, int high, int x, int n)
{
  if(high >= low)
  {
    int mid = (low + high)/2; 
    if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x)
      return mid;
    else if(x > arr[mid])
      return first(arr, (mid + 1), high, x, n);
    else
      return first(arr, low, (mid -1), x, n);
  }
  return -1;
}
int last(vector<int> arr, int low, int high, int x, int n)
{
  if(high >= low)
  {
    int mid = (low + high)/2;  
    if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x )
      return mid;
    else if(x < arr[mid])
      return last(arr, low, (mid -1), x, n);
    else
      return last(arr, (mid + 1), high, x, n);      
  }
  return -1;
}

int count(vector<int> arr, int x, int n)
{
  int i;
  int j;
  i = first(arr, 0, n-1, x, n);
  if(i == -1)
    return 0;
  j = last(arr, i, n-1, x, n);     
  return j-i+1;
}
int main(){
	boost;
	int n;
	cin>>n;
	int a[n];
	u(i,0,n){
		cin>>a[i];
	}
	vector<int> v1,v2;
	u(i,0,n){
		u(j,0,n){
			u(k,0,n){
				v1.pb(a[i]*a[j]+a[k]);
			}
		}
	}
	u(i,0,n){
		u(j,0,n){
			u(k,0,n){
				v2.pb((a[i]+a[j])*a[k]);
			}
		}
	}
	sort(v2.begin(),v2.end());
	/*show(v1);cout<<endl;
	show(v2);cout<<endl;*/
	ll ct=0;
	pair<vector<int>::iterator,vector<int>::iterator> p;
	u(i,0,v1.size()){
		int lo=lower_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
		int up=upper_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
		ct+=-lo+up;
	}
	cout<<ct<<endl;
}
