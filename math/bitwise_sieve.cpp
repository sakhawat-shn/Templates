#include<bits/stdc++.h>
using namespace std;


#define check(N,pos) (N&(1<<(pos)))
#define Set(N,pos) N|(1<<(pos))
const int M=100000000;
int status[M/32+2]={0};
vector<int> primes;
void sieve()
{
    int sqN=(int)sqrt(M);
    int i,j,cnt=1;

    for(i=3;i<=sqN;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            for(j=i*i;j<=M;j+=2*i)
            {
                status[j>>5]=Set(status[j>>5],j&31);
            }
        }
    }
    primes.push_back(2);
    for(i=3;i<=M;i+=2)
    {
        if(check(status[i>>5],i&31)==0)
        {
            primes.push_back(i);
        }
    }
}


int main()
{
    sieve();
    cout<<primes.size();


    return 0;
}
