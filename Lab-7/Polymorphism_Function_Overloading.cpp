#include<bits/stdc++.h>

using namespace std;

struct ds
{
    int index;
    int profit;
    int weight;
};

bool cmp_func(pair<int, pair<float, float>> &a, pair<int, pair<float, float>> &b)
        {
             return a.second.second > b.second.second;
        }

vector<ds> A;               // a list of profit-weight
int dp[1000][1000] = {0};   // the tabulation of data assigning default value 0

void bubsort(int n)
{
    for(int i=0;i<n-1;i++)
    {    
        for(int j=0;j<n-i-1;j++)
        {
            if (A[j].weight>A[j+1].weight)
            {
                int t=A[j].weight;
                A[j].weight=A[j+1].weight;
                A[j+1].weight=t;
            }
        }
    }
}

void Knapsack(int w,int &profit,int n,bool flag = true)
{
    if(flag==true){
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

    else if(flag==false)
    {
        vector<pair<int, pair<float, float>>> M;  // 3 properties in the form of a vector - index | weight | profit / weight

        float w,p;

    for (int i = 1; i <= n; i++)
    {
        
        w = (float)A[i-1].weight;
        p = (float)A[i-1].profit;

        M.push_back(make_pair(i, make_pair(w, (float)p / (float)w)));
    }

    sort(M.begin(), M.end(), cmp_func);

    float w0, wt = 0;
    float pt = 0.0;
    cout << "\nEnter maximum weight of fractional knapsack: ";
    cin >> w0;
    cout << endl;

    bool temp = false;
    float remain;

    cout << "\nContents in knapsack: \n";

    for (auto X : M)
    {
        if (temp == true && X.second.first + wt > w0 && wt != w0)
        {
            remain = (float)(w0 - wt) / (float)X.second.first;

            cout << "\nIndex: " << X.first;
            cout << "\nWeight: " << X.second.first << " | Propotion: " << remain << endl;
            wt = w0;
            pt += (float)X.second.first * X.second.second * remain;
            break;
        }

        if (X.second.first + wt <= w0)
        {
            temp = true;

            wt += X.second.first;

            cout << "\nIndex: " << X.first;
            cout << "\nWeight: " << X.second.first << endl;

            pt += (float)X.second.first * X.second.second;
        }
    }

    cout<<"\nFractional Knapsack profit: "<<pt<<"\n";
    }

}

void Knapsack(int w,double &profit,int n)
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

    profit = (double) dp[w][n];     // return profit here since passed as reference
}

int Knapsack(int W,int n)
{
    int m=0;
    bubsort(n);
    for(int i=0;i<n;i++)
    {
        if(A[i].weight<=W)
        {
            m++;
            W=W-A[i].weight;
        }
        else
        {
            break;
        }
    }
    return m;
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

    double p = 0.0;

    Knapsack(w,p,n);

    cout<<"\nMax. profit in double: "<<(double) p;
    cout<<"\n\n";

    Knapsack(w,profit,n,false);          // fractional knapsack
    cout<<"\n\n";

    cout<<"Enter the weight for variant Knapsack: ";
    cin>>w;
    int m=Knapsack(w,n);
    cout<<"The objects that can be in the Knapsack are: "<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<"Object no: "<<i+1<<" of Weight: "<<A[i].weight<<endl;
    }
}
