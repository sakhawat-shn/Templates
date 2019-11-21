#include<bits/stdc++.h>
using namespace std;

#define LLD long long int

LLD sumDiv(LLD n)
{
    LLD pf_idx=0,pf=primes[pf_idx],ans=1;//primes from sieve
    while(pf*pf<=n)
    {
        LLD power=0;
        while(n%pf==0){n/=pf;power++;}
        ans*=((LLD)pow((double)pf,power+1.0)-1)/(pf-1);
        pf=primes[++pf_idx];
    }
    if(n!=1) ans*=((LLD)pow((double)n,2.0)-1)/(n-1);
    return ans;
}
