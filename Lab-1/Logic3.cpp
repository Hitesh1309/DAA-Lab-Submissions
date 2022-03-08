/*
Logic:-
Merge sort-like algo

- Divide the array into 2 halves
- get the min/max and second min /max of each half
- Compare the results to find the min/max, second min/max of the entire array.
*/

#include<iostream>
using namespace std;

class ls
{
public:
    int n;
    int maxv1;
    int smaxv1;
    int minv1;
    int sminv1;
    int maxv2;
    int smaxv2;
    int minv2;
    int sminv2;
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
        if(n==2)
        {
            if(a[1]>a[0])
            {
                maxv1=a[1];
                minv1=a[0];
                smaxv1=a[0];
                sminv1=a[1];
                return;
            }
            else
            {
                maxv1=a[0];
                minv1=a[1];
                smaxv1=a[1];
                sminv1=a[0];
                return;
            }
        }
        if(a[0]>a[1])
        {
            maxv1=a[0];
            smaxv1=a[1];
        }
        else
        {
            maxv1=a[1];
            smaxv1=a[0];
        }
        for(int i=2;i<n/2;i++)
        {
            if(maxv1>=a[i])
            {
                if(smaxv1>=a[i])
                    continue;
                else
                    smaxv1=a[i];
            }
            else
            {
                smaxv1=maxv1;
                maxv1=a[i];
            }
        }
        if(a[n/2]>a[n/2+1])
        {
            maxv2=a[n/2];
            smaxv2=a[n/2+1];
        }
        else
        {
            maxv2=a[n/2+1];
            smaxv2=a[n/2];
        }
        for(int i=(n/2)+2;i<n;i++)
        {
            if(maxv2>=a[i])
            {
                if(smaxv2>=a[i])
                    continue;
                else
                    smaxv2=a[i];
            }
            else
            {
                smaxv2=maxv2;
                maxv2=a[i];
            }
        }
        if(maxv1>maxv2)
        {
            if(smaxv1>maxv2)
                return;
            else
                smaxv1=maxv2;
        }
        else
        {
            if(maxv1>smaxv2)
            {
                smaxv1=maxv1;
                maxv1=maxv2;
            }
            else
            {
                smaxv1=smaxv2;
                maxv1=maxv2;
            }
        }
        if(n==1)
        {
            maxv1=a[0];
            smaxv1=a[0];
        }
    }
    void minelement()
    {
        if(a[0]<a[1])
        {
            minv1=a[0];
            sminv1=a[1];
        }
        else
        {
            minv1=a[1];
            sminv1=a[0];
        }
        for(int i=2;i<n/2;i++)
        {
            if(minv1<=a[i])
            {
                if(sminv1<=a[i])
                    continue;
                else
                    sminv1=a[i];
            }
            else
            {
                sminv1=minv1;
                minv1=a[i];
            }
        }
        if(a[n/2]<a[n/2+1])
        {
            minv2=a[n/2];
            sminv2=a[n/2+1];
        }
        else
        {
            minv2=a[n/2+1];
            sminv2=a[n/2];
        }
        for(int i=(n/2)+2;i<n;i++)
        {
            if(minv2<=a[i])
            {
                if(sminv2<=a[i])
                    continue;
                else
                    sminv2=a[i];
            }
            else
            {
                sminv2=minv2;
                minv2=a[i];
            }
        }
        if(minv1<minv2)
        {
            if(sminv1<minv2)
                return;
            else
                sminv1=minv2;
        }
        else
        {
            if(minv1<sminv2)
            {
                sminv1=minv1;
                minv1=minv2;
            }
            else
            {
                sminv1=sminv2;
                minv1=minv2;
            }
        }
        if(n==1)
        {
            minv1=a[0];
            sminv1=a[0];
        }
    }
    void displayresults()
    {
        if(n==0)
            return;
        if(n==1)
        {
            cout<<"Minimum value is "<<minv1<<endl;
            cout<<"Maximum value is "<<maxv1<<endl;
            cout<<"Second min and max do not exist"<<endl;
        }
        else
        {
            cout<<"Minimum value is "<<minv1<<endl;
            cout<<"Maximum value is "<<maxv1<<endl;
            cout<<"Second Minimum value is "<<sminv1<<endl;
            cout<<"Second Maximum value is "<<smaxv1<<endl;
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
