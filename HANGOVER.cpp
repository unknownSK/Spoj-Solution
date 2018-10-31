#include<bits/stdc++.h>
using namespace std;
int main()
{
    for(;;)
    {
        double bhams;
        cin>>bhams;
        if(bhams==0.00)
        {
            break;
        }
        else
        {
            int count=0;
            double sum=0;
            for(int i=2;sum<=bhams;i++)
            {
                sum += (double)1/i;
                //cout<<sum<<endl;
                count++;
            }
            cout<<count<<" "<<"card(s)"<<endl;
        }
    }
    return 0;
}
