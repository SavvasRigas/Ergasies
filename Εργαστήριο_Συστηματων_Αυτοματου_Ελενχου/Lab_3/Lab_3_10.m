clear all;
close all;
clc;

m=2; L=1; b=1; g=9.81;
x2e=0;

C = [1 0; 0 1];
D = [0; 0];
t = 0:0.01:25;

x1e=15*pi/180; we = sqrt(g/(L * cos(x1e)));
A = [0 1; -g*(sin(x1e)^2)/(L*cos(x1e)) -b/(m*L)];
B = [0; 2*g*sin(x1e)/(L*we)];

G_1 = ss(A ,B ,C ,D );
impulse(G_1, t)

x1e=40*pi/180; we = sqrt(g/(L * cos(x1e)));
A = [0 1; -g*(sin(x1e)^2)/(L*cos(x1e)) -b/(m*L)];
B = [0; 2*g*sin(x1e)/(L*we)];

G_2 = ss(A ,B ,C ,D );
hold on
impulse(G_2, t)


x1e=87*pi/180; we = sqrt(g/(L * cos(x1e)));
A = [0 1; -g*(sin(x1e)^2)/(L*cos(x1e)) -b/(m*L)];
B = [0; 2*g*sin(x1e)/(L*we)];

G_3 = ss(A ,B ,C ,D );
impulse(G_3, t)
