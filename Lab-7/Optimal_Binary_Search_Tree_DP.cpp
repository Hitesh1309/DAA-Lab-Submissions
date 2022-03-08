// Dynamic Programming code for Optimal Binary Search Tree.

#include <bits/stdc++.h>
using namespace std;

int getTotalCostOfOptimalBST(int keys[], int freq[], int num_keys)
{
    int DP_Table[num_keys][num_keys]{};
    
    for (int j = 0; j < num_keys; ++j)
    {
        for (int i = j; i >= 0; --i)
        {
            int min_total_cost = INT_MAX, sum_freq = accumulate(freq+i, freq+j+1, 0);
            for (int k = i; k <= j; ++k)
            {
                int total_cost = 0,total_cost_left_subtree = 0,total_cost_right_subtree = 0;
                    
                if (k > i)
                {
                    total_cost_left_subtree = DP_Table[i][k-1];
                }
                if (k < j)
                {
                    total_cost_right_subtree = DP_Table[k+1][j];
                }

                total_cost = ( total_cost_left_subtree + total_cost_right_subtree + sum_freq );
                
                if (total_cost < min_total_cost)
                {
					min_total_cost = total_cost;
				}
            }
            DP_Table[i][j] = min_total_cost;
        }
    }
	cout << "The DP Table is : " << endl;
	for(int i=0;i<num_keys;i++)
	{
		for(int j=0;j<num_keys;j++)
		{
			cout << DP_Table[i][j] << " " ;
		}
		cout << endl;
	}
	cout << "Cost of Optimal BST is " << DP_Table[0][num_keys-1];
    return DP_Table[0][num_keys-1];
}

int main()
{
	int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int keys[n];
    int freq[n];
    for(int i=0;i<n;i++)
    {
        cout << "Enter the " << i+1 << "th element and its frequency" << endl;
        cin >> keys[i];
        cin >> freq[i];
    }
	getTotalCostOfOptimalBST(keys, freq, n);
    cout << endl;
	return 0;
}
