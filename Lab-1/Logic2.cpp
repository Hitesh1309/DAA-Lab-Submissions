/*
Logic :-
Heap 
Algorithm :

- Create a max heap using the numbers in the array, take the front/root of the heap and you get the maximum value of the array.
- After getting the maximum value, pop/remove the root and the heap rearranges so that the second maximum element takes the value of new root, and we know the second maximum of the array.
- Similarly, create a min heap using a boolean function, and get the minimum and the second minimum of the given array of integers from the min heap.

*/

#include<iostream>
#include<algorithm>

using namespace std;

class heap
{
    public:
        int n,maxv,smaxv,minv,sminv;
        heap();
        int a[10000];
        ~heap();
    
    static bool compare(int a, int b)
    {
        if(a<b)
            return 0;
        else 
            return 1;
    }

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
        make_heap(a,a+n);
        maxv=a[0];
        pop_heap(a,a+n);
        smaxv=a[0];
    }

    void minelement()
    {
        make_heap(a,a+n,compare);
        minv=a[0];
        pop_heap(a,a+n,compare);
        sminv=a[0];
    }
    
    void display()
    {
        if(n==0)
        {
            return ;
        }
        else if(n==1)
        {
            cout<<"\nThe Maximum value in the array is "<<maxv<<endl;
            cout<<"The Minimum value in the array is "<<minv<<endl;
            cout<<"Second min and max do not exist"<<endl;
        }
        else
        {
            cout<<"\nThe Maximum value in the array is "<<maxv<<endl;        
            cout<<"The Minimum value in the array is "<<minv<<endl;
            cout<<"\nThe Second Maximum value in the array is "<<smaxv<<endl;
            cout<<"The Second Minimum value in the array is "<<sminv<<endl;
        }
    }
};

heap::heap()
{
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;
    while(n<0)
    {
        cout<<"Enter a positive number"<<endl;
        cin>>n;
    }
}

heap::~heap()
{    
}

int main()
{
    heap h;
    h.insert_elements(h.n);
    h.minelement();
    h.maxelement();
    h.display();
    return 0;
}
