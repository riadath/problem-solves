#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for(int k = 1;k <= T;k++){
        int N,w;
        scanf("%d %d",&N,&w);
        vector <int> x,y;
        for(int i = 0;i < N;i++){
            int p,q;
            scanf("%d %d",&p,&q);
            x.push_back(p);
            y.push_back(q);
        }
        int wipes = 0,bottom,head;
        sort(y.begin(),y.end());
        int mx = y[N-1],mn = y[0];
        bottom = mn;
        head = bottom+w;
        wipes++;
        int i = 0;
        while(head < mx){
            while(true){
                if(y[i] > head)break;
                i++;
            }
            bottom = y[i];
            wipes++;
            head = bottom + w;
        }
        printf("Case %d: %d\n",k,wipes);
    }
    return 0;
}
