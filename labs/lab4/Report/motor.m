function [omega, I, v_o] = motor(dt, PWM, supply_vol, omega_old, I_old, J_load)

R = 2.6;
K_e = .0271;
J = .00915995+J_load;
L = .0025;

v_o = supply_vol*(PWM/255);
I = I_old;
omega = omega_old;
v_emf = omega*K_e;

v_inductor = v_o - I*R - v_emf;
dI = v_inductor*dt/L;

I = I+dI;
torque = K_e*I;
alpha = torque/J;

omega = omega_old+alpha*dt;
v_emf = omega*K_e;

v_o = v_emf + I*R + L*(dI/dt);

end 