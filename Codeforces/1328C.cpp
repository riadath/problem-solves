#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        string sum,a,b;
        cin>>sum;
        a.push_back('1');
        b.push_back('1');
        bool gone_big = false;
        for(int i = 1;i < sum.size();i++){
            if(!gone_big){
                if(sum[i] == '0'){
                    a.push_back('0');
                    b.push_back('0');
                }
                else if(sum[i] == '2'){
                    a.push_back('1');
                    b.push_back('1');
                }
                else if(sum[i] == '1'){
                    a.push_back('1');
                    b.push_back('0');
                    gone_big = true;
                }
            }
            else{
                if(sum[i] == '0'){
                    a.push_back('0');
                    b.push_back('0');
                }
                else if(sum[i] == '2'){
                    a.push_back('0');
                    b.push_back('2');
                }
                else if(sum[i] == '1'){
                    a.push_back('0');
                    b.push_back('1');
                    gone_big = true;
                }
            }
        }
        cout<<a<<endl;
        cout<<b<<endl;
    }
    return 0;
}














































