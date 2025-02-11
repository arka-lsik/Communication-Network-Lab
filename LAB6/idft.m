clear all; 
% read the sample value 
a = readmatrix('IDFT.txt'); 
%plot that IDFT FM Signal 
plot(a(1:5000)); 
xlabel("Time") 
ylabel("Amplitude") 
title("IDFT Of combined FM signal") 
