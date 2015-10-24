function [omega, I, v_o, v_emf] = motor(dt, PWM, supply_vol, omega_old, I_old, old_vo, J_load)

R = 2.6;
K_e = .0271;
J = .00915995+J_load;
L = .0025;

v_o = 24;


v_emf = omega_old*K_e;
torque = K_e*I_old;
alpha = torque/J;

v_inductor = v_o - I_old*R - v_emf;

dI = v_inductor*dt/L;
I = I_old + dI;
omega = omega_old + alpha*dt;
end 