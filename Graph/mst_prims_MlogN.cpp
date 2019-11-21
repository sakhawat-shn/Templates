#include<bits/stdc++.h>
using namespace std;

//--------------start-----from shantos book
vector< pir<int,int> > v[100];//{neighbour node,weight}

struct Node
{
    int u,cost;
    Node(int _u,int _cost)
    {
        u=_u;
        cost=_cost;
    }
};

bool operator<(Node a,Node b)
{
    return a.cost>b.cost;
}

int cost[100],taken[100];

int prims(int s)
{
    priority_queue<Node> pq;
    for(int i=0;i<n;i++)
        cost[i]=1000000000,taken[i]=0;
    cost[s]=0;
    pq.push(Node(s,0));
    int ans=0;
    while(!pq.empty())
    {
        Node x=pq.top();
        pq.pop();
        if(taken[x.u])
        {
            continue;
        }
        taken[x.u]=1;
        ans=ans+x.cost;
        for(auto a:v[x.u])
        {
            if(taken[a.first]) continue;
            if(a.second<cost[a.first])
            {
                pq.push(Node(a.first,a.second));
                cost[v.first]=v.second;
            }
        }
    }
    printf("Cost of MST = %d",ans);
}
//----------------end----------

int main()
{


    return 0;
}
