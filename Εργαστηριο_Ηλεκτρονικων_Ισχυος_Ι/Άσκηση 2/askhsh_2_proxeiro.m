clear all; clc; close all;

vrms_r = [226.2 206.7 164.1 103.4 39.95];
a_r = [30 60 90 120 150];
vrms_l = [230 152.8 65.29];
a_l = [90 120 150];
vrms_rl = [230 188.6 126.4 57.45];
a_rl = [60 90 120 150];

figure();
subplot(3,1,1);
plot(a_r, vrms_r, "-o");
title("Vrms = f(a) για ωμικο φορτιο");

subplot(3,1,2);
plot(a_l, vrms_l, "-o");
title("Vrms = f(a) για επαγωγικο φορτιο");

subplot(3,1,3);
plot(a_rl, vrms_rl, "-o");
title("Vrms = f(a) για ωμικο-επαγωγικο φορτιο");



