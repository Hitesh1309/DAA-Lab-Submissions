// Hitesh Gupta
// CS20B1127

#include<bits/stdc++.h>
using namespace std;

// Function to covert decimal to binary.
string toBinary(long int n)
{
    string r;
    while(n!=0) 
    {
        r=(n%2==0 ?"0":"1")+r; 
        n/=2;
    }
    return r;
}

// Function to convert binary to decimal.
int toDecimal(string s)
{
    long int value = 0; 
    long int indexCounter = 0; 
    for(long int i = s.length()-1; i >= 0; i--) 
    { 
    if(s[i] == '1') 
        { 
        value += pow(2, indexCounter); 
        } 
    indexCounter++; 
    } 
    return value; 
}

// Function to multiply two binary numbers.
string multiply(string num1, string num2) 
{
    if (num1 == "0" || num2 == "0") 
    {
        return "0";
    }

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int N = num1.size() + num2.size();
    string answer(N, '0');
                
    for (int place2 = 0; place2 < num2.size(); place2++) {
        int digit2 = num2[place2] - '0';
                
        for (int place1 = 0; place1 < num1.size(); place1++) {
            int digit1 = num1[place1] - '0';
                    
            int numZeros = place1 + place2;
                    
            int carry = answer[numZeros] - '0';
            int multiplication = digit1 * digit2 + carry;
                        
            answer[numZeros] = (multiplication % 2) + '0';
                        
            answer[numZeros + 1] += (multiplication / 2);
        }
    }
                
    if (answer.back() == '0') 
    {
        answer.pop_back();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

// Main function.
int main()
{
    long int n,m;
    string a,b,result;
    cout << "Please Enter the two numbers." << endl;
    cout << "First Number :";
    cin >> n ;
    cout << "Second Number : ";
    cin >> m;

    a = toBinary(n);
    b = toBinary(m);

    cout << "The binary representation of " << n << " is : " << a << endl;
    cout << "The binary representation of " << m << " is : " << b << endl;
    cout << "The binary representation of the product is : " << (multiply(a,b)) << endl;

    result = multiply(a,b);
    
    cout << "The decimal representation of the product is : " ;
    if((n>0&&m>0) || (n<0&&m<0))
    {
        cout << toDecimal(result) << endl;
    }
    else
    {
        cout << "(-" << toDecimal(result) << ")" << endl;
    }
    return 0;
}
