#include<bits/stdc++.h>

using namespace std;

void insertion_sort(int A[],int beg, int end)
{
    int i,j,key;

    for(i=beg+1;i<=end;i++)
    {
        key = A[i];
        j = i-1;

        while(j>=0 && A[j]>key)
        {
            A[j+1] = A[j];    // 0 1 2 3 4 
            j--;
        }

        A[j+1] = key;
    }
}

void merge_sort(int A[], int beg, int mid, int end)   //beg=0 ; end=4 ; mid=2; 0 1 2 | 3 4 
{
    int n1,n2;
    n1 = mid-beg+1;   // n1=3
    n2 = end-mid;     // n2=2

    auto *B = new int[n1];
    auto *C = new int[n2];

    for(int i=0; i<n1; i++)   
        B[i]=A[i+beg];        // i+beg = 0 1 2
    
    for(int j=0;j<n2;j++)
        C[j] = A[mid+1+j];   // j+1+mid = 3 4

    int i,j;
    i=j=0;
    int k=beg;            // 0 1 2 3 | 5 7 - 0 1
    
    while(i<n1 && j<n2)
    {
        if(B[i]<C[j])               // 0 1 3 | 2 4
        {                           // A = 0 1 2 3 
            A[k++]=B[i];
            i++;
        }

        else
        {
            A[k++]=C[j];
            j++;
        }
    }

    while(i<n1)
    {
            A[k++]=B[i];
            i++;
    }

    while(j<n2)
    {
            A[k++]=C[j];
            j++;
    }

}

void sorting_variant(int A[], int beg, int end) 
{
    if(beg+19>=end)
    {
        insertion_sort(A,beg,end);
    }

    else
    {
    int mid;

    mid = (beg+end)/2;

    sorting_variant(A,beg,mid);
    sorting_variant(A,mid+1,end);
    merge_sort(A,beg,mid,end);
    }

}

int main()
{
    int A[10],n,i;

    X:
    cout<<"\nEnter limit: ";
    cin>>n;

    if(n<1)
    {
        cout<<"\nEnter positive number..\n";
        goto X;
    }

    for(i=0;i<n;i++)
    {
        cout<<"\nEnter "<<i+1<<" (st/nd/rd/th) number: ";
        cin>>A[i];
    }

    cout<<"\nDsiplaying array: ";
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    
    cout<<"\n\nSorting the array..\n";
    sorting_variant(A,0,n-1);

    cout<<"\nDsiplaying array: ";
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    
		cout<<"\n"; 
    return 1;
}
