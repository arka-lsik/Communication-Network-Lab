//Code or programming for to generate FM signal sample value in a .txt file
#include<stdio.h> 
#include<math.h> 
#include<limits.h> 
int main(){ 
double y; 
double Ac, Am, kf, fm, fc,fs; 
printf("Enter the value of carrier amplitude: "); 
scanf("%lf",&Ac); 
printf("Enter the value of message amplitude: "); 
scanf("%lf",&Am); 
printf("Enter the value of sensitivity: "); 
scanf("%lf",&kf); 
printf("Enter the value of message frequecny: "); 
scanf("%lf",&fm); 
printf("Enter the value of carrier frequecny: "); 
scanf("%lf",&fc); 
FILE *fp; 
fp = fopen("file signal.txt","w"); 
fs = 100*fc; 
for(int i=0;i<10000;i++){ 
y = Ac*cos(2*3.14*fc*(i/fs)+kf*Am*cos(2*3.14*fm*(i/fs))); 
fprintf(fp, "%lf\n",y); 
} 
fclose(fp); 
return 0; 
}
