clear all;
close all;
clc;

m=2; L=3; b=1; g=9.81;
x1e=40*pi/180; x2e=0;
we = sqrt(g/(L * cos(x1e)));

G = tf( 2*g*sin(x1e)/(L*we), [1 b/(m*L) g*(sin(x1e)^2)/(L*cos(x1e))] );

t = 0:0.1:200;
u = 0.5*sin(2*pi*0.02*t) + 0.5;


C = pid(1, 1, 0.01);
subplot(3,1,1)
hold on
plot(t, (180/pi)*u)
y = (180/pi)*lsim(feedback(series(C, G), 1, -1), u, t, 0);
plot(t, y)
title("PID with Kp = 1")

C = pid(5, 1, 0.01);
subplot(3,1,2)
hold on
plot(t, (180/pi)*u)
y = (180/pi)*lsim(feedback(series(C, G), 1, -1), u, t, 0);
plot(t, y)
title("PID with Ki = 5")

C = pid(50, 1, 0.01);
subplot(3,1,3)
hold on
plot(t, (180/pi)*u)
y = (180/pi)*lsim(feedback(series(C, G), 1, -1), u, t, 0);
plot(t, y)
title("PID with Ki = 50")