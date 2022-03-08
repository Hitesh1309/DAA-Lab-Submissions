#include<iostream>
#include<vector>
#define LARGE 99;
using namespace std;

void CMM_GM(vector<int> a,int n){
    int min=LARGE;
    int index=1;
    int size=n;
    vector<int> ans, arr=a;
    int total=0;
    while(size>=3){
        min=LARGE;index=1;
        for(int i=1;i<size-1;i++){
            if(a[i-1]*a[i]*a[i+1]<min){
                min=a[i-1]*a[i]*a[i+1];
                index=i;
            }
        }
        total+=min;
        cout<<"+"<<a[index-1]<<"*"<<a[index]<<"*"<<a[index+1]<<endl;
        size--;
        a.erase(a.begin()+index);
    }
    cout<<"="<<total;
    for(int i=0;i<ans.size();i++){
        
    }
}

int main()
{
    cout<<"Enter size of array: ";
    int n,value=0;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<":";
        cin>>value;
        arr.push_back(value);
    }
    CMM_GM(arr,n);

    return 0;
}
