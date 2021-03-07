
//codejam prob 1 solved
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int kase = 1;kase<=T;kase++)
    {
        int N;
        cin>>N;
        int arr[N][N];
        int t = 0,r = 0,c = 0;

        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                cin>>arr[i][j];
                if(i == j){
                    t += arr[i][j];
                }
            }
        }
        vector <int> temp1;
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                temp1.push_back(arr[i][j]);
            }

            sort(temp1.begin(),temp1.end());
            for(int k = 0;k <temp1.size()-1;k++){
                if(temp1[k] == temp1[k+1]){
                    r++;
                    break;
                }
            }
            temp1.clear();

        }

        temp1.clear();

        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                temp1.push_back(arr[j][i]);
            }
            sort(temp1.begin(),temp1.end());
            for(int k = 0;k <temp1.size()-1;k++){
                if(temp1[k] == temp1[k+1]){
                    c++;
                    break;
                }
            }
            temp1.clear();
        }
        printf("Case #%d: %d %d %d\n",kase,t,r,c);
    }
    return 0;
}






