// Dynamic Programming code for Matrix Chain Multiplication.

#include <bits/stdc++.h>
using namespace std;

int MCM_DP(int p[], int n)
{

	int m[n-1][n-1];
	int i, j, k, len, val;

	for (i = 1; i < n; i++)
	{
        for(j=1; j<n; j++)
		{
			m[i][j] = 0;
		}
    }

	for (len = 2; len < n; len++)
	{
		for (i = 1; i < n - len + 1; i++)
		{
			j = i + len - 1;
			m[i][j] = INT_MAX;

			for (k = i; k <= j - 1; k++)
			{
				val = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

				if (val < m[i][j])
				{
                    m[i][j] = val;
                }
			}
		}
	}

	cout << "The DP Table is : " << endl;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			cout << m[i][j] << " " ;
		}
		cout << endl;
	}
	cout << "Minimum number of multiplications is " << m[1][n-1] ;
	return m[1][n-1];
}

int main()
{
	cout << "Enter size of array: ";
    int n,value=0;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> value;
        arr[i] = value;
    }

	MCM_DP(arr, n);
    cout << endl;
	return 0;
}
