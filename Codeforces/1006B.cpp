#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }
    int total = 0;
    int m_index[k];
    for(int i = 0;i < k;i++){
        int temp = 0;
        int indx = 0;
        for(int j = 0;j < n;j++){
            if(arr[j] > temp){
                temp = arr[j];
                indx = j;
            }
        }
        m_index[i] = indx;
        total += temp;
        arr[indx] = -1;
    }
    printf("%d\n",total);
    sort(m_index,m_index+k);
    m_index[0] = 0;

    for(int i = 0;i < k-1;i++){
       // cout<<m_index[i-1]<<"----"<<m_index[i]<<endl;
        int t = m_index[i+1] - m_index[i];
        printf("%d ",t);
    }
    printf("%d ",n-m_index[k-1]);
    printf("\n");
    return 0;
}
