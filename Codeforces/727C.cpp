#include <stdio.h>

int qr(int i,int j){
    int s;
    printf("? %d %d\n",i + 1,j + 1);
    fflush(stdout);
    scanf("%d",&s);
    return s;
}

int main(){
    
    int n;
    scanf("%d",&n);
    int ans[n + 1];
    int s1 = qr(0,1);
    int s2 = qr(1,2);
    int s3 = qr(2,0);
    int s13 = (s1 + s2 + s3)/2;
    ans[0] = s13 - s2;
    ans[1] = s13 - s3;
    ans[2] = s13 - s1;
    for(int i = 3;i < n;i++){
        int s = qr(0,i);
        ans[i] = s - ans[0];
    }
    printf("!");
    for(int i = 0;i < n;i++){
        printf(" %d",ans[i]);
    }
    printf("\n");
    return 0;
}