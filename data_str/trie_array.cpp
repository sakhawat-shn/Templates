#define MAX_NODE 100000
#define MAX_LEN 100
char s[MAX_LEN];

int node[MAX_NODE][26];
int root,nnode;
int isword[MAX_NODE];

void init()
{
    root=0;
    nnode=0;
    for(int i=0;i<26;i++)
        node[root][i]=-1;
}


void insrt()
{
    scanf("%s",s);
    int len=strlen(s);
    int now=root;
    for(int i=0;i<len;i++)
    {
        if(node[now][s[i]-'a']==-1)
        {
            node[now][s[i]-'a']=++nnode;
            for(int j=0;j<26;j++)
                node[nnode][j]=-1;
        }
        now=node[now][s[i]-'a'];
    }
    isword[now]=1;
}
