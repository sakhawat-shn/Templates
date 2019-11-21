#include<bits/stdc++.h>
using namespace std;

#define LLD long long int

LLD EulerPhi(LLD n)
{
    LLD pf_idx=0,pf=primes[pf_idx],ans=n;
    while(pf*pf<=n)
    {
        if(n%pf==0) ans-=ans/pf;
        while(n%pf==0) n/=pf;
        pf=primes[++pf_idx];
    }
    if(n!=1) ans-=ans/n;
    return ans;
}
