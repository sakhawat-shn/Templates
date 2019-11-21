#include<bits/stdc++.h>
using namespace std;

//-----------start---------//
int p[100];
void init()
{
    for(int i=0;i<100;i++)p[i]=i;///can use iota() library function
}
int findx(int x)
{
    if(p[x]==x) return x;
    return p[x]=findx(p[x]);
}
void uni(int a,int b )
{
    p[findx(b)]=findx(a);
}
//-----------end-----------//

int main()
{
    init();
    while(1)
    {
        int a,b;
        cin>>a>>b;
        if(findx(a)==findx(b))
        {
            cout<<"in same set"<<endl;
        }
        else
        {
            cout<<"not in same set making same set"<<endl;
            uni(a,b);
        }
    }

    return 0;
}
