#include<bits/stdc++.h>
using namespace std;

#define LLD long long int

LLD numDiv(LLD n)
{
    LLD pf_idx=0,pf=primes[pf_idx],ans=1;//primes from sieve
    while(pf*pf<=n)
    {
        LLD power=0;
        while(n%pf==0){n/=pf;power++;}
        ans*=(power+1);
        pf=primes[++pf_idx];
    }
    if(n!=1) ans*=2;
    return ans;
}
