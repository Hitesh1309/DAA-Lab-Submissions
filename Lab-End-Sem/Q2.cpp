// End Semester Exam - Q2
// Hitesh Gupta
// CS20B1127

// Greedy Algorithm for 0-1 Knapsack with all same profits.

#include <bits/stdc++.h>
using namespace std;

bool cmp_func(pair<int, pair<int, float>> &a, pair<int, pair<int, float>> &b)
{
    return a.second.second > b.second.second;
}

int main()
{
    int n, w, p;
    cout << "\nEnter number of objects: ";
    cin >> n;
    cout << "\nEnter profit of all objects: ";
    cin >> p;
    vector<pair<int, pair<int, float>>> M;

    for (int i = 1; i <= n; i++)
    {
        cout << "\nObject " << i << "\nWeight: ";
        cin >> w;

        M.push_back(make_pair(i, make_pair(w, (float)p / (float)w)));
    }

    sort(M.begin(), M.end(), cmp_func);

    int w0, wt = 0;
    float pt = 0;
    cout << "\nEnter maximum weight of knapsack: ";
    cin >> w0;
    cout << endl;

    bool temp = false;

    cout << "\nContents in knapsack: \n";

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
    cout << "\nNet profit: " << pt << endl;

    return 0;
}
