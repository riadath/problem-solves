#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        int x[N],y[N];
        for(int i = 0;i < N;i++){
            scanf("%d %d",&x[i],&y[i]);
        }
        int w;
        double initial,spent,rain;
        scanf("%d %lf %lf %lf",&w,&initial,&spent,&rain);
        double total = 0;
        int sum1 = 0,sum2 = 0;
        for(int i = 0,j = 1;i < N-1,j < N;i++,j++){
            sum1 += x[i]*y[j];
            sum2 += x[j]*y[i];

        }
        total = 0.5 * (sum1 - sum2) * w;
        double fin_amount = 0;
        double t_ini = (initial/100.0)*total;
        if(spent > t_ini){
            printf("Lack of water. ");
            fin_amount = rain;
        }else{
            fin_amount = t_ini - spent + rain;
        }

        if(fin_amount > total){
            printf("Excess of water. Final percentage: 100");
            cout<<"%"<<endl;
        }else{
            int fin_percentege = (fin_amount/total) * 100;
            cout<<"Final percentage: "<<fin_percentege<<"%"<<endl;
        }
    }
    return 0;
}

