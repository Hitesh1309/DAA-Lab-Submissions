// End Semester Exam - Q4
// Hitesh Gupta
// CS20B1127

// Listing all feasible solutions of 0-1 Knapsack.

#include<bits/stdc++.h>

using namespace std;

struct data  // a data structure
{
    int index;
    int profit;
    int weight;
};

int n;  // number of objects
int w_k; //  max weight of knapsack
vector<data> l; // list of objects

int MAX;  // this holds the maximum number of subsets possible = 2^n

void check_counter(int index_counter[],int i=0)   // checks the index counter array if its correct and if not corrects it
{
    if(index_counter[i]==0 ||index_counter[i]==1)
        return;
    
    else if(index_counter[i]==2)
    {
        index_counter[i] = 0;
        index_counter[i+1] += 1;
        check_counter(index_counter,i+1);
    }

    else if(index_counter[i]==3)
    {
        index_counter[i] = 1;
        index_counter[i+1] += 1;
        check_counter(index_counter,i+1);
    }
}

// listing out binary format from 0 to 2^n -1 gives all possible combinations of subsets | binary_array[i] = 1 
// then consider the ith index else dont

void feasible_soln(int index_counter[],int counter=0)  // the function that gives all possible subsets
{
    vector<int> li;  // an array/vector to get hold of the subset index(s)
    int total_weight = 0;  
    int total_profit = 0;

    if(counter >= MAX) return;  // if the counter goes above MAX value then exit function

    for(int i=0;i<n;i++)   // going through all indices
    {
        if(index_counter[i])  // to check for the current counter if i(th) position is considered or not
        {
            total_weight += l[i].weight;  // normal sumations respectively 
            total_profit += l[i].profit;
            li.push_back(i+1);  // noting down the index that is included
        }
    }

    cout<<"\nSubset index(s): ";
    for(int x:li) cout<<x<<" ";  // listing out index(s)
    cout<<"\n";

    if(total_weight>w_k) cout<<"Subset not feasible\n";  // if total weight goes above the max weight of knapsack

    else
    {
        cout<<"Subset feasible\nProfit = "<<total_profit<<"\n";  // else
    }

    if(counter<MAX)
    {
        index_counter[0] += 1;  // counter ++ for the next round
        check_counter(index_counter);  // rectify the index_counter which is in binary format
        cout<<"\n";
        feasible_soln(index_counter,counter+1);  // recurse with counter+1
    }
    
}

int main()
{
    cout<<"\nEnter the number of objects: ";
    cin>>n;

    MAX = (int) pow(2,n);  // the maximum number of subsets possible = 2^n

    cout<<"\nEnter the max. weight for knapsack: ";
    cin>>w_k;

    data temp;  // temp variable

    cout<<"\nEnter "<<n<<" objects data:\n";  // taking in values of objects
    for(int i=0;i<n;i++)
    {
        cout<<"\nIndex: "<<i+1;
        temp.index = i;
        cout<<"\nProfit: ";
        cin>>temp.profit;
        cout<<"Weight: ";
        cin>>temp.weight;
        cout<<"\n";

        l.push_back(temp);
    }

    int index_counter[n] ={0} ;  // declaring index counter in binary format for making track for all possible subsets

    cout<<"\nPrinting all possible subsets...\n";

    feasible_soln(index_counter); // calling the function

    return 0;
}
