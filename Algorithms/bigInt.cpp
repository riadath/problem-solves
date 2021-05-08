#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void swap(char &c1,char &c2){
    char temp = c2;
    c2 = c1;
    c1 = temp;
}
void reverseChar(char *ch){
    int len = strlen(ch);
    for(int i = 0;i < len/2;i++)swap(ch[i],ch[len - i - 1]);
}


struct BigInt{
    char detum[1100];
    void init(char v[]){
        int i;
        for(i=0; v[i] != 0; i++){
            detum[i] = v[i];
        }
        detum[i] = '\0';
    }
    void printAll(){
        for(int i=0; detum[i] != 0; i++){
            printf("%c",detum[i]);
        }
        puts("");
    }
    int max(int a,int b){
        return (a > b)?a:b;
    }
    void add(BigInt x){
        int tt = 0,carry = 0,st = 0;
        reverseChar(detum),reverseChar(x.detum);
        BigInt temp;
        memset(temp.detum,0,sizeof(temp.detum));
        int lenX = strlen(x.detum),lenY = strlen(detum);
        for(int i = 0;i < max(lenX,lenY);i++){
            tt = 0;
            if(i < lenY)tt = (detum[i] - '0');
            if(i < lenX)tt += (x.detum[i] - '0');
            tt += carry;
            temp.detum[st++] = (tt%10) + '0';
            carry = tt/10;
        }
        while(carry){
            temp.detum[st++] = carry%10 + '0';
            carry /= 10;
        }
        reverseChar(temp.detum);
        temp.detum[st] = '\0';
        init(temp.detum);
    }
    
    void mul(BigInt x){
       int lenX = strlen(x.detum), lenY = strlen(detum);
       BigInt temp;
       memset(temp.detum,0,sizeof(temp.detum));
       reverseChar(detum),reverseChar(x.detum);
       for(int i = 0;i < lenY;i++){
           int carry = 0,tt1 = detum[i] - '0';
           int j = 0;
        //    puts(temp.detum);
           for(;j < lenX;j++){
               int tt2 = x.detum[j] - '0';
               int also = (temp.detum[i + j]);
               if(also != 0)also -= '0';
               int res = (tt1 * tt2) + (also)+ carry;
            //    printf("======> %d %d %d\n",tt1,tt2,res);
               temp.detum[i + j] = res%10 + '0';
               carry = res/10;
           }
           if(carry > 0)temp.detum[i + j] += carry + '0';
        }
        // puts(temp.detum);
        reverseChar(temp.detum);
        int st = 0,lenT = strlen(temp.detum);
        while(temp.detum[st] == '0' && st < lenT){
            st++;
            if(st + 1 >= lenT){
                memset(temp.detum,0,sizeof(temp.detum));
                temp.detum[0] = '0',temp.detum[1] = '\0';
                init(temp.detum);
            }
        }
        for(int i = st,j = 0;i < lenT;i++,j++){
            detum[j] = temp.detum[i];
            if(i + 1 == lenT)detum[j + 1] = '\0';
        }
        memset(temp.detum,0,sizeof(temp.detum));
        for(int i = 0;detum[i] != 0;i++){
            temp.detum[i] = detum[i];
            if(detum[i + 1] == 0)temp.detum[i + 1] = 0;
        }
        init(temp.detum);
    }
    
    void div(int y){
       BigInt temp;
       memset(temp.detum,0,sizeof(temp.detum));
        int st = 0,st2 = 0,tt = detum[0] - '0';
        while(tt < y)tt = tt * 10 + (detum[++st] - '0');
        while(st < strlen(detum)){
            temp.detum[st2++] = tt / y + '0';
            tt = (tt%y) * 10 + detum[++st] - '0';
        }
        if(!st2){
            memset(temp.detum,0,sizeof(temp.detum));
            temp.detum[0] = '0',temp.detum[1] = 0;
        }
        init(temp.detum);
    }
    
    int rem(int y){
        int rm = 0,m = 1;
        reverseChar(detum);
        for(int i = 0;i < strlen(detum);i++){
            rm = ((rm + (detum[i] - '0') * m)%y)%y;
            m = (m * 10)%y;
        }
        return rm;
    }
};
int main()
{
    return 0;
}