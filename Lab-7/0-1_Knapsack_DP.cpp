#include<bits/stdc++.h>

using namespace std;

struct ds
{
    int index;
    int profit;
    int weight;
};

vector<ds> A;               // a list of profit-weight
int dp[1000][1000] = {0};   // the tabulation of data assigning default value 0

void Knapsack(int w,int &profit,int n)
{
    int r_w,p;   // r_w -> remaining weight | p = temp profit

    for(int i=1;i<=w;i++)   // ds[weight][index]
    {
        for(int j=1;j<=n;j++)
        {
            r_w = i - A[j-1].weight;   // remaining weight
            p = A[j-1].profit;         // profit of the particular (index) value

            if(r_w<0)
                dp[i][j] = dp[i][j-1];      // when object cannot be inserted into knapsack
            
            else            
            dp[i][j] = max ( dp[i][j-1] , dp[r_w][j-1] + p);       // the D.P.
        }
    }

    profit = dp[w][n];     // return profit here since passed as reference

    cout<<"\n\n";

    for(int i=1;i<=w;i++)    // just displaying the D.P. table
    {
        for(int j=1;j<=n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    cout<<"\nEnter no. of objects: ";
    int n;
    cin>>n;

    ds temp;   // temp variable to take in values

    cout<<"\nEnter details of "<<n<<" objects:\n";
    for(int i=1;i<=n;i++)           // taking in weight and profits
    {
        cout<<"\nObject "<<i<<":\n"; temp.index = i;
        cout<<"Weight: "; cin>>temp.weight;
        cout<<"Profit: "; cin>>temp.profit;

        A.push_back(temp);
        cout<<"\n";
    }

    cout<<"\nEnter the maximum weight capacity of knapsack: ";
    int w;
    cin>>w;

    int profit = 0;   // intiallizing profit value

    Knapsack(w,profit,n); // passing profit as reference

    cout<<"\nMax. profit: "<<profit;      // displaying profit at the end
    cout<<"\n\n";
}
