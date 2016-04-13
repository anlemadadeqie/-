#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IntegerMultiply(int X, int Y, int N)  
{  
   int a,b,sign,x,y;
 
    if(X>0)
	a = 1;
    else
	a = -1;
    if(Y>0)
	b = 1;
    else
	b = -1;
    sign = a*b;  
    x = abs(X);  
    y = abs(Y);  
    if((0 == x) || (0 == y))  
        return 0;  
    if (1 == N)  
        return x*y;  
    else  
    {  
        int XL = x / (int)pow(10,(int)N/2);   
        int XR = x - XL * (int)pow(10, N/2);  
        int YL = y / (int)pow(10, (int)N/2);  
        int YR = y - YL * (int)pow(10, N/2);  
          
        int XLYL = IntegerMultiply(XL, YL, N/2);  
        int XRYR = IntegerMultiply(XR, YR, N/2);  
        int XLYRXRYL = IntegerMultiply(XL - XR, YR - YL, N/2) + XLYL + XRYR;  
        return sign * (XLYL * (int)pow(10, N) + XLYRXRYL * (int)pow(10, N/2) + XRYR);  
    }  
} 
 void main()  
{  
    int x = 1234;  
    int y = 4321;  
    int number=IntegerMultiply(x,y,4); 
    printf("%d",number); 
}  
