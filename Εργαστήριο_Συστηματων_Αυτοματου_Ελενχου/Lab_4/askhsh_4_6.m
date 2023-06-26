clear all;
close all;
clc;

K=0.0314; R=2; L=1; b=4.5e-2; J=4.33e-2;

G = tf(K, [J*L (J*R + L*b) (R*b + K^2) 0]);


% απο τις γραφικες στο figure(1) μπορω να διακρίνω πως το 
% το κρίσιμο Kp είναι περίπου 8.5
figure(1);
hold on
for Kp = 8.2:0.3:9.1
    C_1 = pid(Kp, 0, 0);
    Gs_1 = feedback(series(C_1, G), 1, -1);
    [h_1 , t_1] = step(Gs_1, 0:0.001:50);
    plot(t_1, h_1, 'DisplayName',['Kp=', num2str(Kp)])
end
title("Step Response")
xlabel("Time (Seconds)")
ylabel("Amplitude")
legend()
hold off
Kpcr = 8.5;

% απο την γραφική στο figure(2) μπορω να διακρίνω πως το 
% το κρίσιμο Τ 
figure(2);
C_2 = pid(Kpcr, 0, 0);
Gs_2 = feedback(series(C_2, G), 1, -1);
step(Gs_2, 0:0.001:15)
Tcr = 4.39;

% απο τις γραφικες στο figure(3) μπορω να διακρίνω πως το 
% το κρίσιμο Ki είναι περίπου 0
figure(3)
hold on
for Ki = 0:0.25:1
    C_3 = pid(0.6*Kpcr, Ki, 0);
    Gs_3 = feedback(series(C_3, G), 1, -1);
    [h_3, t_3] = step(Gs_3, 0:0.001:30);
    plot(t_3, h_3, 'DisplayName',['Ki=', num2str(Ki)])
end
title("Step Response")
xlabel("Time (Seconds)")
ylabel("Amplitude")
legend()
hold off
Ki = 0;

% απο τις γραφικες στο figure(4) μπορω να διακρίνω πως το 
% το κρίσιμο Kd είναι περίπου 6.5
figure(4)
hold on
for Kd = 6:0.5:8
    C_4 = pid(0.6*Kpcr, Ki, Kd);
    Gs_4 = feedback(series(C_4, G), 1, -1);
    [h_4, t_4] = step(Gs_4, 0:0.001:6);
    plot(t_4, h_4, 'DisplayName',['Kd=', num2str(Kd)])
end
title("Step Response")
xlabel("Time (Seconds)")
ylabel("Amplitude")
legend()
hold off
Kd = 6.5;

% Το τελικό αποτέλεσμα
figure(5)
C_5 = pid(0.6*Kpcr, Ki, Kd);
Gs_5 = feedback(series(C_5, G), 1, -1);
step(Gs_5)