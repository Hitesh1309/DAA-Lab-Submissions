/*
Logic:-
Linear search

Linear search the min/max, second min/max in the array
*/

#include<iostream>
using namespace std;

class ls
{
public:
    int n;
    int maxv;
    int smaxv;
    int minv;
    int sminv;
    ls();
    int a[10000];
    ~ls();
    void insert_elements(int n)
    {
        if(n==0)
        {
            cout<<"No elements"<<endl;
            return;
        }
        cout<<"Enter the elements of the array"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    }
    void maxelement()
    {
        if(a[0]>a[1])
        {
            maxv=a[0];
            smaxv=a[1];
        }
        else
        {
            maxv=a[1];
            smaxv=a[0];
        }
        for(int i=2;i<n;i++)
        {
            if(maxv>=a[i])
            {
                if(smaxv>=a[i])
                    continue;
                else
                    smaxv=a[i];
            }
            else
            {
                smaxv=maxv;
                maxv=a[i];
            }
        }
        if(n==1)
        {
            maxv=a[0];
            smaxv=a[0];
        }
    }
    void minelement()
    {
        if(a[0]<a[1])
        {
            minv=a[0];
            sminv=a[1];
        }
        else
        {
            minv=a[1];
            sminv=a[0];
        }
        for(int i=2;i<n;i++)
        {
            if(minv<=a[i])
            {
                if(sminv<=a[i])
                    continue;
                else
                    sminv=a[i];
            }
            else
            {
                sminv=minv;
                minv=a[i];
            }
        }
        if(n==1)
        {
            minv=a[0];
            sminv=a[0];
        }
    }
    void displayresults()
    {
        if(n==0)
            return;
        if(n==1)
        {
            cout<<"Minimum value is "<<minv<<endl;
            cout<<"Maximum value is "<<maxv<<endl;
            cout<<"Second min and max do not exist"<<endl;
        }
        else
        {
            cout<<"Minimum value is "<<minv<<endl;
            cout<<"Maximum value is "<<maxv<<endl;
            cout<<"Second Minimum value is "<<sminv<<endl;
            cout<<"Second Maximum value is "<<smaxv<<endl;
        }
    }
};

ls::ls()
{
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
}

ls::~ls()
{
}

int main()
{
    ls t;
    t.insert_elements(t.n);
    t.minelement();
    t.maxelement();
    t.displayresults();
    return 0;
}
