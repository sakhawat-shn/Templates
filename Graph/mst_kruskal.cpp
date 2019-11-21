#include<bits/stdc++.h>
using namespace std;

//------------start-----------//
#define edge pair<int,int>
vector< pair<int,edge > > graph,mst; ///must check type here for double or int weight
int p[100],total,n,e;

int findx(int x)
{
    if(p[x]==x) return x;
    return p[x]=findx(p[x]);
}
void uni(int a,int b )
{
    p[findx(b)]=findx(a);
}

void init()
{
    graph.clear();
    mst.clear();
    total=0;
    for(int i=0;i<100;i++)
        p[i]=i;
}

int kruskal()
{
    int i,pa,pb;
    sort(graph.begin(),graph.end());
    e=graph.size();
    for(i=total=0;i<e;i++)
    {
        pa=graph[i].second.first;
        pb=graph[i].second.second;
        if(findx(pa)!=findx(pb))
        {
            mst.push_back(graph[i]);
            total=total+graph[i].first;///check total vs graph.first type
            uni(pa,pb);
        }
    }
    return total;///check function return type
}
//---------------end-------------//

int main()
{


    return 0;
}
