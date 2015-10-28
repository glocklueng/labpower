/**
 * @file  motor_controller.c
 * @brief Implements motor control for a brushless motor
 * 
 * @details Takes a 
 * 
 * @author Sam Girvin
 * @date  10.2015
 */

 `define k_p .2
 `define k_d 100
 `define k_i 1

 int motor_controller(float freq, float setpoint_freq){
 	/*
 	float p_err = setpoint_freq - freq;
 	float d_err = p_err - old_p_err;
 	float i_err = p_err + old_p_err;

 	PWM_1 = PWM k_p*p_err + k_d*d_err +k_i *i_err;

 	PWM_max = (i_max*r_s+v_e)/V1;
 	PWM_min = (-i_max*r_s+v_e)/V1;

 	if (PWM_1>PWM_max)
 		PWM = PWM_max;
 		i_err = PWM*V1/k_i;
 	else if (PWM_1<PWM_min)
 		PWM = PWM_min;
 		i_err = PWM*V1/k_i;
 	else
 		PWM = PWM_1;
 	


	*/

 }