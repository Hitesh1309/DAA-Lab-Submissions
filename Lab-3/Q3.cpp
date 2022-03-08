#include <iostream>

using namespace std;

void bubble_sort(int A[], int n)
{
    int i,j,t;
    
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                t = A[j+1];
                A[j+1] = A[j];
                A[j] = t;
            }
        }
    }
}

void BS_I(int A[], int n, int i)
{
    int flag = 0;
    int beg, end, mid;
    beg = 0;
    end = n;
    
    mid = (beg+end)/2;
    
    while(beg<end)
    {
        
        if(A[mid]==i)
        {
            cout<<"\nNumber found at position "<<mid+1<<endl;
            cout<<"A["<<mid<<"] = "<<i<<endl;
            flag = 1;
            break;
        }
        
        if(i<A[mid])
        {
            end = mid;
        }
        
        else
        {
            beg = mid+1;
        }
        
        mid = (beg+end)/2;
    }
    
    if(flag == 0)
    {    
        cout<<"\nNumber not found\n";
    }
}

void BS_R(int A[], int beg, int end, int i)
{
    int mid = (beg+end)/2;
    
    if(beg==end)
    {
        cout<<"\nNumber not found\n";
    }
    
    else
    {
       if(A[mid]==i)
        {
            cout<<"\nNumber found at position "<<mid+1<<endl;
            cout<<"A["<<mid<<"] = "<<i<<endl;
        }
        
        else if(i<A[mid])
        {
            BS_R(A,beg,mid,i);
        }
        
        else 
        {
            BS_R(A,mid+1,end,i);
        }
    }
}

void TS_I(int A[], int n, int i)
{
    int flag = 0;
    int beg, end, mid1, mid2;
    beg = 0;
    end = n;

    while(beg<end)
    {
        mid1 = (beg+end)/3;
        mid2 = 2*mid1;

        if(A[mid1]==i)
        {
            cout<<"\nNumber found at position "<<mid1+1<<endl;
            cout<<"A["<<mid1<<"] = "<<i<<endl;
            flag = 1;
            break;
        }

        else if(A[mid2]==i)
        {
            cout<<"\nNumber found at position "<<mid2+1<<endl;
            cout<<"A["<<mid2<<"] = "<<i<<endl;
            flag = 1;
            break;
        }

        else if(i<A[mid1])
        {
            end = mid1;
        }

        else if(i>A[mid1]&&i<A[mid2])
        {
            beg = mid1+1;
            end = mid2;
        }

        else if(i>A[mid2])
        {
            beg = mid2+1;
        }
    }

    if(flag==0)
    {    
        cout<<"\nNumber not found\n";
    }
}

void TS_R(int A[],int beg, int end, int i)
{
    int mid1, mid2;

    mid1 = (beg+end)/3;
    mid2 = 2*mid1;

    if(beg>=end)
    {
        cout<<"\nNumber not found\n";
    }

    else if(A[mid1]==i)
    {
        cout<<"\nNumber found at position "<<mid1+1<<endl;
        cout<<"A["<<mid1<<"] = "<<i<<endl;
    }

    else if(A[mid2]==i)
    {
        cout<<"\nNumber found at position "<<mid2+1<<endl;
        cout<<"A["<<mid2<<"] = "<<i<<endl;
    }

    else if(i<A[mid1])
    {
        TS_R(A,beg,mid1,i);
    }

    else if(i>A[mid1]&&i<A[mid2])
    {
        TS_R(A,mid1+1,mid2,i);
    }

    else if(i>A[mid2])
    {
        TS_R(A,mid2+1,end,i);
    }
}


int main()
{
    int A[10], n, i;
    
    A:

    cout<<"Enter limit: ";
    cin>>n;
    
    if(n<0)
    {
        cout<<"\nEnter +ve limit\n";
        cout<<"To exit code enter 0 : ";
        cin>>n;

        if(n==0)
            exit(0);
        
        goto A;
    }

    cout<<"\nEnter "<<n<<" numbers:\n";
    
    for(i=0;i<n;i++)
        cin>>A[i];
        
    cout<<"\nDisplaying array: ";
    
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
        
    bubble_sort(A,n);
    
    /*
    cout<<"\nDisplaying sorted array: ";
    
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
        
    */
    
    cout<<"\nEnter number to search: ";
    cin>>i;
    
    cout<<"\nDoing binary search:\n\nIterative:\n";
    
    BS_I(A,n,i);
    
    cout<<"\nRecursive:\n";
    
    BS_R(A,0,n,i);

    cout<<"\nDoing ternary search:\n\nIterative:\n";

    TS_I(A,n,i);

    cout<<"\nRecursive:\n";

    TS_R(A,0,n,i);
      
    return 0;  
}
