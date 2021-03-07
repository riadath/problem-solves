#include <bits/stdc++.h>
using namespace std;
vector <string> a,b;
int len_a,len_b;
vector <string>path;
int len = 0;
int ans;
int dp[101][101];
int f(int i,int j)
{
    if(i == len_a || j == len_b)
    {
        return 0;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    int p = 0,q = 0;
    if(a[i] == b[j])
    {
        dp[i][j] = 1 + f(i+1,j+1);
    }
    else
    {
        p = f(i,j+1);
        q = f(i+1,j);
        dp[i][j] = max(p,q);
    }
    return dp[i][j];

}

void solution(int i,int j)
{
    if(i == len_a || j == len_b)
    {
         for(int k = 0; k < ans; k++)
        {
            cout<< path[k];
            if(k != ans-1)cout << " ";
        }
        cout<<endl;
        return;
    }

    if(a[i] == b[j])
    {
        path.push_back(b[j]);
        solution(i+1,j+1);
        //path.erase(path.end()-1);
    }
    else
    {
        if(dp[i][j+1] > dp[i+1][j])
            solution(i,j+1);
        else
            solution(i+1,j);
    }
}

int main()
{
    //freopen("input_file.txt","r",stdin);
    //freopen("output_file.txt","w",stdout);
    string temp;
    int i = 1;
    while(cin>>temp)
    {
        memset(dp,-1,sizeof(dp));
        len_a = 1,len_b = 0;
        a.push_back(temp);
        while(true)
        {
            cin>>temp;
            if(temp == "#")
                break;
            a.push_back(temp);
            len_a++;
        }
        while(true)
        {
            cin>>temp;
            if(temp == "#")
                break;
            b.push_back(temp);
            len_b++;
        }

        ans = f(0,0);
        //cout<<ans<<"\n";
        //cout<<"Case :"<< i++<< " " ;
        solution(0,0);

        path.clear();
        a.clear();
        b.clear();
    }
    return 0;
}

















