void build(int att,int l,int r)
{
    //can init like sum[att]=0
    if(l==r)
    {
        //if need saet value of sum[att]=then=num[l]
        return ;
    }
    int mid=(l+r)/2;
    build(att*2,l,mid);
    build(att*2+1,mid+1,r);
    //do init like: sum[att]=sum[att*2]+sum[att*2+1] and others.
}

void update(int att,int l,int r,int pos,int u)
{
    if(l==r)
    {
        sum[att]+=u;
        return ;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update(att*2,l,mid,pos,u);
    else
        update(att*2+1,mid+1,r,pos,u);
    sum[att]=sum[att*2]+sum[att*2+1];
}

int query(int att,int L,int R,int l,int r)
{
    if(r<L||R<l) return 0;
    if(l<=L&&R<=r) return sum[att];
    int mid=(L+R)/2;
    int x=query(att*2,L,mid,l,r);
    int y=query(att*2+1,mid+1,R,l,r);
    return x+y;
}

int main()
{
    return 0;
}
