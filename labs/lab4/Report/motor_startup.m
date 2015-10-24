clear;
close all;

dt = 1*10^-6;
t = 0:dt:5*10^-3;

omega = zeros(length(t));
I = zeros(length(t));
v_o = zeros(length(t));

PWM = 155;
supply_vol = 24;
J_load = 0;


for q = 1:length(t)-1
    [omega(q+1), I(q+1), v_o(q+1)] = motor(dt, PWM, supply_vol, omega(q), I(q), J_load);
    
end

figure;
subplot(3,1,1);
plot(t, omega);
title('Omega');
subplot(3, 1, 2);
plot(t, I);
title('Current');
subplot(3,1,3);
plot(t,v_o);
title('Voltage at terminal')

