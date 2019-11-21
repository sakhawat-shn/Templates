#include<bits/stdc++.h>
using namespace std;

#define LLD long long int //note ur code

vector<int> primeFactors(LLD n)
{
    vector<int> factors;
    LLD pf_idx=0;pf=primes[pf_idx]; //primes has been populated by sieve
    while(pf*pf<=n)
    {
        while(n%pf==0){n/=pf;factors.push_back(pf);}
        pf=primes[++pf_idx];
    }
    if(n!=1) factors.push_back(n);
    return factors;
}
