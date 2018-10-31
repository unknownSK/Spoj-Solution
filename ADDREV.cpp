#include<bits/stdc++.h>
using namespace std;

long long int rever(long long int x)
{
    long long int ans = 0;
    while(x>0)
    {
        long long int r = x%10;
        ans = ans*10 + r;
        x = x/ 10;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    for(int test=0;test<n;test++)
    {
        int a ,b;
        cin>>a>>b;
        a=rever(a);
        b=rever(b);
        a = a+b;
        a = rever(a);
        cout<<a<<endl;
    }
    return 0;
}
