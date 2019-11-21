#include<bits/stdc++.h>
using namespace std;

#define LLD long long int //note it,as code

LLD _sieve_size;
bitset<10000010> bs;
vector<int> primes;

void sieve(LLD upperbound)
{
    _sieve_size=upperbound+1;
    bs.set();
    bs[0]=bs[1]=0;
    for(LLD i=2;i<=_sieve_size;i++)
    {
        if(bs[i])
        {
            for(LLD j=i*i;j<=_sieve_size;j+=i) bs[j]=0;
            primes.push_back((int)i);
        }
    }
}

bool isPrime(LLD n)
{
    if(n<=_sieve_size) return bs[n];
    for(int i=0;i<(int)primes.size();i++)
    {
        if(n%primes[i]==0) return false;
    }
    return true;
}

int main()
{
    sieve(10000000);
    printf("%d\n",isPrime(2147483647));//prime
    printf("%d\n",isPrime(136117223861LL));//not prime 104729*1299709
}

//mine idea..its faster .866s vs 1.6s
#define svn 1000000

bool prm[svn];

int shv()
{
    int i,rt,j;
    rt=sqrt(svn)+1;
    for(i=0;i<svn;i++)
    {
        prm[i]=1;
    }
    prm[0]=0;
    prm[1]=0;
    for(i=4;i<svn;i=i+2)
    {
        prm[i]=0;
    }
    for(i=3;i<=rt;i=i+2)
    {
        if(prm[i])
        {
            for(j=2*i;j<svn;j=j+i)
            {
                prm[j]=0;
            }
        }
    }
    for(i=1;i<svn;i++)
    {
        if(prm[i])
            primes1.push_back(i);
    }
}
// end


//another way which is O(n. prev 2 O(nloglogn)
#define N 10000000
int lp[N+1];
vector<int> pr;
void new_way_shv()
{

    for (int i=2; i<=N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
