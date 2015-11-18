/*
* Info: Header file for motor controller. Outputs a PWM
* Author: Vikram, Sam, Carson Palmer
*
*/



float motor_controller(float freq, float setpoint_freq);

void change_err_der(float new_err_der);

void change_err_int(float new_err_int);