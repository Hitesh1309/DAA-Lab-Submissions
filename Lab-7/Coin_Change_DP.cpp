#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,t;
    cout<<"\nEnter no. of denominations (where 1 would be auto added): ";
    cin>>n;

    vector<int> change;   //vector of denominations
    map<int,int> record;  // map of amount - minimum number of denominations

    cout<<"\nInserted a base denomination 1\nEnter "<<n-1; cout<<" denominations:\n";

    change.push_back(1);
    record[1] = 1;

    for(int i=1;i<n;i++)
    {
        cin>>t;
        change.push_back(t);
        record[t] = 1;     // assign minimum value
    }

    record[0] = 0;    //assign to 0 value

    int amount;

    A:
    cout<<"\nEnter total amount: ";
    cin>>amount;

    if(amount<0)
    {
        cout<<"\nEnter amount again..\n";
        goto A;
    }

    int m;

    for(int i=1;i<=amount;i++)
    {
        if(record[i]!=0)
            continue;
        
        else
        {
            m = INT_MAX;

            for(int X:change)
            {
                if(i-X>0)     // to check out of bounds
                {
                    m = min(m,record[i-X]+1);     // iteratively assigning min value
                }
            }

            record[i] = m;
        }
    }

    cout<<"\nMinimum number of denominations required for "<<amount<<" is: "<<record[amount];
    cout<<"\n\n";

}
