#include<bits/stdc++.h>
using namespace std;
#define LLD long long int
//mine idea..its faster .866s vs 1.6s
#define svn 6000000
LLD phi[svn];
bool prime[svn];

int shv()
{
    int i,j;
    for(i=0;i<svn;i++)
    {
        phi[i]=i;
        prime[i]=1;
    }
    prime[0]=0;
    prime[1]=0;
    phi[0]=0;
    phi[1]=1;
    prime[2]=0;
    for(i=2;i<svn;i=i+2)
    {
        prime[i]=0;
        phi[i]=(phi[i]-phi[i]/2);
    }
    for(i=3;i<svn;i=i+2)
    {
        if(prime[i])
        {
            for(j=i;j<svn;j=j+i)
            {
                phi[j]=(phi[j]-phi[j]/i);
                prime[j]=0;
            }
        }
    }

}
