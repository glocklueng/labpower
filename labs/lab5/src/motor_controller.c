/**
 * @file  motor_controller.c
 * @brief Implements motor control for a brushless motor
 * 
 * @details TBD
 * 
 * @author Sam Girvin - lol
 * @date  10.2015
 */


 float max_current = 3;
 float R_s = 2.6;
 float K_e = .0271;
 int V_o = 24;
 float PWM_LIMIT = 255;
 float max_speed = (PWM_LIMIT*V_o - max_current*R_s)/K_e;

 //PID Constants
 float ku = 1;
 float pu = .25;

 float kp = .6*ku;
 float kd = kp*pu/8;
 float ki = 2*kp/pu;



 float motor_controller(float speed, float setpoint, float old_err, float old_err_int){

 	if(setpoint > max_speed) setpoint = max_speed;

 	float err = setpoint - speed;
 	float err_der = err-old_err;
 	float err_int = old_err_int+err;

 	float PWM_1 = kp*err+kd*err_der+ki*err_der;

 	float PWM_max = (max_current*R_s*K_e*speed)/((float)V_o);
 	float PWM_min = (-max_current*R_s*K_e*speed)/((float)V_o);

 	if(PWM_max > PWM_LIMIT) PWM_max = PWM_LIMIT;
 	if(PWM_min<0) = PWM_min = 0;

 	if(PWM_1 > PWM_max) {
 		float PWM = PWM_max;
 		err_int = PWM/PWM_LIMIT*V_o/ki;
 	} else {
 		float PWM = PWM_min;
 		err_int = PWM/PWM_LIMIT*V_o/ki;
 	} else {
 		float PWM = PWM_1;
 	}

 	return PWM;
}