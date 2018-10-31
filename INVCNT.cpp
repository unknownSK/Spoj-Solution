#include<bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
#define ll long long int
#define all(a) (a.begin(),a.end())
#define rep(a,i,n) for(ll i=a;i<n;i++)

ll getsum(ll BITree[],ll index)
{
    ll sum=0;
    while(index>0)
    {
        sum+=BITree[index];
        index-=(index&(-index));
    }
    return sum;
}

void update(ll BITree[],ll n,ll index,ll val)
{
    index++;
    while(index<=n)
    {
        BITree[index]+=val;
        index-=(index&(-index));
    }
}

ll *construct(ll arr[],ll n)
{
    ll *BITree = new ll[n+1];
    rep(1,i,n+1)
    {
        BITree[i]=0;
    }
    rep(0,i,n)
    {
        update(BITree,n,i,arr[i]);
    }
    return BITree;
}

ll countt(ll arr[],ll n)
{
    ll countm =0;
    ll maxelement = *max_element(arr,arr+n);
    ll bit[maxelement+1];
    rep(1,i,n+1)
    {
        bit[i]=0;
    }
    for(ll i=n-1;i>=0;i--)
    {
        countm+=getsum(bit,arr[i]-1);
        update(bit,maxelement,arr[i],1);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll bhams[n];
        rep(0,i,n)
        {
            cin>>bhams[i];
        }
        cout<<countt(bhams,n)<<endl;
    }
}
