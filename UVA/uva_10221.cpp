#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int main()
{
    double s,a;
    char str[10];
    while(scanf("%lf %lf",&s,&a)==2)
    {
        scanf("%s",str);
        double angle;
        if(str[0] == 'd')angle = a;
        else angle = (a/60.00);
        if(angle < 0)angle = angle*-1.0;
        if(angle > 180.0)angle = 360.0-angle;
        /*if(angle>=360){
            int temp = floor(angle/360);
            angle = angle - temp*360;
        }*/
        angle = angle*pi/180.00;
        double arc,chord;
        s = s+6440.0;
        arc = s*angle;
        chord = s*sqrt(2.0*(1.0-cos(angle)));
        printf("%0.6lf %0.6lf\n",arc,chord);
    }
    return 0;
}










