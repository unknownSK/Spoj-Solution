#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>bhams(10);
    for(int i=0;i<10;i++)
    {
        cin>>bhams[i];
    }
    int s=0,s1=0,s2=0;
    for(int i=0;i<10;i++)
    {
        s1=s;
        s2=s1 + bhams[i];
        int frooty1 = abs(100 - s1);
        int frooty2 = abs(100 - s2);
        if(frooty1<=frooty2)
        {
            s=s1;
        }
        else
        {
            s=s2;
        }
    }
    cout<<s<<endl;
    return 0;
}
