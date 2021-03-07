#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int temp = (((((n*567)/9)+7492)*235)/47) - 498;
        temp = temp/10;
        temp = temp%10;
        if(temp< 0)temp *= -1;
        cout<<temp<<endl;
    }
    return 0;
}

