#include <bits/stdc++.h>
using namespace std;

void mkbst(int a[][2],int n);


class bst
{
    public:
        int data;
        class bst* right;
        class bst* left;
};

void pre(bst* head);

class bst* head=NULL;
class bst* tmp=NULL;

int cost=0,height=0;
int bestcost=1000000;

void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}

void permutations(int a[][2], int i, int end,int n)
{
    if (i==end-1)
    {
        mkbst(a,n);
        if(cost<bestcost)
        {
            bestcost=cost;
            tmp=head;
        }
        cost=0;
        head=NULL;
        return;
    }
    for (int j=i;j<end;j++)
    {
        swap(&a[i][0],&a[j][0]);
        swap(&a[i][1],&a[j][1]);
        permutations(a,i+1,end,n);
        swap(&a[i][0],&a[j][0]);
        swap(&a[i][1],&a[j][1]);
    }
}

bst* insertbst(bst* head, int info,int freq,int height)
{
    height++;
    if(head==NULL)
    {
        cost=cost+height*freq;
        height=0;
        bst* node=new bst;
        node->data=info;
        node->left=NULL;
        node->right=NULL;
        head=node;
        return head;
    }
    if (info>head->data)
    {
        head->right=insertbst(head->right,info,freq,height);
    }
    else
    {
        head->left=insertbst(head->left,info,freq,height);
    }
    return head;
}

void mkbst(int a[][2],int n)
{
    for(int i=0;i<n;i++)
    {
        head=insertbst(head,a[i][0],a[i][1],height);
    }
}

void pre(bst* head)
{
    if(head==NULL)
        return;
    cout<<head->data<<" ";
    pre(head->left);
    pre(head->right);
}

int main()
{
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int a[n][2];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the "<<i+1<<"th element and its frequency"<<endl;
        cin>>a[i][0];
        cin>>a[i][1];
    }
    permutations(a,0,n,n);
    cout<<"Preorder traversal of Greedy Optimal BST"<<endl;
    pre(tmp);
    cout<<endl;
    cout<<"Cost of the optimal bst is: "<<bestcost<<endl;
    return 0;
}
