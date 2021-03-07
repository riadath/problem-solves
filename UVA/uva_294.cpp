
#include <bits/stdc++.h>
using namespace std;
#define MAX 35000
int if_prime[MAX+500];
void prime_sieve()
{
    for(int i = 0; i < MAX; i++)
    {
        if_prime[i] = 1;
    }
    if_prime[0] = 0;
    if_prime[1] = 0;
    for(int i = 2; i < MAX; i += 2)
    {
        if_prime[i] = 0;
    }
    if_prime[2] = 1;
    int i,j;
    for(i = 3; i*i < MAX; i += 2)
    {
        for(j = i*i; j < MAX; j += 2*i)
        {
            if_prime[j] = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    prime_sieve();
    int T;
    cin>>T;
    while(T--)
    {
        long long int l,u;
        cin>>l>>u;
        //cout<<l<<" "<<u<<endl;
        int nod = 1,max_div = 0,temp = 0;
        long long int i,j,k,p,cur_num = 0;
        for(p = l; p <= u; p++)
        {
            i = p;
            nod = 1;
           // cout<<"num:"<<i<<endl;
            for(k = 2; k*k <= i; k++)
            {
                temp = 0;
                if(if_prime[k])
                {
                    //cout<<"prime:"<<k<<endl;
                    if(i%k == 0)
                    {
                        while(i%k == 0)
                        {
                            i /= k;
                            temp++;
                        }
                    }
                    nod = nod * (temp+1);
                }
            }
            if(i > 1){
                nod = nod * 2;
            }
           // cout<<"----------------------------------------"<<endl;
            if(nod > max_div)
            {
                max_div = nod;
                cur_num = p;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %d divisors.\n",l,u,cur_num,max_div);
    }
    return 0;
}









