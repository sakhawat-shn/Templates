#include<bits/stdc++.h>
using namespace std;

struct Interval
{
    int low,high;
};
struct ITNode
{
    Interval i;
    int mx;
    ITNode *left,*right;
    ITNode(Interval a)
    {
        i.high=a.high;
        i.low=a.low;
        mx=a.high;
        left=right=NULL;
    }
};

ITNode *insrt(ITNode *root,Interval i)
{
    if(root==NULL)
        return new ITNode(i);
    int l=root->i.low;
    if(i.low<l)
    {
        root->left=insrt(root->left,i);
    }
    else
    {
        root->right=insrt(root->right,i);
    }
    if(root->mx<i.high)
    {
        root->mx=i.high;
    }
    return root;
}

bool doOVerlap(Interval i1,Interval i2)
{
    if(i1.low<=i2.high&&i2.low<=i1.high)
    {
        return true;
    }
    return false;
}

Interval overlapSearch(ITNode *root,Interval i)
{
    if(root==NULL) return {-1,-1};
    if(doOVerlap(root->i,i))
    {
        return root->i;
    }
    if(root->left!=NULL&&root->left->mx>=i.low)
    {
        return overlapSearch(root->left,i);
    }
    return overlapSearch(root->right,i);
}

void inorder(ITNode *root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<"["<<root->i.low<<","<<root->i.high<<"]"<<"max="<<root->mx<<endl;
    inorder(root->right);
}

int main()
{
    ITNode *root=NULL;
    root=insrt(root,{1,6});
    root=insrt(root,{3,7});
    root=insrt(root,{5,8});
    root=insrt(root,{2,60});
    root=insrt(root,{40,66});
    root=insrt(root,{66,80});
    root=insrt(root,{33,78});
    root=insrt(root,{54,94});
    root=insrt(root,{69,78});
    root=insrt(root,{22,77});
    inorder(root);
    while(1)
    {
        int a,b;
        cin>>a>>b;
        Interval i=overlapSearch(root,{a,b});
        cout<<i.low<<" "<<i.high<<endl;
    }
    return 0;


    return 0;
}
