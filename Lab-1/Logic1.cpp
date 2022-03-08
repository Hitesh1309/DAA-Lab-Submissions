/*
Logic:-
Divide and conquer 2 way

- Take first 2 elements and store min/max in a[0], take min/max of next 2 elements and store in a[1], and so on
- You end up with n/2 elements now, do step 1again and you end up with n/4 elements.
- Do till you end up with one element in the array and it will be the min
- If you want second min update the min in the array as 100000 and if you want second max update the max in the array as -100000 and do step 1 and 2 again.
- You get the second max and second min.

*/

#include <iostream>
using namespace std;

class logic
{
public:
    int n;
    int maxv;
    int smaxv;
    int minv;
    int sminv;
    logic();
    int a[10000];
    int b[10000];
    int c[10000];
    int d[10000];
    ~logic();
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
            b[i]=a[i];
            c[i]=a[i];
            d[i]=a[i];        
        }
    }

    void maxi()
    {
        int count=0, fcount=0,sum=0;
        while(fcount!=1)
        {
            for(int i=1;i<n-sum;i+=2)
            {
                if(a[i]>a[i-1])
                {
                    a[count]=a[i];
                }
                else
                {
                    a[count]=a[i-1];
                }
                count++;
            }
            if(((n-sum)%2==1))
            {
                a[count]=a[n-sum-1];
            }
            sum=sum+count;
            count++;
            fcount=count;
            count=0;
        }
        maxv=a[0];
        
        for(int i=0;i<n;i++)
        {
            if(c[i]==maxv)
            {
                c[i]=-1000000;
                break;
            }
            else
            {
                continue;
            }
        }
        sum=0,count=0,fcount=0;

        while(fcount!=1)
        {
            for(int i=1;i<n-sum;i+=2)
            {
                
                if(c[i]>c[i-1])
                {
                    c[count]=c[i];
                }
                else
                {
                    c[count]=c[i-1];
                }
                count++;
            }
            if(((n-sum)%2==1))
            {
                c[count]=c[n-sum-1];
            }
            
            sum=sum+count;
            count++;
            fcount=count;
            count=0;
        }
        smaxv=c[0];
    }

    void mini()
    {
        int count=0, fcount=0,sum=0;
        while(fcount!=1)
        {
            for(int i=1;i<n-sum;i+=2)
            {
                
                if(b[i]<b[i-1])
                {
                    b[count]=b[i];
                }
                else
                {
                    b[count]=b[i-1];
                }
                count++;
            }
            if(((n-sum)%2==1))
            {
                b[count]=b[n-sum-1];
            }
            
            sum=sum+count;
            count++;
            fcount=count;
            count=0;
        }
        minv=b[0];
        
        for(int i=0;i<n;i++)
        {
            if(d[i]==minv)
            {
                d[i]=1000000;
                break;
            }
            else
            {
                continue;
            }
        }
        sum=0,count=0,fcount=0;

        while(fcount!=1)
        {
            for(int i=1;i<n-sum;i+=2)
            {
                
                if(d[i]<d[i-1])
                {
                    d[count]=d[i];
                }
                else
                {
                    d[count]=d[i-1];
                }
                count++;
            }
            if(((n-sum)%2==1))
            {
                d[count]=d[n-sum-1];
            }
            sum=sum+count;
            count++;
            fcount=count;
            count=0;
        }
        sminv=d[0];
    }

    void disp()
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

logic::logic()
{
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
}

logic::~logic()
{
}

int main()
{
    logic t;
    t.insert_elements(t.n);
    t.maxi();
    t.mini();
    t.disp();
    return 0;
}
