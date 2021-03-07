#include <bits/stdc++.h>

using namespace std;
string add(string f0,string f1)
{
    string fs = "";
    if(f0.length()>f1.length())
    {
        swap(f0,f1);
    }
    int n0 = f0.length(),n1 = f1.length();
    int carry = 0,differnce = n1 - n0;
    for(int i = n0-1; i >= 0; i--)
    {
        int sum = (f0[i] - '0')+(f1[i+differnce] - '0')+carry;
        fs.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for(int i = n1-n0-1; i>=0; i--)
    {
        int sum = f1[i] - '0' + carry;
        fs.push_back(sum%10 + '0');
        carry /= 10;
    }
    while(carry != 0)
    {
        fs.push_back(carry%10 + '0');
        carry /= 10;
    }
    reverse(fs.begin(),fs.end());
    return fs;
}
string store[6000];
string fibo(int n)
{
    string f0,f1;
    f0 += '0';
    f1 += '1';
    if(n == 0)return f0;
    if(n == 1)return f1;
    if(store[n].length() != 0)return store[n];
    else{
        store[n] = add(fibo(n-1) , fibo(n-2));
        return add(fibo(n-1),fibo(n-2));
    }
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        string fs;
        fs = fibo(n);
        cout<<"The Fibonacci number for "<<n<<" is "<<fs<<endl;
    }
    return 0;
}
