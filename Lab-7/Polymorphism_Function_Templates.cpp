#include<bits/stdc++.h>
using namespace std;

template <typename T>
void printFunc(vector<T> a){
    int n=a.size();
    for(int i=0;i<n;i++){
        cout<<a[i]<<",";
    }
    cout<<endl;
}

template <typename T>
T maxLinear(vector<T> a){
    T max;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(i==0){
            max=a[i];
        }
        else if(a[i]>=max){
            max=a[i];
        }
    }
    return max;
}

template <typename T>
void maxMinLinear(vector<T> a){
    T max,min;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(i==0){
            max=a[i];
            min=a[i];
        }
        else {
            if(a[i]>=max){
            max=a[i];
            }
            if(a[i]<=min){
            min=a[i];
            }
        }
    }
    cout<<"Max value is "<<max<<" and Min value is "<<min<<", computed linearly.\n";
}

template <typename T>
void minMax(vector<T> a,int n){
    printFunc(a);
    int size=n;
    map<T,vector<T>> comps;
    vector<T> temp;
    while(size>1){
        for(int i=size-2;i>=0;i-=2){
            if(a[i]>=a[i+1]){
                if(comps.find(a[i])!=comps.end()){
                    temp=comps.at(a[i]);
                    temp.push_back(a[i+1]);
                }
                else{
                    temp.clear();
                    temp.push_back(a[i+1]);
                }
                comps.erase(a[i]);
                comps.insert(pair<T,vector<T>>(a[i],temp));
                comps.erase(a[i+1]);
                a.erase(a.begin()+i+1);
            }
            else{
                if(comps.find(a[i+1])!=comps.end()){
                    temp=comps.at(a[i+1]);
                    temp.push_back(a[i]);
                }
                else{
                    temp.clear();
                    temp.push_back(a[i]);
                }
                comps.erase(a[i+1]);
                comps.insert(pair<T,vector<T>>(a[i+1],temp));
                comps.erase(a[i]);
                a.erase(a.begin()+i);
            }
        }
        size=(size+1)/2;
        printFunc(a);
    }
    cout<<"Largest value is "<<a[0]<<endl;
    cout<<"Second largest value is "<<maxLinear(comps.at(a[0]))<<endl;
}

--------

#include "functiontemplate.h"

int main(){
    int n,input=-1;

    while(input!=4){
        cout<<"\nEnter 1 for integers.\nEnter 2 for characters.\nEnter 3 for double.\nEnter 4 to exit.\n";
        cin>>input;
        system("clear");
        switch(input){
            case 1:{
                int value=0;
                vector<int> arr;
                cout<<"Enter number of integers in array: ";
                cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"Enter integer "<<i+1<<" :";
                    cin>>value;
                    arr.push_back(value);
                }
                minMax(arr,n);
                maxMinLinear(arr);
            }break;
            case 2:{
                char balue;
                vector<char> brr;
                cout<<"Enter number of characters in array: ";
                cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"Enter character "<<i+1<<" :";
                    cin>>balue;
                    brr.push_back(balue);
                }
                minMax(brr,n);
                maxMinLinear(brr);
            }break;
            case 3:{
                double value=0;
                vector<double> arr;
                cout<<"Enter number of double in array: ";
                cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"Enter integer "<<i+1<<" :";
                    cin>>value;
                    arr.push_back(value);
                }
                minMax(arr,n);
                maxMinLinear(arr);
            }break;
            case 4:{
                cout<<"Thank you for using this program.\n";
            }break;
            default:{
                cout<<"Wrong entry, try again.\n";
            }
        }
    }
    
    return 0;
}
