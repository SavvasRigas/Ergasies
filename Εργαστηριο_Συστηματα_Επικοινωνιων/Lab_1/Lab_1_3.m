clc;
clear all;
close all;
scrz = get(0, 'ScreenSize');

load res_762;

figure('Position', [50 150 scrz(3)/2 scrz(4)/2]);
set(gcf, 'color', 'white');
FontSize = 14;
set(gcf, 'DefaultLineLineWidth', 2);
set(gcf, 'DefaultTextFontSize', FontSize, 'DefaultAxesFontSize', ...
FontSize, 'DefaultLineMarkerSize',0.25*FontSize);

plot(t, SignIn);
grid on;
xlabel('t');
ylabel('SignIn');

[mean, min, max]= m3s(SignIn);

file = ['out_' num2str(AM, '%03d') '.mat'];
save(file);