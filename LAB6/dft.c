#include<stdio.h> 
#include<math.h> 
#include<complex.h> 
#define N 1000 
int main() { 
int n; 
double y; 
double Ac, Am, kf, fm, fc, fs; 
printf("Enter the value of carrier amplitude: "); 
scanf("%lf", &Ac); 
printf("Enter the value of message amplitude: "); 
scanf("%lf", &Am); 
printf("Enter the value of sensitivity: "); 
scanf("%lf", &kf); 
printf("Enter the value of message frequency: "); 
scanf("%lf", &fm); 
printf("Enter the value of carrier frequency: "); 
scanf("%lf", &fc); 
FILE *fp; 
fp = fopen("fm_signal11.txt", "w"); 
fs = 100 * fc; 
for(int i = 0; i < N; i++) { y = Ac * cos(2 * M_PI * fc * (i / fs) + kf * Am * cos(2 *M_PI * fm * (i / fs))); 
fprintf(fp, "%lf\n", y); 
} 
fclose(fp); 
// Separation of even and odd parts of the signal 
double even_part[N]; 
double odd_part[N]; 
for(int i = 0; i < N; i++) { 
if (i % 2 == 0) 
even_part[i] = Ac * cos(2 * M_PI * fc * (i / fs) + kf * 
Am * cos(2 * M_PI * fm * (i / fs))); 
else 
odd_part[i] = Ac * cos(2 * M_PI * fc * (i / fs) + kf * 
Am * cos(2 * M_PI * fm * (i / fs))); 
} 
// DFT calculation 
double complex X_even[N]; 
double complex X_odd[N]; 
for(int k = 0; k < N; k++) { 
double complex sum_even = 0; 
double complex sum_odd = 0; 
for(int n = 0; n < N; n++) { 
sum_even += even_part[n] * cexp(-2 * I * M_PI * k * n / 
N); 
sum_odd += odd_part[n] * cexp(-2 * I * M_PI * k * n / 
N); 
} 
X_even[k] = sum_even; 
X_odd[k] = sum_odd; 
} 
// Combining the even and odd parts to get DFT of original signal 
double complex X_combined[N]; 
for(int k = 0; k < N; k++) { 
X_combined[k] = X_even[k] + X_odd[k]; 
} 
// Saving the DFT of combined signal to file 
fp = fopen("dft_combined_signal.txt", "w"); 
for(int k = 0; k < N; k++) { 
fprintf(fp, "%lf, %lf;\n", creal(X_combined[k]), 
cimag(X_combined[k])); 
} 
fclose(fp);   
return 0; }
