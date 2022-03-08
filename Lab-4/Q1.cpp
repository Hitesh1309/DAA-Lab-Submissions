#include<bits/stdc++.h>

using namespace std;

void swap(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

void bubble_sort(int A[],int n)
{
    int i;

    if(n<=1)
        return;

    for(i=0;i<n-1;i++)
    {
        if(A[i]>A[i+1])
            swap(A[i],A[i+1]);
    }

    bubble_sort(A,n-1);

}

void selection_sort(int A[], int n)
{
    int i,j,min;

    for(i=0;i<n-1;i++)
    {
        min = i;

        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
                min = j;
        }

        swap(A[min],A[i]);
    }
}

void insertion_sort(int A[], int n)
{
    int i,j,key;

    for(i=1;i<n;i++)
    {
        key = A[i];
        j = i-1;

        while(j>=0 && A[j]>key)
        {
            A[j+1] = A[j];
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
    int k=beg;
    
    while(i<n1 && j<n2)
    {
        if(B[i]<C[j])
        {
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

void two_way_merge_sort(int A[], int beg, int end)
{
    if(beg>=end)
        return;

    int mid;

    mid = (beg+end)/2;

    two_way_merge_sort(A,beg,mid);
    two_way_merge_sort(A,mid+1,end);
    merge_sort(A,beg,mid,end);

}

void top_down_heapify(int A[],int i)
{
    int p,t;

    if(i%2==1)
    {
        p = (i-1)/2;
    }

    else
    {
        p = (i-2)/2;
    }

    if(p>=0 && A[i]>A[p])
    {
        swap(A[i],A[p]);

        top_down_heapify(A,p);
    }
}

void re_heap(int A[],int n,int p)
{
    int i1 = 2*p + 1;
    int i2 = 2*p + 2;

    if(i1>=n)
        return;
    
    else if(i1<n && i2>=n)
    {
        if(A[p]<A[i1])
        {   
            swap(A[p],A[i1]);
        }
    }

    else if(i1<n && i2<n)
    {
        if(A[i1]>A[p] && A[i1]>A[i2])
        {   swap(A[i1],A[p]);
            re_heap(A,n,i1);
        }
        
        else if(A[i2]>A[p] && A[i2]>A[i1])
        {   swap(A[i2],A[p]);
            re_heap(A,n,i2);
        }
        
        else
            return;
    }
}

void heap_sort(int A[], int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        swap(A[0],A[n-1-i]);
        re_heap(A,n-1-i,0);
    }
}

int main()
{
    int choice;
    int n;
    B:
    cout<<"\nEnter limit: ";
    cin>>n;

    if(n<1)
    {
        cout<<"\nEnter positive limit..\n";
        goto B;
    }

    auto *A = new int[n];

    int i;
    cout<<"\nEnter "<<n<<" numbers:\n";
    for(i=0;i<n;i++)
        cin>>A[i];
    
    while (1)
    {
        cout<<"\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Merge Sort\n5.Heap Sort\n6.Exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"\nSorting: ";
                bubble_sort(A,n);

                for(i=0;i<n;i++)
                    cout<<A[i]<<" ";
                
                cout<<endl;
                break;
            }
            case 2:
            {
                cout<<"\nSorting array using selection sort...\n";

                selection_sort(A,n);

                cout<<"\nPrinting sorted array:\n";

                for(i=0;i<n;i++)
                    cout<<A[i]<<" ";
                
                cout<<endl;
                break;
            }
            case 3:
            {
                cout<<"\nDoing insertion sort...\n";

                insertion_sort(A,n);

                cout<<"\nDisplaying sorted array:\n";

                for(i=0;i<n;i++)
                    cout<<A[i]<<" ";

                cout<<endl;
                break;
            }
            case 4:
            {
                cout<<"\n\nSorting the array..\n";
                two_way_merge_sort(A,0,n-1);

                cout<<"\nDsiplaying array: ";
                for(i=0;i<n;i++)
                    cout<<A[i]<<" ";
                break;
            }
            case 5:
            {
                for(i=0;i<n;i++)
                    top_down_heapify(A,i);
                
                cout<<"\nSorting: ";

                heap_sort(A,n);

                for(i=0;i<n;i++)
                    cout<<A[i]<<" ";
                
                cout<<endl;
                break;
            }
            case 6:
            {
                exit(1);
            }
        }
    }
    return 0;
}
