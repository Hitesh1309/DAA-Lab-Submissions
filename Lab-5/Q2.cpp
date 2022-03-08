#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b) //function to swap to numbers by reference
{ 
    int t=*a;
    *a=*b;
    *b=t;
} 

void partition(int arr[],int low,int high); //function to make windows recursively

void quickvariant(int arr[],int n); //function which does quicksort by calling the initial partition

int main()
{
    int n;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quickvariant(a,n);
    cout<<"Sorted array is:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void partition(int arr[],int low,int high)
{
    if((high-low+1)<=1) //if the window has 1 element or less just returns
    {
        return;
    }
    else if((high-low+1)==2) //if the window has 2 elements it compares the value and swaps if necessary
    {
        if(arr[low]>arr[low+1])
        {
            swap(&arr[low],&arr[low+1]);
        }
        return;
    }
    else //if window has more than 2 elements
    {
        int x,y,j=low-1,k=low-1; // j is the variable pointing to the vaalue <x, k points to value <y
        x=arr[high-1]; //x is the second last element of window
        y=arr[high]; //y is last element of window
        if(x>y) //if x>y then we swap the value of x and y and the values in the array
        {
            swap(&arr[high-1],&arr[high]);
            swap(x,y);
        }

        for(int i=low;i<high-1;i++) //iterating through all elements through the window till high-2
        {
            j; //made a dumb mistake here :( (j=low-1 should be outside loop)
            k;
            if(arr[i]<=x)
            {
                if(j!=k)
                {
                    j++;
                    k++;
                    swap(&arr[i],&arr[j]);  
                    swap(&arr[i],&arr[k]);
                }
                else
                {
                    j++;
                    k++;
                    swap(&arr[i],&arr[j]);  
                }
            }
            else if(arr[i]>x && arr[i]<y)
            {
                k++;
                swap(&arr[i],&arr[k]);
            }
            else
            {
                //nothing lol
            }
        }
        if(j==k)
        {
            swap(&arr[j+1],&arr[high-1]);
            j++;
            k++;
            swap(&arr[k+1],&arr[high]);
            k++;
            partition(arr,low,j-1);
            partition(arr,j+1,k-1);
            partition(arr,k+1,high);
        }
        else
        {
            swap(&arr[j+1],&arr[high-1]);
            j++;
            swap(&arr[k+1],&arr[high-1]);
            k++;
            swap(&arr[k+1],&arr[high]);
            k++;
            partition(arr,low,j-1);
            partition(arr,j+1,k-1);
            partition(arr,k+1,high);
        }
    }
}

void quickvariant(int arr[],int n)
{
    partition(arr,0,n-1); //partition from a[0] to a[n-1]
}
