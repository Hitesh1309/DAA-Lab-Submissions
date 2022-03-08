// End Semester Exam - Q1
// Hitesh Gupta
// CS20B1127

// Greedy Algorithm for 0-1 Knapsack with all same weights.

#include <bits/stdc++.h>
using namespace std;

// Boolean function to compare two elements.
bool cmp_func(pair<int, pair<int, float>> &a, pair<int, pair<int, float>> &b)
{
    return a.second.second > b.second.second;
}

// Main function.
int main()
{
    int n, w, p;
    // Taking inputs.
    cout << "\nEnter number of objects: ";
    cin >> n;
    cout << "\nEnter weight of all objects: ";
    cin >> w;
    // Creating a vector pair to store total weight,profit and weight.
    vector<pair<int, pair<int, float>>> M;
    // Taking inputs.
    for (int i = 1; i <= n; i++)
    {
        cout << "\nObject " << i << "\nProfit: ";
        cin >> p;

        M.push_back(make_pair(i, make_pair(w, (float)p / (float)w)));
    }
    // Sorting the (profit/weight) ratio in non-increasing order.
    sort(M.begin(), M.end(), cmp_func);

    int w0, wt = 0;
    float pt = 0;
    // Taking input.
    cout << "\nEnter maximum weight of knapsack: ";
    cin >> w0;
    cout << endl;

    bool temp = false;
    // Outputting the input values.
    cout << "\nContents in knapsack: \n";
    // Greedy function.
    for (auto X : M)
    {
        if (X.second.first + wt <= w0)
        {
            temp = true;

            wt += X.second.first;

            cout << "\nIndex: " << X.first;
            cout << "\nWeight: " << X.second.first << endl;

            pt += (float)X.second.first * X.second.second;
        }
    }
    // Outputting the final value.
    cout << "\nNet profit: " << pt << endl;

    return 0;
}
