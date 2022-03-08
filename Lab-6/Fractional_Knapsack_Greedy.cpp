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

    vector<pair<int, pair<int, float>>> M;

    for (int i = 1; i <= n; i++)
    {
        cout << "\nObject " << i << "\nWeight: ";
        cin >> w;
        cout << "Profit: ";
        cin >> p;

        M.push_back(make_pair(i, make_pair(w, (float)p / (float)w)));
    }

    sort(M.begin(), M.end(), cmp_func);

    int w0, wt = 0;
    float pt = 0;
    cout << "\nEnter maximum weight of knapsack: ";
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

    cout << "\nNet profit: " << pt << endl;
}
