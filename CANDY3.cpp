#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(unsigned long long int test=0;test<t;test++)
    {
        unsigned long long int n;
        cin>>n;
        unsigned long long int sum=0;
        for(int i=0;i<n;i++)
        {
            unsigned long long int data;
            cin>>data;
            sum = (sum+data)%n;
        }
        if(sum==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
