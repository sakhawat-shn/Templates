#include<bits/stdc++.h>
using namespace std;

bitset<100010> vis;

int segmented_sieve(int a, int b)
{
    vis=0;
    if(b<2) return 0;
    if(a<2) a=2;
    int xx=sqrt((double)b)+1;
    for(ll i=0;i<SZ(prime) && prime[i]<=xx;i++)
    {
        ll j=(a/prime[i]);
        if(a%prime[i]!=0) j++;
        j*=prime[i];
        if(j==prime[i]) j+=prime[i];
        for(;j<=b;j+=prime[i])
            vis[j-a]=1;
    }
    int cnt=0;
    for(ll i=a;i<=b;i++)
        if(vis[i-a]==0) cnt++;
    return cnt;
}

int main()
{


    return 0;
}
