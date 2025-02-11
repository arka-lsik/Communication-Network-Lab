# include <stdio.h> 
# include <limits.h> 
# include <math.h> 
# define pi 3.14 
int main(){ 
    float Ac=1,Am=1,fc=10,fm=1,Kf=5; 
    float fsamp=100*fc; 
 
    int samples_no=1000; 
    int i; 
    float time[samples_no],Yfm[samples_no]; 
    // time samples 
    time[0]=0; 
    for (i=1;i<samples_no;i++){ 
        time[i]=time[i-1]+(1/fsamp); 
    } 
    // fm modulated 
    for (i=0;i<samples_no;i++){ 
 // finding the DFT : real and imaginary parts magnitude 
    int n,k,N=samples_no; 
    float real_dft[samples_no]; 
    float imag_dft[samples_no]; 
    float mag_dft[samples_no]; 
    int index=0; 
    for (k=0;k<samples_no;k++){ 
        real_dft[k]=0; 
        imag_dft[k]=0; 
        for (n=0;n<N;n++){ 
            real_dft[k]=real_dft[k]+Yfm[n]*cosf(2*pi*k*n/N); 
            imag_dft[k]=imag_dft[k]-Yfm[n]*sinf(2*pi*k*n/N); 
 
        } 
        printf("%d\n",k); 
        mag_dft[k]=sqrt((real_dft[k]*real_dft[k])+(imag_dft[k]*imag_dft[k])); 
    } 
   // transfer function details 
    float TF_real[N],TF_imag[N],freq[N]; 
    float Qe=fc/(2*Kf*Am); 
    float x[N],Y_real[N],Y_imag[N]; 
    float eta=1,gm=1,Ec=1,L=0.001,a=1.0274,b=1.5; 
    
 
    freq[0]=0; 
    x[0]=-2*Qe; 
    // freq scale points
  for (i=1;i<N;i++){ 
    freq[i]=freq[i-1]+(fsamp/N); 
    } 
    
    
    for (i=0;i<N;i++){ 
        x[i]=2*Qe*(freq[i]-fc)/fc; 
        // transfer function 
        if(1-pow((x[i]+a),2)>=0){ 
        TF_real[i]=(eta*gm*Ec*2*pi*fc*L*Qe)*(sqrt(1+pow((x[i]+a),2))-sqrt(1
pow((x[i]+a),2)))/(pow((1+(b*b)-(x[i]*x[i])),2)+(4*x[i]*x[i])); 
        TF_imag[i]=0; 
        } 
        else{ 
        TF_real[i]=(eta*gm*Ec*2*pi*fc*L*Qe)*(sqrt(1+pow((x[i]+a),2)))/(pow((1+(b*b)
(x[i]*x[i])),2)+(4*x[i]*x[i])); 
        TF_imag[i]=(eta*gm*Ec*2*pi*fc*L*Qe)*(sqrt(-1+pow((x[i]+a),2)))/(pow((1+(b*b)
(x[i]*x[i])),2)+(4*x[i]*x[i])); 
        }
 // DFT x transfer function 
    Y_real[i]=(TF_real[i]*real_dft[i])-(TF_imag[i]*imag_dft[i]); 
    Y_imag[i]=(TF_real[i]*imag_dft[i])+(TF_imag[i]*real_dft[i]); 
    } 
    
    // finding the IDFT : real and imaginary parts magnitude 
    // CALCULATING IDFT OF DFT SAMPLES : 
    N=samples_no; 
    float real_idft[samples_no]; 
    float imag_idft[samples_no]; 
    float mag_idft[samples_no]; 
 
    index=0; 
    for (n=0;n<samples_no;n++){ 
        real_idft[n]=0; 
        imag_idft[n]=0; 
        for (k=0;k<N;k++){ 
            real_idft[n]=real_idft[n]+((Y_real[k]*cosf(2*pi*k*n/N))-(Y_imag[n]*sinf(2*pi*k*n/N))); 
            imag_idft[n]=imag_idft[n]+((Y_real[k]*sinf(2*pi*k*n/N))+(Y_imag[n]*cosf(2*pi*k*n/N))); 
        } 
        printf("%d\n",n); 
        real_idft[n]=real_idft[n]/N; 
        imag_idft[n]=imag_idft[n]/N; 
        
    } 
    
    // saving the plot to a text file 
 
    FILE *fp1 = fopen("text","w"); 
    for (i=0;i<samples_no;i++){ 
 
fprintf(fp1,"%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",time[i],Yfm[i],real_dft[i],Img_dft[
 i],TF_real[i],TF_imag[i],Y_real[i],Y_imag[i],real_idft[i],imag_idft[i]); 
} 
fclose(fp1);
