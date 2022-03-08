#include<bits/stdc++.h>
using namespace std;
 
void SortDictionary(string arr[], int n)
{
   int index[n];
   int i, j, min;
     
   for (i=0; i<n; i++)
   {
      index[i] = i;
   }

   for (i=0; i<n-1; i++)   
   {
      min = i;
      for (j=i+1; j<n; j++)
      {
         if (arr[index[min]].compare(arr[index[j]]) > 0)
         {
            min = j;
         }
      }
         
      if (min != i)
      {
         int temp = index[min];
         index[min] = index[i];
         index[i] = temp;
      }
   }
     
   for (i=0; i<n; i++)
   {
      cout << i+1 << ". " << arr[index[i]] << " \n";
   }
}
 
int main()
{
   int num;

   cout << "Enter the number of words/strings : " << endl;
   cin >> num;
   cin.ignore(1024, '\n');

   string arr[num];

   for (int i = 0; i < num; ++i) 
   {
      getline(cin,arr[i]);
   }

   cout << "\nThe strings in the dictionary order: " << endl;
   SortDictionary(arr, num);

   return 0;
}
