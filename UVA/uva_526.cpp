#include<bits/stdc++.h>
using namespace std;
string a,b;
int del_c,ans,len_a,len_b,dp[1001][1001],soln[1001][1001],c;
int f(int x,int y)
{
    if(x == len_a)
        return len_b - y;
    if(y == len_b)
        return len_a - x;

    if(dp[x][y] != - 1)
        return dp[x][y];

    int p,q,r;
    if(a[x] == b[y])
    {
        soln[x][y] = 0;
        dp[x][y] = f(x+1,y+1);
    }
    else
    {

        p = 1 + f(x,y+1);
        q = 1 + f(x+1,y);
        r = 1 + f(x+1,y+1);
        dp[x][y] = min(p,min(q,r));
        if(p<=q && p<=r)
            soln[x][y] = 1;
        else if(q <= r && q <= q)
            soln[x][y] = 2;
        else
            soln[x][y] = 3;
    }

    return dp[x][y];

}

void print_soln(int x,int y)
{
    if(y == len_b){
        for(;x < len_a;x++){
            cout << c++ << " Delete "<< x+1-del_c;
            if(c != ans+1)cout<<"\n";
            del_c++;
        }
        return ;
    }
    else if(x == len_a){
        for(;y < len_b;y++){
            cout << c++ << " Insert "<< y+1 <<","<<b[y];
            if(c != ans+1)cout<<"\n";
            del_c--;
        }
        return ;
    }

    if(soln[x][y] == 0)
    {
        print_soln(x+1,y+1);
    }
    else if(soln[x][y] == 1)
    {
        cout<< c++ <<" Insert "<<y+1<<","<<b[y];
        if(c != ans+1)cout<<"\n";
        del_c--;
        print_soln(x,y+1);
    }
    else if(soln[x][y] == 2)
    {
        cout << c++ << " Delete "<< x+1-del_c;
        if(c != ans+1)cout<<"\n";
        del_c++;
        print_soln(x+1,y);
    }
    else if(soln[x][y] == 3)
    {
        cout<<c++<<" Replace "<<y+1<<","<<b[y];
        if(c != ans+1)cout<<"\n";
        print_soln(x+1,y+1);
    }

}
int main()
{
    //freopen("input_file,txt","r",stdin);
    //freopen("output_file.txt","w",stdout);
    while(getline(cin,a) && getline(cin,b))
    {
        len_a = a.size(),len_b = b.size();
        memset(soln,0,sizeof(soln));
        memset(dp,-1,sizeof(dp));
        ans = f(0,0);
        cout<< ans << "\n";
        c = 1;
        del_c = 0;
        print_soln(0,0);
        cout<< "\n";
        a.clear();
        b.clear();
    }
    return 0;
}

