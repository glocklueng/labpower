function [PWM] = controller(speed, current, setpoint, old_PWM)

err = setpoint-speed;

kp = .05;

PWM = old_PWM+kp*err;

end function

