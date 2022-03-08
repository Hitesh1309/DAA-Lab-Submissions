#include<iostream>
using namespace std;

//The algorithm function
int negCounter(int*,int,int,int);

//The main function
int main(){
    //Variable declaration
    int n,i;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    int *a=new int[n];
    for(i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<" : ";
        cin>>a[i];
    }
    int ans1=negCounter(a,0,n-1,2);
    cout<<"Ans when fac is 2 :"<<ans1<<"\n";
    int ans2=negCounter(a,0,n-1,3);
    cout<<"Ans when fac is 3 :"<<ans2<<"\n";
    return 0;
}

int negCounter(int* a,int beg,int end,int fac=2){
    //Counter declaration
    int counter=0;
    //Base case
    if(end-beg<fac-1){
        for(int i=beg;i<=end;i++){
            //To show examined chunk
            cout<<end<<","<<beg<<endl;
            cout<<"checked "<<a[i]<<endl;
            if(a[i]<0){
                counter++;
            }
        }
        return counter;
    }
    else{
        if(fac==3){
            //Dividing array into 3 parts
            int mid1=((end-beg)/fac)+beg;
            int mid2=((2*(end-beg))/fac)+beg;

            //To show chunks to be divided
            cout<<beg<<","<<mid1<<","<<mid2<<","<<end<<endl;

            //Recursion call
            counter+=negCounter(a,beg,mid1,fac)+negCounter(a,mid1+1,mid2,fac)+negCounter(a,mid2+1,end,fac);
            return counter;
        }
        else{
            //Dividing array into 2 parts
            int mid=((end-beg)/fac)+beg;

            //To show chunks to be divided
            cout<<beg<<","<<mid<<","<<end<<endl;

            //Recursion call
            counter+=negCounter(a,beg,mid,fac)+negCounter(a,mid+1,end,fac);
            return counter;
        }
    }
}
