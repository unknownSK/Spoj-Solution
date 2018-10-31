#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int test=0;test<t;test++)
    {
        int n;
        cin>>n;
        vector<int>bhams(n);
        vector<int>frooty(n);
        for(int i=0;i<n;i++)
        {
            cin>>bhams[i];
        }
        for(int j=0;j<n;j++)
        {
            cin>>frooty[j];
        }
        sort(bhams.begin(),bhams.end());
        sort(frooty.begin(),frooty.end());
        int sum =0;
        for(int i=0;i<n;i++)
        {
            sum+=bhams[i]*frooty[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
