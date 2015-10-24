clear;
close all;

dt = 1*10^-3;
t = 0:dt:1;

omega = zeros(length(t));
I = zeros(length(t));
v_o = zeros(length(t));
v_emf = zeros(length(t));


PWM = 155;
supply_vol = 24;
J_load = 0;
v_o(1) = PWM/255*supply_vol;


for q = 1:length(t)-1
    [omega(q+1), I(q+1), v_o(q+1), v_emf(q+1)] = motor(dt, PWM, supply_vol, omega(q), I(q), v_o(q), J_load);
end

figure;
subplot(2,2,1);
plot(t, omega);
title('Omega');
subplot(2, 2, 2);
plot(t, I);
title('Current');
subplot(2,2,3);
plot(t,v_o);
title('Voltage at terminal');
subplot(2,2,4);
plot(t,v_emf);
title('BACK Voltage');


