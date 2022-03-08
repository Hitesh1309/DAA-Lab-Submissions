/*
Logic:-
Element reduction 

- Seperating array into positve (inlcuding 0) and negative numbers
- In +ve numbers array (including 0) reducing each elements by 1 in iterative manner and what element reaches 0 first is the minimum element and the element reaching 0 last is the maximum element (checking first and then reduction of elements)
- In -ve numbers array increasing every element by 1 in iterative manner and which element reaches 0 first is the maximum element and the element reaching 0 last is the minimum element
- Similar manner to find second maximum and minimum for those two arrays
- Then comparing those results to determine the final MAX, SMAX, SMIN, MIN values

*/

#include<iostream>
using namespace std;

struct result 
{
  int max, min, smax, smin;
 
};

class value 
{
public:
result p, n;
  
int i;
  
void res (int B[], int C[], int b, int c) 
  {
    int l = 0, k = 0, flag = 1;
    
 
if (b == 1)
      
      {
	
p.max = p.min = B[0];
      
 
}
    
 
    else if (b > 1)
      
while (flag)
	
	{
	  for (i = 0; i < b; i++)
	    
	    {
	      if (B[i] == 0)
		
		{
		  B[i] += k;
		  
l += 1;
		  
if (l == 1)
		    
p.max = p.smax = p.smin = p.min = B[i];
		  
		  else if (l == 2)
		    
p.max = p.smin = B[i];
		  
		  else
		    
		    {
		      p.smax = p.max;
		      
p.max = B[i];
		    
}
		  
B[i] = 0;
		  
if (l == b)
		    
		    {
		      flag = 0;
		      
break;
		    
}
		
 
}
	    
}
	  
for (i = 0; i < b; i++)
	    
B[i] -= 1;
	  
k += 1;
	
}
    
l = 0;
    
flag = 1;
    
k = 0;
    
 
if (c == 1)
      
      {
	
n.max = n.min = C[0];
      
}
    
 
    else if (c > 1)
      
while (flag)
	
	{
	  for (i = 0; i < c; i++)
	    
	    {
	      if (C[i] == 0)
		
		{
		  C[i] -= k;
		  
l += 1;
		  
if (l == 1)
		    
n.max = n.smax = n.smin = n.min = C[i];
		  
		  else if (l == 2)
		    
n.min = n.smax = C[i];
		  
		  else
		    
		    {
		      n.smin = n.min;
		      
n.min = C[i];
		    
}
		  
C[i] = 0;
		  
if (l == c)
		    
		    {
		      flag = 0;
		      
break;
		    
}
		
}
	    
}
	  
for (i = 0; i < c; i++)
	    
C[i] += 1;
	  
k += 1;
	
}
    
 
if (b == 1 && c == 0)
      
cout << "\nOne element array therefore max and min element is: " << p.
	max << "\nSecond max and min do not exist\n";
    
 
    else if (c == 1 && b == 0)
      
cout << "\nOne element array therefore max and min element is: " << n.
	max << "\nSecond max and min do not exist\n";
    
 
    else if (b > 1 && c > 1)
      
cout << "\nMax : " << p.max << "\nSecond max " << p.
	smax << "\nSecond min : " << n.smin << "\nMin : " << n.min << endl;
    
    else if (b == 1)
      
cout << "\nMax : " << p.max << "\nSecond max " << n.
	max << "\nSecond min : " << n.smin << "\nMin : " << n.min << endl;
    
    else if (c == 1)
      
cout << "\nMax : " << p.max << "\nSecond max " << p.
	smax << "\nSecond min : " << p.min << "\nMin : " << n.min << endl;
    
 
    else if (c == 0)
      
cout << "\nMax : " << p.max << "\nSecond max " << p.
	smax << "\nSecond min : " << p.smin << "\nMin : " << p.min << endl;
    
    else
      
cout << "\nMax : " << n.max << "\nSecond max " << n.
	smax << "\nSecond min : " << n.smin << "\nMin : " << n.min << endl;
  
}

};


int main()
{ int A[10],B[10],C[10],a,b=0,c=0,i;
A:
cout<<"\nEnter no. of numbers (only positive number): ";
cin>>a;
if(a<=0)
{ cout<<"Enter positive number...";
goto A;
}
cout<<"Enter "<<a<<" numbers:\n";
for(i=0;i<a;i++)
cin>>A[i];
for(i=0;i<a;i++)
{ if(A[i]>=0)
B[b++]=A[i];
else
C[c++]=A[i];
}
value V;
V.res(B,C,b,c);
return 0;
}
