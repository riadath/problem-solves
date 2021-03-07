#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n && n)
    {
        int i,j,p = 0,q = 65;
        bool is = false;
        for(i = 60;i >= 0;i--){
            for(j = 1;j < i;j++){
                int temp = (i*i*i) - (j*j*j);
                if(temp == n){
                    if(j < q){
                        p = i;
                        q = j;
                        is = true;
                    }
                }
            }
        }
        if(!is){
            cout<<"No solution"<<endl;
        }else{
            cout<<p<<" "<<q<<endl;
        }

    }
    return 0;
}
