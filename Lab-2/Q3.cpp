#include<bits/stdc++.h>
using namespace std;

int a=0,b=0,c=0,f=0;

class algo
{
    int n;
    int A[100000];
    int x;

    public:

    void data();
    bool tripsum();
};

bool algo::tripsum()
{
    sort(A,A+n);
    for (int i=0;i<n;i++)
    {
        int point=A[i];
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
            int l=point+A[j]+A[k];
            if(l==x)
            {
                a=A[i];
                b=A[j];
                c=A[k];
                return true;
            }
            if(l<x)
                j++;
            else
                k--;
        }
    }
    return false;
}

void algo::data()
{
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    if(n<3)
    {
        cout<<"Number of elements should be >= 3"<<endl<<"Terminating Program"<<endl;
        f=1;
        return;
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element "<<i+1<<" "<<endl;
        cin>>A[i];
    }
    cout<<"Enter the number whose sum is to be found"<<endl;
    cin>>x;
}

int main()
{
    algo code;
    code.data();
    if(f==1)
        return 0;
    bool p=code.tripsum();
    if(p==true)
    {
        cout<<"Sum exists : "<<a<<"+"<<b<<"+"<<c<<endl;
    }
    else
    {
        cout<<"Sum doesnt exist"<<endl;
    }
    return 0;
}
