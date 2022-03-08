// End Semester Exam - Q3
// Hitesh Gupta
// CS20B1127

// DP Algorithm for (0,1/2,1) Knapsack.

#include<bits/stdc++.h>

using namespace std;

struct data  // a data structure
{
    int index;
    int profit;
    int weight;
};

float dp[1000][1000] = {0.0};  // a dp structure with default value of 0
// dp format is [weight][no. of objects]

int n;  // number of objects
int w_k; //  max weight of knapsack
vector<data> l; // list of objects

float Knapsack()
{
    int r_w,h_r_w; // remaining weight, half remaining weight
    float p,h_p;   // temp profit, half-temp profit

    //dp format is [weight][no. of objects]

    for(int i=1;i<=w_k;i++) // [ i = weight ][ j = no. of objects ]
    {
        for(int j=1;j<=n;j++)
        {
            r_w = i - l[j].weight;
            h_r_w = i - (l[j].weight+1)/2;

            p = (float) l[j].profit;
            h_p = ((float) l[j].profit)/(2.0);

            if(h_r_w < 0)  // cannot include current object
            {
                dp[i][j] = dp[i][j-1];  
            }

            else if( h_r_w >=0 && r_w<0)  // can include half object but not full object
            {   
                dp[i][j] = max ( dp[i][j-1] , dp[h_r_w][j-1] + h_p ); // recursion
            }

            else if(r_w>=0)  // can include half or even full object
            {
                dp[i][j] = max ( dp[i][j-1] , max( dp[h_r_w][j-1] + h_p , dp[r_w][j-1] + p ) ); // recursion
            }
        }
    }

    return dp[w_k][n]; // optimal substructure


    // NOTE: if the weight of the object is odd and considered is its half then the space it takes up is (weight+1)/2
    // that is -> 3/2 = 2 (1.5) | 11/2 = 6 (5.5)
}

int main()
{
    cout<<"\nEnter the number of objects: ";
    cin>>n;

    cout<<"\nEnter the max. weight for knapsack: ";
    cin>>w_k;

    data temp;
    temp.index = 0;
    temp.profit = 0;
    temp.weight = 0;

    l.push_back(temp); // junk value at list[0]

    cout<<"\nEnter "<<n<<" objects data:\n";
    for(int i=1;i<=n;i++)
    {
        cout<<"\nIndex: "<<i;
        temp.index = i;
        cout<<"\nProfit: ";
        cin>>temp.profit;
        cout<<"Weight: ";
        cin>>temp.weight;
        cout<<"\n";

        l.push_back(temp);
    }

    cout<<"Max profit is: "<<Knapsack()<<endl;

    return 0;
}
