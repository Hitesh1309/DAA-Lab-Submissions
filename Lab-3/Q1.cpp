#include <bits/stdc++.h>
using namespace std;

class algo
{
    int a[10000];

    public:

    int n;
    algo()
    {
        cout<<"Enter the number of elements"<<endl;
        cin>>n;
    }
    void read()
    {
        for (int i=0;i<n;i++)
        {
            cout<<"Enter the element "<<i+1<<endl;
            cin>>a[i];
        }
    }
    int way1(int n)
    {
        if(n==0)
            return a[0];
        else
            return max(a[n],way1(n-1));
    }
    int way2(int start,int end)
    {
        if(start==end)
            return a[start];
        else
            return max(way2(start,(end+start)/2),way2(((end+start)/2)+1,end));
    }
    int way3(int start,int end)
    {
        int k=(end-start)/3;
        if(start+1==end)
        {
            return max(a[start],a[end]);
        }
        else if(end<start)
        {
            return -1000000;
        }
        else if(start==end)
        {
            return a[start];
        }
        else
            return max(way3(start,start+k),max(way3(start+k+1,start+2*k),way3(start+2*k+1,end)));
    }

    int wayk(int start,int end,int k)
    {
        int d;
        if(k==1)
        {
            return way1(n);
        }
        float p=float((end-start))/k;
        if(start+1==end)
        {
            return max(a[start],a[end]);
        }
        else if(end<start)
        {
            return -1000000;
        }
        else if(start==end)
        {
            return a[start];
        }
        else
        {
            for(int i=1;i<=k;i++)
            {
                if(i==1)
                {
                    d=max(wayk(start,start+p,k),wayk(start+p+1,start+float(2*p),k));
                }
                else if(i>1&&1<k)
                {
                    d=max(d,wayk(start+float(i*p)+1,start+float((i+1)*p),k));
                }
                else
                {
                    d=max(d,wayk(start+i*p+1,end,k));
                }
            }
        }
        return d;
    }
};

int main()
{
    algo a;
    if(a.n==0)
    {
        cout<<"0 elements hence no maximum"<<endl;
        return 0;
    }
    a.read();
    int r=a.way1(a.n-1);
    cout<<"Max value in 1-way is :"<<r<<endl;
    r=a.way2(0,(a.n)-1);
    cout<<"Max value in 2-way is :"<<r<<endl;
    r=a.way3(0,(a.n)-1);
    cout<<"Max value in 3-way is :"<<r<<endl;
    int k;
    cout<<"Enter the value of k to find max in k-way"<<endl;
    cin>>k;
    r=a.wayk(0,(a.n)-1,k);
    cout<<"Max value in k-way is :"<<r<<endl;
    return 0;
}
