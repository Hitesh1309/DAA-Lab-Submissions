#include <bits/stdc++.h>
using namespace std;

class Insert
{
    public:
        int arr[100],pos;

        int binarySearch(int arr[],int num,int min,int max)
        {
            while(min <= max)
            {
                int middle = min + (max - min)/2;
                if(num == arr[middle])
                {
                    return (middle+1);
                }
                else if(num > arr[middle])
                {
                    min = middle + 1 ;
                }
                else
                {
                    max = middle - 1;
                }
            }
            return min;
        }

        void insertionVariant(int arr[],int n)
        {
            int i,j,element;

            for(i=0; i<n; ++i)
            {
                j = i-1;
                element = arr[i];

                pos = binarySearch(arr, element, 0, j);

                while(j >= pos)
                {
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = element;
            }
        }

        void printArray(int arr[],int n)
        {
            int i;
            cout <<"\nSorted array: \n";
            for (i = 0; i < n; i++)
            {
                cout <<" "<< arr[i];
            }
            cout << endl;
        }
};

int main()
{
    Insert a1;
    int n,i;
    cout << "Enter the size of the array." << endl;
    cin >> n;
    int arr[n];
    for(i = 0; i <n ; i++)
    {
        cout << "Enter element " << i+1 << " : " ;
        cin >> arr[i];
    }
    a1.insertionVariant(arr,n);
    a1.printArray(arr,n);
    return 0;
}
