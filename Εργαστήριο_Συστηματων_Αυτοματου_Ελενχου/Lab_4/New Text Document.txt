clear all
close all
clc

K=0.0314; R=2; L=1; b=4.5e-2; J=4.33e-2;

G = tf(K, [J*L (J*R + L*b) (R*b + K^2) 0]);

%% Kp calculation
% hold on
% for Kp = 8.2:0.3:9.1
%     C = pid(Kp, 0, 0);
%     Gs = feedback(series(C, G), 1, -1);
%     [h, t] = step(Gs, 0:0.001:50);
%     plot(t, h, 'DisplayName',['Kp=', num2str(Kp)])
% end
% title("Step Response")
% xlabel("Time (Seconds)")
% ylabel("Amplitude")
% legend()
% hold off
Kpcr = 8.5;

%% Tcritical calculation
% C = pid(Kpcr, 0, 0);
% Gs = feedback(series(C, G), 1, -1);
% step(Gs, 0:0.001:15)
Tcr = 4.39;

%% Ki calculation
% hold on
% for Ki = 0:0.25:1
%     C = pid(0.6*Kpcr, Ki, 0);
%     Gs = feedback(series(C, G), 1, -1);
%     [h, t] = step(Gs, 0:0.001:30);
%     plot(t, h, 'DisplayName',['Ki=', num2str(Ki)])
% end
% title("Step Response")
% xlabel("Time (Seconds)")
% ylabel("Amplitude")
% legend()
% hold off
Ki = 0;

%% Ki calculation
% hold on
% for Kd = 0.6*Kpcr*Tcr/8:2:15
% for Kd = 6:0.5:8
%     C = pid(0.6*Kpcr, Ki, Kd);
%     Gs = feedback(series(C, G), 1, -1);
%     [h, t] = step(Gs, 0:0.001:6);
%     plot(t, h, 'DisplayName',['Kd=', num2str(Kd)])
% end
% title("Step Response")
% xlabel("Time (Seconds)")
% ylabel("Amplitude")
% legend()
% hold off
Kd = 6.5;

%% Final plot
C = pid(0.6*Kpcr, Ki, Kd);
Gs = feedback(series(C, G), 1, -1);
step(Gs)