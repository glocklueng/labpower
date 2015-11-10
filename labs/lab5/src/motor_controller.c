/**
 * @file  motor_controller.c
 * @brief Implements motor control for a brushless motor
 * 
 * @details TBD
 * 
 * @author Sam Girvin - lol
 * @date  10.2015
 */


 #define max_current 3.0
 #define R_s 2.6
 #define K_e .0271
 #define V_o 24.0
 #define PWM_LIMIT 1.0


 //PID Constants
 #define ku 1.0
 #define pu .25



 //THIS VALUE IS WRONG
 float max_speed = (V_o - max_current*R_s)/K_e;

float kp = .015;
 float kd = 0.00;
 float ki = 0.0;

 // float kp = 0.6*ku;
 // float kd = kp*pu/8.0;
 // float ki = 2.0*kp/pu;

 float saved_err_int = 0.0;
 float previous_err = 0.0;
 float old_PWM = 0.0;

 float motor_controller(float speed, float setpoint) {

 	if(setpoint > max_speed) setpoint = max_speed;

 	float err = setpoint - speed;
 	//float err_der = err-saved_err_der;
 	float err_der = (err-previous_err)/.01;
 	float err_int = saved_err_int+err*.01;

 	float PWM_1 = old_PWM+(kp*err+kd*err_der+ki*err_int)/24.0; //MAYBE WRONG

 	float PWM_max = (max_current*R_s+K_e*speed)/((float)V_o);
 	//float PWM_max = .5;
 	float PWM_min = (-max_current*R_s+K_e*speed)/((float)V_o);

 	if(PWM_max > PWM_LIMIT) PWM_max = 1.0;
 	if(PWM_min<0) PWM_min = 0.0;

 	float PWM;
 	if(PWM_1 > PWM_max) {
 		PWM = PWM_max;
 		//err_int = PWM*V_o/ki;
 	} else if(PWM < PWM_min) {
 		PWM = PWM_min;
 		//err_int = PWM*V_o/ki;
 	} else {
 		PWM = PWM_1;
 	}

 	saved_err_int = err_int;
 	previous_err = err;
 	old_PWM = PWM;

 	if(PWM < 0) PWM = 0;
 	return PWM;
 }


 void change_err_der(float new_err_der) {
 	previous_err = new_err_der;
 }

 void change_err_int(float new_err_int) {
 	saved_err_int = new_err_int;
 }