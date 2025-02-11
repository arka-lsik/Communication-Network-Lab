clc; 
clear all; 
% Load the combined DFT signal  
data = readmatrix('dft1.txt');  
% Separate the real and imaginary parts  
real_part = data(:, 1);  
imaginary_part = data(:, 2); 
% Plot the real part  
subplot(2, 1, 1);  
plot(real_part);  
title('Real Part of Combined DFT Signal');  
xlabel('Index');  
ylabel('Amplitude'); 
% Plot the imaginary part  
subplot(2, 1, 2);  
plot(imaginary_part);  
title('Imaginary Part of Combined DFT Signal');  
xlabel('Index');  
ylabel('Amplitude'); 
