#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,t;

    cout<<"\nEnter the number of denominations: ";
    cin>>n;

    vector<int> change;
    map<int,int> result;

    change.push_back(1); // default denominations

    cout<<"\nEnter "<<n<<" denominations:\n";
    for(int i=0;i<n;i++)
    {
        cin>>t;
        change.push_back(t);
    }

    sort(change.begin(),change.end(), greater<int>());

    cout<<endl<<"Enter the amount in hand: ";
    int amount;
    cin>>amount;

    for(int X: change)
    {
        while(amount>=X)
        {
            amount -= X;
            result[X]++;
        }
    }

    cout<<"\nCoin change:\n";
    for(int X:change)
    {
        cout<<"Change "<<X<<": "<<result[X]<<endl;
    }

    cout<<endl;
    
}
