struct node
{
    bool endmark;
    node *next[26+1];
    node()
    {
        endmark=false;
        for(int i=0;i<26;i++)
            next[i]=NULL;
    }
} *root;

void insrt(string str)
{
    int len=str.size();
    node *curr=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
        {
            curr->next[id]=new node();
        }
        curr=curr->next[id];
    }
    curr->endmark=1;
}

bool srch(string str)
{
	int len=str.size();
    node *curr=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
        {
            return false;
        }
        curr=curr->next[id];
    }
    return curr->endmark;
}

void del(node *cur)
{
    for(int i=0;i<26;i++)
        if(cur->next[i])
            del(cur->next[i]);
    delete(cur);
}

int main()
{
    root=new node();
    //do ur works.....
    del(root);//root will be deleted
    return 0;
}
