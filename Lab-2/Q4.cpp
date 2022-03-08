#include<iostream>

using namespace std;

class algo 
{
    int sum=0, i, j, k;
    
    public:
        
        void subsum(int A[], int n)
        {   
            for(i=0;i<=n-1;i++)
            {
                k=i;
                
                while(k<=n-1)
                {
                    sum=0;
                    cout<<"\nSum of subset [ ";
                    
                    for(j=i;j<=k;j++)
                    {
                        cout<<A[j]<<" ";
                        sum+=A[j];
                    }
                    
                    cout<<"]: "<<sum;
                    
                    k+=1;
                }
            }
            
        }
        
    
};

int main()
{
    int A[10],n,i;
    algo a;
    
    A:
    
    cout<<"Enter array limit: ";
    cin>>n;
    
    if(n<=0)
    {   
        cout<<"\nEnter positive number\n";
        goto A;
    }

    cout<<"Enter "<<n<<" numbers:\n";
    
    for(i=0;i<n;i++)
        cin>>A[i];
        
    cout<<endl<<endl;
        
    a.subsum(A,n);
    
    cout<<endl;
    
}
