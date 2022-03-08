#include<iostream>
using namespace std;
#define SIZE 999999

class stackArr{
    private:
    int arr[SIZE];
    int h1,h2;
    
    public:
    stackArr(){
        h1=-1;
        h2=SIZE;
    }
    void push1(int n){
        if(h1==h2-1){
            cout<<"Stack Overflow\n";
            return;
        }
        else{
            h1++;
            arr[h1]=n;
        }
    }
    void pop1(){
        if(h1==-1){
            cout<<"Stack Underflow\n";
            return;
        }
        else{
            cout<<"Popped value is "<<arr[h1]<<"\n";
            h1--;
        }
    }
    void push2(int n){
        if(h1==h2-1){
            cout<<"Stack Overflow\n";
            return;
        }
        else{
            h2--;
            arr[h2]=n;
        }
    }
    void pop2(){
        if(h2==SIZE){
            cout<<"Stack Underflow\n";
            return;
        }
        else{
            cout<<"Popped value is "<<arr[h2]<<"\n";
            h2++;
        }
    }
};

int main(){
    stackArr arr;
    int choice=-1,n;
    while(choice!=5){
        cout<<"\nEnter a menu option:\n";
        cout<<"1)Push to stack 1\n";
        cout<<"2)Pop from stack 1\n";
        cout<<"3)Push to stack 2\n";
        cout<<"4)Pop from stack 2\n";
        cout<<"5)Exit\n";
        cin>>choice;
        system("clear");
        switch(choice){
            case 1:{
                cout<<"Enter value to push: ";
                cin>>n;
                arr.push1(n);
                break;
            }
            case 2:arr.pop1();break;
            case 3:{
                cout<<"Enter value to push: ";
                cin>>n;
                arr.push2(n);
                break;
            }
            case 4:arr.pop2();break;
            case 5:break;
            default:cout<<"Wrong input, try again\n\n";
        }
    }
    return 0;
}
