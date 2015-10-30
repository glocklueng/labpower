/**
 * @file  motor_controller.c
 * @brief Implements motor control for a brushless motor
 * 
 * @details TBD
 * 
 * @author Sam Girvin - lol
 * @date  10.2015
 */


 #define max_current 3
 #define R_s 2.6
 #define K_e .0271
 #define V_o 24.0
 #define PWM_LIMIT 255


 //PID Constants
 #define ku 1.0
 #define pu .25



 //THIS VALUE IS WRONG
 float max_speed = (V_o - max_current*R_s)/K_e;

#define kp 100
 #define kd 1
 #define ki 4

 // float kp = 0.6*ku;
 // float kd = kp*pu/8.0;
 // float ki = 2.0*kp/pu;

 float saved_err_der = 0.0;
 float saved_err_int = 0.0;


 float motor_controller(float speed, float setpoint) {

 	if(setpoint > max_speed) setpoint = max_speed;

 	float err = setpoint - speed;
 	float err_der = err-saved_err_der;
 	float err_int = saved_err_int+err;

 	float PWM_1 = kp*err+kd*err_der+ki*err_der;

 	float PWM_max = (max_current*R_s*K_e*speed)/((float)V_o);
 	float PWM_min = (-max_current*R_s*K_e*speed)/((float)V_o);

 	if(PWM_max > PWM_LIMIT) PWM_max = PWM_LIMIT;
 	if(PWM_min<0) PWM_min = 0;

 	float PWM;
 	if(PWM_1 > PWM_max) {
 		PWM = PWM_max;
 		err_int = PWM/PWM_LIMIT*V_o/ki;
 	} else if(PWM < PWM_min) {
 		PWM = PWM_min;
 		err_int = PWM/PWM_LIMIT*V_o/ki;
 	} else {
 		PWM = PWM_1;
 	}

 	saved_err_der = err_der;
 	saved_err_int = err_int;

 	return PWM;
 }


 void change_err_der(float new_err_der) {
 	saved_err_der = new_err_der;
 }

 void change_err_int(float new_err_int) {
 	saved_err_int = new_err_int;
 }