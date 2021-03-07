#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	int v,a;
	double k,R;
	cin>>v>>a>>k;
	double angle = sin(2.0 * ((a*3.1415926535)/180.0));
	R = (k/(k-1)) * ((angle * v * v)/10.0);
	printf("%.2f",R);
	return 0;
}
