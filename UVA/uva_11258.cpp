#include <bits/stdc++.h>
using namespace std;
string a;
int len_a;
long long dp[220];
bool if_strto_num()
{
    double sum = 0;
    int p = 0;
    for(int i = len_a -1; i >= 0; i--)
    {
        sum += (a[i]-'0')*pow(10,p);
        p++;
        if(sum > INT_MAX)
            return false;
    }
    return true;
}

long long string_to_num(int i,int j)
{
    double sum = 0;
    int p = 0;
    for(int k = j; k >= i; k--)
    {
        sum += (a[k] - '0')*pow(10,p);
        p++;
    }
    return (long long)sum;
}

long long f(int i)
{
    if(i == len_a)return 0;

    if(dp[i] != -1)return dp[i];
    int j = i+1;
    long long t;
    for(;j<len_a;j++){
        t = string_to_num(i,j);
        if(t > (long long)INT_MAX || t < 0)break;
    }

    j--;
   // cout<<j<<endl;
    long long temp = 0;
    for(int k = 0;k <= j;k++){
        t = string_to_num(i,i+k);
        if(t > (long long)INT_MAX || t < 0)break;
        if(i+k < len_a)temp = max(temp,string_to_num(i,i+k)+f(i+k+1));
    }
    dp[i] = temp;
    return dp[i];
}

int main()
{
    //freopen("input_file.txt","r",stdin);
    //freopen("output_file.txt","w",stdout);

    int T;
    cin>>T;
    while(T--)
    {
        cin>>a;
        memset(dp,-1,sizeof(dp));
        len_a = a.size();
        long long ans;
        if(if_strto_num()){
            ans = string_to_num(0,len_a-1);
        }
        else{
            ans = f(0);
        }
        //cout<<"----->";
        cout<<ans<<endl;
    }
    return 0;
}

















