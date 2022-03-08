// Hitesh Gupta
// CS20B1127

#include <bits/stdc++.h>
using namespace std;

// Function to swap two numbers.
void swap(int* num1, int* num2) 
{ 
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
} 

// Function to create 2 pivots and swap the numbers.
void part(int a[],int min,int max)
{
    if((max-min+1) <= 1)
    {
        return;
    }
    else if((max-min+1) == 2)
    {
        if(a[min] > a[min+1])
        {
            swap(&a[min],&a[min+1]);
        }
        return;
    }
    else
    {
        int x,y,f=min-1,g=min-1;
        x=a[max-1];
        y=a[max];
        if(x > y)
        {
            swap(&a[max-1],&a[max]);
            swap(x,y);
        }

        for(int i=min; i<max-1; i++)
        {
            f; //<x partition
            g; //btw x and y partition
            if(a[i] <= x)
            {
                f++;
                g++;
                swap(&a[i],&a[f]);
                swap(&a[i],&a[g]);
            }
            else if(a[i] > x && a[i] < y)
            {
                g++;
                swap(&a[i],&a[g]);
            }
            else
            {}
        }
        if(f == g)
        {
            swap(&a[f+1],&a[max-1]);
            f++;
            g++;
            swap(&a[g+1],&a[max]);
            g++;
            part(a,min,f-1);
            part(a,f+1,g-1);
            part(a,g+1,max);
        }
        else
        {
            swap(&a[f+1],&a[max-1]);
            f++;
            swap(&a[g+1],&a[max-1]);
            g++;
            swap(&a[g+1],&a[max]);
            g++;
            part(a,min,f-1);
            part(a,f+1,g-1);
            part(a,g+1,max);
        }
    }
}

void quickvariant(int a[],int n)
{
    part(a,0,n-1);
}

// Main function.
int main()
{
    int n;
    cout << "Please Enter number of elements." << endl;
    cin >> n;
    int a[n];
    cout << "Enter the elements" << endl;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    quickvariant(a,n);
    cout << "Sorted array is:" << endl;
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
