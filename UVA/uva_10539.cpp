#include <stdio.h>
#include <math.h>
#define size_one 1000000
#define size_two 1000000000000
bool prime_ara[size_one];
unsigned long long al_prime_arr[80100];
void prime_store()
{
    int i,j;
    for(i=0; i<size_one; i++)
    {
        prime_ara[i]=true;
    }
    for(i=2; i*i <= size_one; i++)
    {
        for(j=2; i*j<=size_one; j++)
        {
            prime_ara[i*j]=false;
        }
    }
    prime_ara[0] = false;
    prime_ara[1] = false;
    int k,l,indx = 0;
    for(k = 2; k <= 50; k++)
    {
        for(l = 2; pow(l,k) <= size_two ; l++)
        {
            if(prime_ara[l])
            {
                unsigned long long temp = pow(l,k);
                al_prime_arr[indx] = temp;
                indx++;
            }
        }
    }
}
int main()
{
    prime_store();
    int T;
    scanf("%d",&T);
    while(T--)
    {
    	int counter = 0,i;
		unsigned long long low,high;
		scanf("%llu %llu",&low,&high);
		for(i = 0;i < 80100;i++){
			if(al_prime_arr[i]>=low && al_prime_arr[i]<=high){
				counter++;
			}
		}
		printf("%d\n",counter);
    }
    return 0;
}












