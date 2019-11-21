#include<bits/stdc++.h>
using namespace std;

#define LLD long long int

void dbug(int a)
{
    cout<<a<<"\n";
}


int x,y,d;

void extendedEuclid(int a,int b)
{
    if(b==0){x=1;y=0;d=a;return;}
    extendedEuclid(b,a%b);
    int x1=y;
    int y1=x-(a/b)*y;
    x=x1;
    y=y1;
}

int main()
{
    extendedEuclid(25,18);
    dbug(x);dbug(y);dbug(d);
    return 0;
}
