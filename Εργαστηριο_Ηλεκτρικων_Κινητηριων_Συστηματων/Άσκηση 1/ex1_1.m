close all;

figure;
rpmrotorspeed = (60*out.rotorspeed.Data(:,1))/(2*pi);
%{
h1=plot(out.eletorque);
hold on;
h2=plot(out.mectorque);
hold on;
h3=plot(out.rotorspeed);
hold on;
h4=plot(out.stacurrent);
hold off;
legend([h1 h2 h3 h4],'Mel=f(t)','Ml=f(t)','Ω=f(t)','Is=f(t)');
ylabel('Time(s)');
xlabel('Mel,Ml,Ω,Is');
%}
%mectorque025 = out.mectorque025.Data(:,1);
%eletorque025 = out.eletorque025.Data(:,1);
h1=plot(rpmrotorspeed,out.eletorque010.Data(:,1));
hold on;
h2=plot(rpmrotorspeed,out.mectorque010.Data(:,1));
hold on;
h3=plot(rpmrotorspeed,eletorque025);
hold on;
h4=plot(rpmrotorspeed,mectorque025);
hold off;
legend([h1 h2 h3 h4],'Mel=f(n) ML=0.1Ω','Ml=f(n) ML=0.1Ω','Mel=f(n) ML=0.25Ω','Ml=f(n) ML=0.25Ω');
xlabel('N(rpm)');
ylabel('M(Nm)');