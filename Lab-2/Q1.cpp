#include <iostream>
using namespace std;
#define SIZE 999999

class trapWater{
    
    private:
    
        int left[SIZE];
        int right[SIZE];
        int water = 0;
    
    public:
    
        void waterTrapped(int arr[], int n)
        {
            left[0] = arr[0];
            
            for (int i = 1;i < n ;i++) 
            {
                left[i] = max(left[i - 1], arr[i]);
            }
          
            right[n-1] = arr[n-1]; 
            
            for (int i = n - 2;i >= 0;i--) 
            {
                right[i] = max(right[i + 1], arr[i]);
            }
          
            for (int i = 0;i < n;i++) 
            {
                water += max(0, min(left[i], right[i]) - arr[i]);
            }
            
            cout << "The amount of water trapped between the blocks is : " << water << endl;
        }
};

int main()
{
    trapWater t;
    
    int n,i;
    
    cout << "Enter the size of the array : " ;
    
    cin >> n;
    
    while(n<0)
    {
        cout << "Enter a positive integer!!!" << endl;
        cin >> n;
    }
    
    int a[n];
    
    cout << "Enter the height of the blocks in the array : \n" ;
    
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        while(a[i]<0)
        {
            cout << "Enter a positive integer!!!" << endl;
            cin >> a[i];
        }
    }
    
    t.waterTrapped(a,n);
    
    return 0;
}
